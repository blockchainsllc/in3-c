#ifndef IN3_NODE_SELECT_DEF_CFG_H
#define IN3_NODE_SELECT_DEF_CFG_H

#define JSON_TO_BIN(x) x // marker for pre-build stage

#include "../../core/client/client.h"

#ifndef NO_BOOT_NODES_MAINNET
/*
#define BOOT_NODES_MAINNET JSON_TO_BIN("{"                                                                                          \
                                       " \"nodeRegistry\": {"                                                                       \
                                       "   \"contract\": \"0xac1b824795e1eb1f6e609fe0da9b9af8beaab60f\","                           \
                                       "   \"registryId\": \"0x23d5345c5c13180a8080bd5ddbe7cde64683755dcce6e734d95b7b573845facb\"," \
                                       "   \"nodeList\": [{"                                                                        \
                                       "    \"address\": \"0x45d45e6ff99e6c34a235d263965910298985fcfe\","                           \
                                       "    \"url\": \"https://in3-v2.slock.it/mainnet/nd-1\","                                     \
                                       "    \"props\": \"0xFFFF\""                                                                  \
                                       "   }, {"                                                                                    \
                                       "    \"address\": \"0x2e333ec090f1028df0a3c39a918063443be82b2b\","                           \
                                       "    \"url\": \"https://mainnet.incubed.net\","                                     \
                                       "    \"props\": \"0xFFFF\""                                                                  \
                                       "   }, {"                                                                                    \
                                       "    \"address\": \"0x510ee7f6f198e018e3529164da2473a96eeb3dc8\","                           \
                                       "    \"url\": \"https://0001.mainnet.in3.anyblock.tools\","                                     \
                                       "    \"props\": \"0xFFFF\""                                                                  \
                                       "   }, {"                                                                                    \
                                       "    \"address\": \"0xc513a534de5a9d3f413152c41b09bd8116237fc8\","                           \
                                       "    \"url\": \"https://in3-v2.slock.it/mainnet/nd-4\","                                     \
                                       "    \"props\": \"0xFFFF\""                                                                  \
                                       "   }, {"                                                                                    \
                                       "    \"address\": \"0xbcdf4e3e90cc7288b578329efd7bcc90655148d2\","                           \
                                       "    \"url\": \"https://in3-v2.slock.it/mainnet/nd-5\","                                     \
                                       "    \"props\": \"0xFFFF\""                                                                  \
                                       "   }]"                                                                                      \
                                       " }"                                                                                         \
                                       "}")
*/
const unsigned char BOOT_NODES_MAINNET_BIN[] = {
    0xd9, 0x61, 0x5f, 0x35, 0x63, 0xce, 0x12, 0x14, 0xac, 0x1b, 0x82, 0x47,
    0x95, 0xe1, 0xeb, 0x1f, 0x6e, 0x60, 0x9f, 0xe0, 0xda, 0x9b, 0x9a, 0xf8,
    0xbe, 0xaa, 0xb6, 0x0f, 0x6e, 0xb8, 0x1c, 0x20, 0x23, 0xd5, 0x34, 0x5c,
    0x5c, 0x13, 0x18, 0x0a, 0x80, 0x80, 0xbd, 0x5d, 0xdb, 0xe7, 0xcd, 0xe6,
    0x46, 0x83, 0x75, 0x5d, 0xcc, 0xe6, 0xe7, 0x34, 0xd9, 0x5b, 0x7b, 0x57,
    0x38, 0x45, 0xfa, 0xcb, 0x1a, 0xa2, 0x45, 0x63, 0xb2, 0xf6, 0x14, 0x45,
    0xd4, 0x5e, 0x6f, 0xf9, 0x9e, 0x6c, 0x34, 0xa2, 0x35, 0xd2, 0x63, 0x96,
    0x59, 0x10, 0x29, 0x89, 0x85, 0xfc, 0xfe, 0x79, 0x6b, 0x3c, 0x24, 0x68,
    0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f, 0x69, 0x6e, 0x33, 0x2d, 0x76,
    0x32, 0x2e, 0x73, 0x6c, 0x6f, 0x63, 0x6b, 0x2e, 0x69, 0x74, 0x2f, 0x6d,
    0x61, 0x69, 0x6e, 0x6e, 0x65, 0x74, 0x2f, 0x6e, 0x64, 0x2d, 0x31, 0x00,
    0x41, 0x6e, 0xbd, 0xff, 0xff, 0x63, 0xb2, 0xf6, 0x14, 0x2e, 0x33, 0x3e,
    0xc0, 0x90, 0xf1, 0x02, 0x8d, 0xf0, 0xa3, 0xc3, 0x9a, 0x91, 0x80, 0x63,
    0x44, 0x3b, 0xe8, 0x2b, 0x2b, 0x79, 0x6b, 0x3b, 0x68, 0x74, 0x74, 0x70,
    0x73, 0x3a, 0x2f, 0x2f, 0x6d, 0x61, 0x69, 0x6e, 0x6e, 0x65, 0x74, 0x2e,
    0x69, 0x6e, 0x63, 0x75, 0x62, 0x65, 0x64, 0x2e, 0x6e, 0x65, 0x74, 0x00,
    0x41, 0x6e, 0xbd, 0xff, 0xff, 0x63, 0xb2, 0xf6, 0x14, 0x51, 0x0e, 0xe7,
    0xf6, 0xf1, 0x98, 0xe0, 0x18, 0xe3, 0x52, 0x91, 0x64, 0xda, 0x24, 0x73,
    0xa9, 0x6e, 0xeb, 0x3d, 0xc8, 0x79, 0x6b, 0x3c, 0x27, 0x68, 0x74, 0x74,
    0x70, 0x73, 0x3a, 0x2f, 0x2f, 0x30, 0x30, 0x30, 0x31, 0x2e, 0x6d, 0x61,
    0x69, 0x6e, 0x6e, 0x65, 0x74, 0x2e, 0x69, 0x6e, 0x33, 0x2e, 0x61, 0x6e,
    0x79, 0x62, 0x6c, 0x6f, 0x63, 0x6b, 0x2e, 0x74, 0x6f, 0x6f, 0x6c, 0x73,
    0x00, 0x41, 0x6e, 0xbd, 0xff, 0xff, 0x63, 0xb2, 0xf6, 0x14, 0xc5, 0x13,
    0xa5, 0x34, 0xde, 0x5a, 0x9d, 0x3f, 0x41, 0x31, 0x52, 0xc4, 0x1b, 0x09,
    0xbd, 0x81, 0x16, 0x23, 0x7f, 0xc8, 0x79, 0x6b, 0x3c, 0x24, 0x68, 0x74,
    0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f, 0x69, 0x6e, 0x33, 0x2d, 0x76, 0x32,
    0x2e, 0x73, 0x6c, 0x6f, 0x63, 0x6b, 0x2e, 0x69, 0x74, 0x2f, 0x6d, 0x61,
    0x69, 0x6e, 0x6e, 0x65, 0x74, 0x2f, 0x6e, 0x64, 0x2d, 0x34, 0x00, 0x41,
    0x6e, 0xbd, 0xff, 0xff, 0x63, 0xb2, 0xf6, 0x14, 0xbc, 0xdf, 0x4e, 0x3e,
    0x90, 0xcc, 0x72, 0x88, 0xb5, 0x78, 0x32, 0x9e, 0xfd, 0x7b, 0xcc, 0x90,
    0x65, 0x51, 0x48, 0xd2, 0x79, 0x6b, 0x3c, 0x24, 0x68, 0x74, 0x74, 0x70,
    0x73, 0x3a, 0x2f, 0x2f, 0x69, 0x6e, 0x33, 0x2d, 0x76, 0x32, 0x2e, 0x73,
    0x6c, 0x6f, 0x63, 0x6b, 0x2e, 0x69, 0x74, 0x2f, 0x6d, 0x61, 0x69, 0x6e,
    0x6e, 0x65, 0x74, 0x2f, 0x6e, 0x64, 0x2d, 0x35, 0x00, 0x41, 0x6e, 0xbd,
    0xff, 0xff};
