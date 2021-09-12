#include "api.h"
#include "blobs.h"

LIB_RUBY_PARSER_ParserResult_BLOB lib_ruby_parser__internal__parse(
    LIB_RUBY_PARSER_ParserOptions_BLOB options,
    LIB_RUBY_PARSER_ByteList_BLOB input);
LIB_RUBY_PARSER_StringPtr_BLOB lib_ruby_parser__internal__token_name(
    const LIB_RUBY_PARSER_Token_BLOB *token);
LIB_RUBY_PARSER_StringPtr_BLOB lib_ruby_parser__internal__render_diagnostic_message(
    const LIB_RUBY_PARSER_DiagnosticMessage_BLOB *message);

LIB_RUBY_PARSER_ParserResult lib_ruby_parser__parse(LIB_RUBY_PARSER_ParserOptions options, LIB_RUBY_PARSER_ByteList input)
{
    return UNPACK_ParserResult(
        lib_ruby_parser__internal__parse(
            PACK_ParserOptions(options),
            PACK_ByteList(input)));
}

LIB_RUBY_PARSER_StringPtr lib_ruby_parser__token_name(const LIB_RUBY_PARSER_Token *token)
{
    return UNPACK_StringPtr(
        lib_ruby_parser__internal__token_name(
            (const LIB_RUBY_PARSER_Token_BLOB *)token));
}

LIB_RUBY_PARSER_StringPtr lib_ruby_parser__render_diagnostic_message(
    const LIB_RUBY_PARSER_DiagnosticMessage *message)
{
    return UNPACK_StringPtr(
        lib_ruby_parser__internal__render_diagnostic_message(
            (const LIB_RUBY_PARSER_DiagnosticMessage_BLOB *)message));
}
