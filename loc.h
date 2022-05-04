#ifndef LIB_RUBY_PARSER_LOC_H
#define LIB_RUBY_PARSER_LOC_H

#include <stddef.h>
#include <stdint.h>
#include "decoded_input.h"

/// @defgroup loc Loc
/// @brief A set of structs and functions to work with source locations
/// @{
/// @}

/// `Loc` struct from `lib-ruby-parser`
/// @ingroup loc
typedef struct
{
    /// Begin of the location
    size_t begin;
    /// End of the location
    size_t end;
} LIB_RUBY_PARSER_Loc;

/// Returns source code of the given location.
/// Equivalent of `lib_ruby_parser::Loc::source`
/// @ingroup loc
char *LIB_RUBY_PARSER_loc_source(const LIB_RUBY_PARSER_Loc *loc, const LIB_RUBY_PARSER_DecodedInput *input);

/// Equivalent of `Option<Loc>`
/// @ingroup loc
typedef struct
{
    enum
    {
        LIB_RUBY_PARSER_NONE_LOC = 0,
        LIB_RUBY_PARSER_SOME_LOC = 1,
    } tag;

    union
    {
        LIB_RUBY_PARSER_Loc loc;
        uint8_t none;
    } as;
} LIB_RUBY_PARSER_MaybeLoc;

#endif // LIB_RUBY_PARSER_LOC_H