const unsigned int BOOT_NODES_MAINNET_BIN_LEN = 410;

#endif // NO_BOOT_NODES_MAINNET

#ifdef IN3_STAGING

#ifndef NO_BOOT_NODES_GOERLI
/*
#define BOOT_NODES_GOERLI JSON_TO_BIN("{"                                                                                          \
                                      " \"nodeRegistry\": {"                                                                       \
                                      "   \"contract\": \"0x814fb2203f9848192307092337340dcf791a3fed\","                           \
                                      "   \"registryId\": \"0x0f687341e0823fa5288dc9edd8a00950b35cc7e481ad7eaccaf61e4e04a61e08\"," \
                                      "   \"nodeList\": [{"                                                                        \
                                      "    \"address\": \"0x784bfa9eb182c3a02dbeb5285e3dba92d717e07a\","                           \
                                      "    \"url\": \"https://in3.stage.slock.it/goerli/nd-1\","                                   \
                                      "    \"props\": \"0xFFFF\""                                                                  \
                                      "   }, {"                                                                                    \
                                      "    \"address\": \"0x17cdf9ec6dcae05c5686265638647e54b14b41a2\","                           \
                                      "    \"url\": \"https://in3.stage.slock.it/goerli/nd-2\","                                   \
                                      "    \"props\": \"0xFFFF\""                                                                  \
                                      "   }]"                                                                                      \
                                      " }"                                                                                         \
                                      "}")
*/
const unsigned char BOOT_NODES_GOERLI_BIN[] = {
    0xcd, 0x61, 0x5f, 0x35, 0x63, 0xce, 0x12, 0x14, 0x81, 0x4f, 0xb2, 0x20,
    0x3f, 0x98, 0x48, 0x19, 0x23, 0x07, 0x09, 0x23, 0x37, 0x34, 0x0d, 0xcf,
    0x79, 0x1a, 0x3f, 0xed, 0x6e, 0xb8, 0x1c, 0x20, 0x0f, 0x68, 0x73, 0x41,
    0xe0, 0x82, 0x3f, 0xa5, 0x28, 0x8d, 0xc9, 0xed, 0xd8, 0xa0, 0x09, 0x50,
    0xb3, 0x5c, 0xc7, 0xe4, 0x81, 0xad, 0x7e, 0xac, 0xca, 0xf6, 0x1e, 0x4e,
    0x04, 0xa6, 0x1e, 0x08, 0x1a, 0xa2, 0x42, 0x63, 0xb2, 0xf6, 0x14, 0x78,
    0x4b, 0xfa, 0x9e, 0xb1, 0x82, 0xc3, 0xa0, 0x2d, 0xbe, 0xb5, 0x28, 0x5e,
    0x3d, 0xba, 0x92, 0xd7, 0x17, 0xe0, 0x7a, 0x79, 0x6b, 0x3c, 0x26, 0x68,
    0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f, 0x69, 0x6e, 0x33, 0x2e, 0x73,
    0x74, 0x61, 0x67, 0x65, 0x2e, 0x73, 0x6c, 0x6f, 0x63, 0x6b, 0x2e, 0x69,
    0x74, 0x2f, 0x67, 0x6f, 0x65, 0x72, 0x6c, 0x69, 0x2f, 0x6e, 0x64, 0x2d,
    0x31, 0x00, 0x41, 0x6e, 0xbd, 0xff, 0xff, 0x63, 0xb2, 0xf6, 0x14, 0x17,
    0xcd, 0xf9, 0xec, 0x6d, 0xca, 0xe0, 0x5c, 0x56, 0x86, 0x26, 0x56, 0x38,
    0x64, 0x7e, 0x54, 0xb1, 0x4b, 0x41, 0xa2, 0x79, 0x6b, 0x3c, 0x26, 0x68,
    0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f, 0x69, 0x6e, 0x33, 0x2e, 0x73,
    0x74, 0x61, 0x67, 0x65, 0x2e, 0x73, 0x6c, 0x6f, 0x63, 0x6b, 0x2e, 0x69,
    0x74, 0x2f, 0x67, 0x6f, 0x65, 0x72, 0x6c, 0x69, 0x2f, 0x6e, 0x64, 0x2d,
    0x32, 0x00, 0x41, 0x6e, 0xbd, 0xff, 0xff};
