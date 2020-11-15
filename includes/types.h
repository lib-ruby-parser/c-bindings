#ifndef LIB_RUBY_PARSER_TYPES_H
#define LIB_RUBY_PARSER_TYPES_H

#include "gen.h"

struct Loc
{
    size_t begin;
    size_t end;
};

struct Token
{
    int token_type;
    char *token_value;
    struct Loc *loc;
};

struct Tokens
{
    size_t len;
    struct Token *list;
};

enum ErrorLevel
{
    WARNING,
    ERROR
};

struct DiagnosticMessage
{
    char dummy;
};

struct Diagnostic
{
    enum ErrorLevel level;
    struct DiagnosticMessage *message;
    struct Range range;
};

struct Diagnostics
{
    size_t len;
    struct Diagnostic *list;
};

struct Comment
{
    struct Range location;
};

struct Comments
{
    size_t len;
    struct Comment *list;
};

enum MagicCommentKind
{
    ENCODING,
    FROZEN_STRING_LITERAL,
    WARN_INDENT,
};

struct MagicComment
{
    enum MagicCommentKind kind;
    struct Range key_l;
    struct Range value_l;
};

struct MagicComments
{
    size_t len;
    struct MagicComment *list;
};

struct ParserResult
{
    struct Node *ast;
    struct Tokens *tokens;
    struct Diagnostics *diagnostics;
    struct Comments *comments;
    struct MagicComments *magic_comments;
};

#endif // LIB_RUBY_PARSER_TYPES_H
