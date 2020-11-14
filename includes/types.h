#ifndef LIB_RUBY_PARSER_TYPES_H
#define LIB_RUBY_PARSER_TYPES_H

#include "gen.h"

struct ParserResult
{
    char dummy;
};

struct Node
{
    char dummy;
};

struct NodeList
{
    size_t length;
    size_t capacity;
    struct Node *head;
};

struct Tokens
{
    char dummy;
};

struct Diagnostics
{
    char dummy;
};

struct Comments
{
    char dummy;
};

struct MagicComments
{
    char dummy;
};

#endif // LIB_RUBY_PARSER_TYPES_H