const unsigned int BOOT_NODES_GOERLI_BIN_LEN = 211;

#endif // NO_BOOT_NODES_GOERLI

#else /* IN3_STAGING */

#ifndef NO_BOOT_NODES_GOERLI
/*
#define BOOT_NODES_GOERLI JSON_TO_BIN("{"                                                                                          \
                                      " \"nodeRegistry\": {"                                                                       \
                                      "   \"contract\": \"0x5f51e413581dd76759e9eed51e63d14c8d1379c8\","                           \
                                      "   \"registryId\": \"0x67c02e5e272f9d6b4a33716614061dd298283f86351079ef903bf0d4410a44ea\"," \
                                      "   \"nodeList\": [{"                                                                        \
                                      "    \"address\": \"0x45d45e6ff99e6c34a235d263965910298985fcfe\","                           \
                                      "    \"url\": \"https://in3-v2.slock.it/goerli/nd-1\","                                      \
                                      "    \"props\": \"0xFFFF\""                                                                  \
                                      "   }, {"                                                                                    \
                                      "    \"address\": \"0x1fe2e9bf29aa1938859af64c413361227d04059a\","                           \
                                      "    \"url\": \"https://in3-v2.slock.it/goerli/nd-2\","                                      \
                                      "    \"props\": \"0xFFFF\""                                                                  \
                                      "   }, {"                                                                                    \
                                      "    \"address\": \"0x7c1f2b5c1e2fe8300f3e0865818faf43ad22d99d\","                           \
                                      "    \"url\": \"https://in3.jentzschfamily.de\","                                      \
                                      "    \"props\": \"0xFFFF\""                                                                  \
                                      "   }]"                                                                                      \
                                      " }"                                                                                         \
                                      "}")
*/
const unsigned char BOOT_NODES_GOERLI_BIN[] = {
    0xd1, 0x61, 0x5f, 0x35, 0x63, 0xce, 0x12, 0x14, 0x5f, 0x51, 0xe4, 0x13,
    0x58, 0x1d, 0xd7, 0x67, 0x59, 0xe9, 0xee, 0xd5, 0x1e, 0x63, 0xd1, 0x4c,
    0x8d, 0x13, 0x79, 0xc8, 0x6e, 0xb8, 0x1c, 0x20, 0x67, 0xc0, 0x2e, 0x5e,
    0x27, 0x2f, 0x9d, 0x6b, 0x4a, 0x33, 0x71, 0x66, 0x14, 0x06, 0x1d, 0xd2,
    0x98, 0x28, 0x3f, 0x86, 0x35, 0x10, 0x79, 0xef, 0x90, 0x3b, 0xf0, 0xd4,
    0x41, 0x0a, 0x44, 0xea, 0x1a, 0xa2, 0x43, 0x63, 0xb2, 0xf6, 0x14, 0x45,
    0xd4, 0x5e, 0x6f, 0xf9, 0x9e, 0x6c, 0x34, 0xa2, 0x35, 0xd2, 0x63, 0x96,
    0x59, 0x10, 0x29, 0x89, 0x85, 0xfc, 0xfe, 0x79, 0x6b, 0x3c, 0x23, 0x68,
    0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f, 0x69, 0x6e, 0x33, 0x2d, 0x76,
    0x32, 0x2e, 0x73, 0x6c, 0x6f, 0x63, 0x6b, 0x2e, 0x69, 0x74, 0x2f, 0x67,
    0x6f, 0x65, 0x72, 0x6c, 0x69, 0x2f, 0x6e, 0x64, 0x2d, 0x31, 0x00, 0x41,
    0x6e, 0xbd, 0xff, 0xff, 0x63, 0xb2, 0xf6, 0x14, 0x1f, 0xe2, 0xe9, 0xbf,
    0x29, 0xaa, 0x19, 0x38, 0x85, 0x9a, 0xf6, 0x4c, 0x41, 0x33, 0x61, 0x22,
    0x7d, 0x04, 0x05, 0x9a, 0x79, 0x6b, 0x3c, 0x23, 0x68, 0x74, 0x74, 0x70,
    0x73, 0x3a, 0x2f, 0x2f, 0x69, 0x6e, 0x33, 0x2d, 0x76, 0x32, 0x2e, 0x73,
    0x6c, 0x6f, 0x63, 0x6b, 0x2e, 0x69, 0x74, 0x2f, 0x67, 0x6f, 0x65, 0x72,
    0x6c, 0x69, 0x2f, 0x6e, 0x64, 0x2d, 0x32, 0x00, 0x41, 0x6e, 0xbd, 0xff,
    0xff, 0x63, 0xb2, 0xf6, 0x14, 0x7c, 0x1f, 0x2b, 0x5c, 0x1e, 0x2f, 0xe8,
    0x30, 0x0f, 0x3e, 0x08, 0x65, 0x81, 0x8f, 0xaf, 0x43, 0xad, 0x22, 0xd9,
    0x9d, 0x79, 0x6b, 0x3c, 0x1d, 0x68, 0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f,
    0x2f, 0x69, 0x6e, 0x33, 0x2e, 0x6a, 0x65, 0x6e, 0x74, 0x7a, 0x73, 0x63,
    0x68, 0x66, 0x61, 0x6d, 0x69, 0x6c, 0x79, 0x2e, 0x64, 0x65, 0x00, 0x41,
    0x6e, 0xbd, 0xff, 0xff};
