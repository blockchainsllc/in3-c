extern crate bindgen;

use std::env;
use std::fs::copy;
use std::path::PathBuf;

include!("common.rs");

const IN3_DIR: &'static str = "in3";
const BINDINGS_FILE: &'static str = "in3.rs";

fn find_in3_header(header_search_paths: &Vec<PathBuf>, name: &str) -> Option<PathBuf> {
    for search_path in header_search_paths.iter() {
        let potential_file = search_path.join(name);
        if potential_file.is_file() {
            return Some(potential_file);
        }
    }
    None
}

/// Gets environment variable value. Panics if variable is not set.
fn env_var(var: &str) -> String {
    env::var(var).expect(&format!("Environment variable {} is not set", var))
}

fn write_bindgen_bindings(
    header_search_paths: &Vec<PathBuf>,
    update_pregenerated_bindings: bool,
    pregenerated_bindgen_header: PathBuf,
    out_bindings_path: PathBuf,
) {
    let builder = bindgen::Builder::default()
        .rust_target(bindgen::RustTarget::Stable_1_28)
        .size_t_is_usize(true)
        .use_core()
        .ctypes_prefix("libc")
        .header(
            find_in3_header(header_search_paths, "in3.rs.h")
                .expect("Could not find header")
                .to_str()
                .unwrap(),
        )
        .disable_name_namespacing()
        .prepend_enum_name(false)
        .generate_comments(true)
        .impl_debug(true)
        .constified_enum_module("in3_ret_t")
        .rustified_enum(".*");

    let bindings = builder.generate().expect("Unable to generate bindings");
    bindings
        .write_to_file(&out_bindings_path)
        .expect("Unable to write bindings");

    if update_pregenerated_bindings {
        copy(out_bindings_path, pregenerated_bindgen_header)
            .expect("Unable to update in3 bindings");
    }
}

fn main() {
    let mut header_search_paths: Vec<PathBuf> = Vec::new();
    header_search_paths.push([IN3_DIR, "include"].iter().collect());

    println!("cargo:rustc-link-lib=static=in3_{}", env_var("TARGET"));

    // fixme: find a way to get workspace dir through an env var so we can point to native libs
    // until then workspace cargo commands (cargo build/run/etc.) will find libin3 in in3-sys/native
    // and others (cargo publish) that run from inside rust/in3-sys will find libin3 in native/
    println!("cargo:rustc-link-search=native=in3-sys/native");
    println!("cargo:rustc-link-search=native=native");

    let pregenerated_bindgen_header: PathBuf = [
        env_var("CARGO_MANIFEST_DIR"),
        "pre_generated".into(),
        BINDINGS_FILE.into(),
    ]
        .iter()
        .collect();

    let out_bindings_path = PathBuf::from(env_var("OUT_DIR")).join(BINDINGS_FILE);

    write_bindgen_bindings(
        &header_search_paths,
        env::var("UPDATE_IN3_BINDINGS").is_ok(),
        pregenerated_bindgen_header,
        out_bindings_path,
    );
}
