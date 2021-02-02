#include <stddef.h>
#include "custom_decoder.h"

struct DecoderOutput decode_ok(char *bytes, uint32_t len)
{
    return (struct DecoderOutput){
        .status = DECODING_STATUS_OK,
        .value = {
            .success = {
                .bytes = bytes,
                .len = len}}};
}

struct DecoderOutput decode_err(char *error_message)
{
    return (struct DecoderOutput){
        .status = DECODING_STATUS_ERROR,
        .value = {
            .error = {
                .error_message = error_message}}};
}