const unsigned int BOOT_NODES_GOERLI_BIN_LEN = 268;

#endif // NO_BOOT_NODES_GOERLI

#ifndef NO_BOOT_NODES_IPFS

/*
#define BOOT_NODES_IPFS JSON_TO_BIN("{"                                                                                          \
                                    " \"nodeRegistry\": {"                                                                       \
                                    "   \"contract\": \"0xa93b57289070550c82edb1106e12bb37138948b8\","                           \
                                    "   \"registryId\": \"0xf0162ec6d785ee990e36bad865251f45af0916cf136169540c02b0dd9cb69196\"," \
                                    "   \"nodeList\": [{"                                                                        \
                                    "    \"address\": \"0x45d45e6ff99e6c34a235d263965910298985fcfe\","                           \
                                    "    \"url\": \"https://in3-v2.slock.it/ipfs/nd-1\","                                        \
                                    "    \"props\": \"0xFFFF\""                                                                  \
                                    "   }, {"                                                                                    \
                                    "    \"address\": \"0x1fe2e9bf29aa1938859af64c413361227d04059a\","                           \
                                    "    \"url\": \"https://in3-v2.slock.it/ipfs/nd-2\","                                        \
                                    "    \"props\": \"0xFFFF\""                                                                  \
                                    "   }]"                                                                                      \
                                    " }"                                                                                         \
                                    "}")
*/
const unsigned char BOOT_NODES_IPFS_BIN[] = {
    0xcd, 0x61, 0x5f, 0x35, 0x63, 0xce, 0x12, 0x14, 0xa9, 0x3b, 0x57, 0x28,
    0x90, 0x70, 0x55, 0x0c, 0x82, 0xed, 0xb1, 0x10, 0x6e, 0x12, 0xbb, 0x37,
    0x13, 0x89, 0x48, 0xb8, 0x6e, 0xb8, 0x1c, 0x20, 0xf0, 0x16, 0x2e, 0xc6,
    0xd7, 0x85, 0xee, 0x99, 0x0e, 0x36, 0xba, 0xd8, 0x65, 0x25, 0x1f, 0x45,
    0xaf, 0x09, 0x16, 0xcf, 0x13, 0x61, 0x69, 0x54, 0x0c, 0x02, 0xb0, 0xdd,
    0x9c, 0xb6, 0x91, 0x96, 0x1a, 0xa2, 0x42, 0x63, 0xb2, 0xf6, 0x14, 0x45,
    0xd4, 0x5e, 0x6f, 0xf9, 0x9e, 0x6c, 0x34, 0xa2, 0x35, 0xd2, 0x63, 0x96,
    0x59, 0x10, 0x29, 0x89, 0x85, 0xfc, 0xfe, 0x79, 0x6b, 0x3c, 0x21, 0x68,
    0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f, 0x69, 0x6e, 0x33, 0x2d, 0x76,
    0x32, 0x2e, 0x73, 0x6c, 0x6f, 0x63, 0x6b, 0x2e, 0x69, 0x74, 0x2f, 0x69,
    0x70, 0x66, 0x73, 0x2f, 0x6e, 0x64, 0x2d, 0x31, 0x00, 0x41, 0x6e, 0xbd,
    0xff, 0xff, 0x63, 0xb2, 0xf6, 0x14, 0x1f, 0xe2, 0xe9, 0xbf, 0x29, 0xaa,
    0x19, 0x38, 0x85, 0x9a, 0xf6, 0x4c, 0x41, 0x33, 0x61, 0x22, 0x7d, 0x04,
    0x05, 0x9a, 0x79, 0x6b, 0x3c, 0x21, 0x68, 0x74, 0x74, 0x70, 0x73, 0x3a,
    0x2f, 0x2f, 0x69, 0x6e, 0x33, 0x2d, 0x76, 0x32, 0x2e, 0x73, 0x6c, 0x6f,
    0x63, 0x6b, 0x2e, 0x69, 0x74, 0x2f, 0x69, 0x70, 0x66, 0x73, 0x2f, 0x6e,
    0x64, 0x2d, 0x32, 0x00, 0x41, 0x6e, 0xbd, 0xff, 0xff};
