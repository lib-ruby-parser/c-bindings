#ifndef LIB_RUBY_PARSER_TOKEN_REWRITER_h
#define LIB_RUBY_PARSER_TOKEN_REWRITER_h

enum RewriteAction
{
    REWRITE_ACTION_DROP,
    REWRITE_ACTION_KEEP,
};

enum LexStateActionKind
{
    LEX_STATE_ACTION_SET,
    LEX_STATE_ACTION_KEEP,
};

union LexStateActionValue
{
    struct
    {
        int new_state;
    } set;

    struct
    {

    } keep;
};

struct LexStateAction
{
    enum LexStateActionKind kind;
    union LexStateActionValue value;
};

#endif // LIB_RUBY_PARSER_TOKEN_REWRITER_h
