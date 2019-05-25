#ifndef FILTER_H
#define FILTER_H

#include <client/client.h>
#include <client/context.h>

in3_filter_t* filter_new(in3_filter_type_t ft);
size_t        filter_add(in3_t* in3, in3_filter_type_t type, char* options);
bool          filter_remove(in3_t* in3, size_t id);
int           filter_get_changes(in3_ctx_t* ctx, size_t id, sb_t* result);
bool          filter_opt_valid(d_token_t* tx_params);

#endif //FILTER_H