const unsigned int BOOT_NODES_IPFS_BIN_LEN = 201;

#endif // NO_BOOT_NODES_IPFS

#ifndef NO_BOOT_NODES_BTC
/*
#define BOOT_NODES_BTC JSON_TO_BIN("{"                                                                                          \
                                   " \"nodeRegistry\": {"                                                                       \
                                   "   \"contract\": \"0xc2c05fbfe76ee7748ae5f5b61b57a46cc4061c32\","                           \
                                   "   \"registryId\": \"0x53786c93e54c21d9852d093c394eee9df8d714d8f2534cdf92f9c9998c528d19\"," \
                                   "   \"nodeList\": [{"                                                                        \
                                   "    \"address\": \"0x45d45e6ff99e6c34a235d263965910298985fcfe\","                           \
                                   "    \"url\": \"https://in3-v2.slock.it/btc/nd-1\","                                         \
                                   "    \"props\": \"0xFFFF\""                                                                  \
                                   "   }, {"                                                                                    \
                                   "    \"address\": \"0x1fe2e9bf29aa1938859af64c413361227d04059a\","                           \
                                   "    \"url\": \"https://in3-v2.slock.it/btc/nd-2\","                                         \
                                   "    \"props\": \"0xFFFF\""                                                                  \
                                   "   }]"                                                                                      \
                                   " }"                                                                                         \
                                   "}")
*/
const unsigned char BOOT_NODES_BTC_BIN[] = {
    0xcd, 0x61, 0x5f, 0x35, 0x63, 0xce, 0x12, 0x14, 0xc2, 0xc0, 0x5f, 0xbf,
    0xe7, 0x6e, 0xe7, 0x74, 0x8a, 0xe5, 0xf5, 0xb6, 0x1b, 0x57, 0xa4, 0x6c,
    0xc4, 0x06, 0x1c, 0x32, 0x6e, 0xb8, 0x1c, 0x20, 0x53, 0x78, 0x6c, 0x93,
    0xe5, 0x4c, 0x21, 0xd9, 0x85, 0x2d, 0x09, 0x3c, 0x39, 0x4e, 0xee, 0x9d,
    0xf8, 0xd7, 0x14, 0xd8, 0xf2, 0x53, 0x4c, 0xdf, 0x92, 0xf9, 0xc9, 0x99,
    0x8c, 0x52, 0x8d, 0x19, 0x1a, 0xa2, 0x42, 0x63, 0xb2, 0xf6, 0x14, 0x45,
    0xd4, 0x5e, 0x6f, 0xf9, 0x9e, 0x6c, 0x34, 0xa2, 0x35, 0xd2, 0x63, 0x96,
    0x59, 0x10, 0x29, 0x89, 0x85, 0xfc, 0xfe, 0x79, 0x6b, 0x3c, 0x20, 0x68,
    0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f, 0x69, 0x6e, 0x33, 0x2d, 0x76,
    0x32, 0x2e, 0x73, 0x6c, 0x6f, 0x63, 0x6b, 0x2e, 0x69, 0x74, 0x2f, 0x62,
    0x74, 0x63, 0x2f, 0x6e, 0x64, 0x2d, 0x31, 0x00, 0x41, 0x6e, 0xbd, 0xff,
    0xff, 0x63, 0xb2, 0xf6, 0x14, 0x1f, 0xe2, 0xe9, 0xbf, 0x29, 0xaa, 0x19,
    0x38, 0x85, 0x9a, 0xf6, 0x4c, 0x41, 0x33, 0x61, 0x22, 0x7d, 0x04, 0x05,
    0x9a, 0x79, 0x6b, 0x3c, 0x20, 0x68, 0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f,
    0x2f, 0x69, 0x6e, 0x33, 0x2d, 0x76, 0x32, 0x2e, 0x73, 0x6c, 0x6f, 0x63,
    0x6b, 0x2e, 0x69, 0x74, 0x2f, 0x62, 0x74, 0x63, 0x2f, 0x6e, 0x64, 0x2d,
    0x32, 0x00, 0x41, 0x6e, 0xbd, 0xff, 0xff};
