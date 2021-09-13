#ifndef LIB_RUBY_PARSER_C_BINDINGS_API_H
#define LIB_RUBY_PARSER_C_BINDINGS_API_H

#include "structs.h"

LIB_RUBY_PARSER_ParserResult lib_ruby_parser__parse(
    LIB_RUBY_PARSER_ParserOptions options,
    LIB_RUBY_PARSER_ByteList input);

LIB_RUBY_PARSER_StringPtr lib_ruby_parser__token_name(
    const LIB_RUBY_PARSER_Token *token);

LIB_RUBY_PARSER_StringPtr lib_ruby_parser__render_diagnostic_message(
    const LIB_RUBY_PARSER_DiagnosticMessage *message);

#endif // LIB_RUBY_PARSER_C_BINDINGS_API_H
