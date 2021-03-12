#include <stddef.h>
#include "custom_decoder.h"

DecoderOutput decode_ok(char *bytes, uint32_t len)
{
    return (DecoderOutput){
        .status = DECODING_STATUS_OK,
        .value = {
            .success = {
                .bytes = bytes,
                .len = len}}};
}

DecoderOutput decode_err(char *error_message)
{
    return (DecoderOutput){
        .status = DECODING_STATUS_ERROR,
        .value = {
            .error = {
                .error_message = error_message}}};
}