const unsigned int BOOT_NODES_BTC_BIN_LEN = 199;

#endif // NO_BOOT_NODES_BTC

#ifndef NO_BOOT_NODES_EWC
/*
#define BOOT_NODES_EWC JSON_TO_BIN("{"                                                                                          \
                                   " \"nodeRegistry\": {"                                                                       \
                                   "   \"contract\": \"0x039562872008f7a76674a6e7842804f0ad37cb13\","                           \
                                   "   \"registryId\": \"0x313454c05fc6e5336a3315ed2233da6b831d4cb826d836c3d603f2e2a9f1ed75\"," \
                                   "   \"nodeList\": [{"                                                                        \
                                   "    \"address\": \"0x45d45e6ff99e6c34a235d263965910298985fcfe\","                           \
                                   "    \"url\": \"https://in3-v2.slock.it/ewc/nd-1\","                                         \
                                   "    \"props\": \"0xFFFF\""                                                                  \
                                   "   }, {"                                                                                    \
                                   "    \"address\": \"0x1fe2e9bf29aa1938859af64c413361227d04059a\","                           \
                                   "    \"url\": \"https://in3-v2.slock.it/ewc/nd-2\","                                         \
                                   "    \"props\": \"0xFFFF\""                                                                  \
                                   "   }]"                                                                                      \
                                   " }"                                                                                         \
                                   "}")
*/
const unsigned char BOOT_NODES_EWC_BIN[] = {
    0xcd, 0x61, 0x5f, 0x35, 0x63, 0xce, 0x12, 0x14, 0x03, 0x95, 0x62, 0x87,
    0x20, 0x08, 0xf7, 0xa7, 0x66, 0x74, 0xa6, 0xe7, 0x84, 0x28, 0x04, 0xf0,
    0xad, 0x37, 0xcb, 0x13, 0x6e, 0xb8, 0x1c, 0x20, 0x31, 0x34, 0x54, 0xc0,
    0x5f, 0xc6, 0xe5, 0x33, 0x6a, 0x33, 0x15, 0xed, 0x22, 0x33, 0xda, 0x6b,
    0x83, 0x1d, 0x4c, 0xb8, 0x26, 0xd8, 0x36, 0xc3, 0xd6, 0x03, 0xf2, 0xe2,
    0xa9, 0xf1, 0xed, 0x75, 0x1a, 0xa2, 0x42, 0x63, 0xb2, 0xf6, 0x14, 0x45,
    0xd4, 0x5e, 0x6f, 0xf9, 0x9e, 0x6c, 0x34, 0xa2, 0x35, 0xd2, 0x63, 0x96,
    0x59, 0x10, 0x29, 0x89, 0x85, 0xfc, 0xfe, 0x79, 0x6b, 0x3c, 0x20, 0x68,
    0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f, 0x69, 0x6e, 0x33, 0x2d, 0x76,
    0x32, 0x2e, 0x73, 0x6c, 0x6f, 0x63, 0x6b, 0x2e, 0x69, 0x74, 0x2f, 0x65,
    0x77, 0x63, 0x2f, 0x6e, 0x64, 0x2d, 0x31, 0x00, 0x41, 0x6e, 0xbd, 0xff,
    0xff, 0x63, 0xb2, 0xf6, 0x14, 0x1f, 0xe2, 0xe9, 0xbf, 0x29, 0xaa, 0x19,
    0x38, 0x85, 0x9a, 0xf6, 0x4c, 0x41, 0x33, 0x61, 0x22, 0x7d, 0x04, 0x05,
    0x9a, 0x79, 0x6b, 0x3c, 0x20, 0x68, 0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f,
    0x2f, 0x69, 0x6e, 0x33, 0x2d, 0x76, 0x32, 0x2e, 0x73, 0x6c, 0x6f, 0x63,
    0x6b, 0x2e, 0x69, 0x74, 0x2f, 0x65, 0x77, 0x63, 0x2f, 0x6e, 0x64, 0x2d,
    0x32, 0x00, 0x41, 0x6e, 0xbd, 0xff, 0xff};
const unsigned int BOOT_NODES_EWC_BIN_LEN = 199;

#endif // NO_BOOT_NODES_EWC

#ifndef NO_BOOT_NODES_LOCAL
/*
#define BOOT_NODES_LOCAL JSON_TO_BIN("{"                                                                \
                                     " \"nodeRegistry\": {"                                             \
                                     "   \"contract\": \"0xf0fb87f4757c77ea3416afe87f36acaa0496c7e9\"," \
                                     "   \"nodeList\": [{"                                              \
                                     "    \"address\": \"0x784bfa9eb182c3a02dbeb5285e3dba92d717e07a\"," \
                                     "    \"url\": \"http://localhost:8545\","                          \
                                     "    \"props\": \"0xFFFF\""                                        \
                                     "   }]"                                                            \
                                     " }"                                                               \
                                     "}")
*/
const unsigned char BOOT_NODES_LOCAL_BIN[] = {
    0xc8, 0x61, 0x5f, 0x35, 0x62, 0xce, 0x12, 0x14, 0xf0, 0xfb, 0x87, 0xf4,
    0x75, 0x7c, 0x77, 0xea, 0x34, 0x16, 0xaf, 0xe8, 0x7f, 0x36, 0xac, 0xaa,
    0x04, 0x96, 0xc7, 0xe9, 0x1a, 0xa2, 0x41, 0x63, 0xb2, 0xf6, 0x14, 0x78,
    0x4b, 0xfa, 0x9e, 0xb1, 0x82, 0xc3, 0xa0, 0x2d, 0xbe, 0xb5, 0x28, 0x5e,
    0x3d, 0xba, 0x92, 0xd7, 0x17, 0xe0, 0x7a, 0x79, 0x6b, 0x35, 0x68, 0x74,
    0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x68, 0x6f,
    0x73, 0x74, 0x3a, 0x38, 0x35, 0x34, 0x35, 0x00, 0x41, 0x6e, 0xbd, 0xff,
    0xff};
const unsigned int BOOT_NODES_LOCAL_BIN_LEN = 85;

#endif // NO_BOOT_NODES_LOCAL

#endif /* IN3_STAGING */

static inline bytes_t nodeselect_def_cfg_data(chain_id_t chain_id) {
#ifndef NO_BOOT_NODES_MAINNET
  if (chain_id == CHAIN_ID_MAINNET)
    return bytes((uint8_t*) BOOT_NODES_MAINNET_BIN, BOOT_NODES_MAINNET_BIN_LEN);
#endif // NO_BOOT_NODES_MAINNET

#ifndef NO_BOOT_NODES_GOERLI
  if (chain_id == CHAIN_ID_GOERLI)
    return bytes((uint8_t*) BOOT_NODES_GOERLI_BIN, BOOT_NODES_GOERLI_BIN_LEN);
#endif // NO_BOOT_NODES_GOERLI

#ifndef NO_BOOT_NODES_IPFS
  if (chain_id == CHAIN_ID_IPFS)
    return bytes((uint8_t*) BOOT_NODES_IPFS_BIN, BOOT_NODES_IPFS_BIN_LEN);
#endif // NO_BOOT_NODES_IPFS

#ifndef NO_BOOT_NODES_BTC
  if (chain_id == CHAIN_ID_BTC)
    return bytes((uint8_t*) BOOT_NODES_BTC_BIN, BOOT_NODES_BTC_BIN_LEN);
#endif // NO_BOOT_NODES_BTC

#ifndef NO_BOOT_NODES_EWC
  if (chain_id == CHAIN_ID_EWC)
    return bytes((uint8_t*) BOOT_NODES_EWC_BIN, BOOT_NODES_EWC_BIN_LEN);
#endif // NO_BOOT_NODES_EWC

#ifndef NO_BOOT_NODES_LOCAL
  if (chain_id == CHAIN_ID_LOCAL)
    return bytes((uint8_t*) BOOT_NODES_LOCAL_BIN, BOOT_NODES_LOCAL_BIN_LEN);
#endif // NO_BOOT_NODES_LOCAL

  return bytes(NULL, 0);
}

static inline json_ctx_t* nodeselect_def_cfg(chain_id_t chain_id) {
  bytes_t bincfg = nodeselect_def_cfg_data(chain_id);
  return bincfg.data ? parse_binary(&bincfg) : NULL;
}

#endif //IN3_NODE_SELECT_DEF_CFG_H
