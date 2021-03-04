#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_MESSAGE_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_MESSAGE_H

#include <stdint.h>

enum DiagnosticMessageType {
    FRACTION_AFTER_NUMERIC,
    NO_DIGITS_AFTER_DOT,
    UNKNOWN_TYPE_OF_PERCENT_STRING,
    NUMERIC_LITERAL_WITHOUT_DIGITS,
    UNTERMINATED_LIST,
    UNTERMINATED_REGEXP,
    UNTERMINATED_STRING,
    UNTERMINATED_QUOTED_STRING,
    INVALID_UNICODE_ESCAPE,
    TOO_LARGE_UNICODE_CODEPOINT,
    INVALID_UNICODE_CODEPOINT,
    MULTIPLE_CODEPOINT_AT_SINGLE_CHAR,
    INVALID_ESCAPE_CHARACTER,
    INVALID_HEX_ESCAPE,
    UNTERMINATED_HEREDOC,
    UNTERMINATED_HEREDOC_ID,
    SLASH_R_AT_MIDDLE_OF_LINE,
    D_STAR_INTERPRETED_AS_ARG_PREFIX,
    STAR_INTERPRETED_AS_ARG_PREFIX,
    AMPERSAND_INTERPRETED_AS_ARG_PREFIX,
    TRIPLE_DOT_AT_EOL,
    PARENTHESES_ITERPRETED_AS_ARGLIST,
    AMBIGUOUS_FIRST_ARGUMENT,
    AMBIGUOUS_OPERATOR,
    INVALID_CHARACTER_SYNTAX,
    INVALID_OCTAL_DIGIT,
    TRAILING_CHAR_IN_NUMBER,
    EMBEDDED_DOCUMENT_MEETS_EOF,
    INVALID_CHAR,
    INCOMPLETE_CHARACTER_SYNTAX,
    GVAR_WITHOUT_ID,
    INVALID_GVAR_NAME,
    IVAR_WITHOUT_ID,
    INVALID_IVAR_NAME,
    CVAR_WITHOUT_ID,
    INVALID_CVAR_NAME,
    UNKNOWN_REGEX_OPTIONS,
    UNTERMINATED_UNICODE_ESCAPE,
    ENCODING_ERROR,
    INVALID_MULTIBYTE_CHAR,
    AMBIGUOUS_TERNARY_OPERATOR,
    AMBIGUOUS_REGEXP,
    ELSE_WITHOUT_RESCUE,
    BEGIN_NOT_AT_TOP_LEVEL,
    ALIAS_NTH_REF,
    CSEND_INSIDE_MASGN,
    CLASS_OR_MODULE_NAME_MUST_BE_CONSTANT,
    ENDLESS_SETTER_DEFINITION,
    UNEXPECTED_TOKEN,
    CLASS_DEFINITION_IN_METHOD_BODY,
    MODULE_DEFINITION_IN_METHOD_BODY,
    INVALID_RETURN_IN_CLASS_OR_MODULE_BODY,
    CONST_ARGUMENT,
    IVAR_ARGUMENT,
    GVAR_ARGUMENT,
    CVAR_ARGUMENT,
    NO_SUCH_LOCAL_VARIABLE,
    ORDINARY_PARAM_DEFINED,
    NUMPARAM_USED,
    TOK_AT_EOL_WITHOUT_EXPRESSION,
    END_IN_METHOD,
    COMPARISON_AFTER_COMPARISON,
    CIRCULAR_ARGUMENT_REFERENCE,
    DYNAMIC_CONSTANT_ASSIGNMENT,
    CANT_ASSIGN_TO_SELF,
    CANT_ASSIGN_TO_NIL,
    CANT_ASSIGN_TO_TRUE,
    CANT_ASSIGN_TO_FALSE,
    CANT_ASSIGN_TO_FILE,
    CANT_ASSIGN_TO_LINE,
    CANT_ASSIGN_TO_ENCODING,
    CANT_ASSIGN_TO_NUMPARAM,
    CANT_SET_VARIABLE,
    BLOCK_GIVEN_TO_YIELD,
    BLOCK_AND_BLOCK_ARG_GIVEN,
    SYMBOL_LITERAL_WITH_INTERPOLATION,
    RESERVED_FOR_NUMPARAM,
    KEY_MUST_BE_VALID_AS_LOCAL_VARIABLE,
    DUPLICATE_VARIABLE_NAME,
    DUPLICATE_KEY_NAME,
    SINGLETON_LITERAL,
    NTH_REF_IS_TOO_BIG,
    DUPLICATED_ARGUMENT_NAME,
    REGEX_ERROR,
    INVALID_SYMBOL,
    VOID_VALUE_EXPRESSION
};

struct UnterminatedHeredoc {
    char *heredoc_id;
};

struct AmbiguousFirstArgument {
    char operator_;
};

struct AmbiguousOperator {
    char *operator_;
    char *interpreted_as;
};

struct InvalidCharacterSyntax {
    char *suggestion;
};

struct TrailingCharInNumber {
    char c;
};

struct InvalidChar {
    char c;
};

struct InvalidGvarName {
    char c;
};

struct InvalidIvarName {
    char c;
};

struct InvalidCvarName {
    char c;
};

struct UnknownRegexOptions {
    char *options;
};

struct EncodingError {
    char *error;
};

struct AmbiguousTernaryOperator {
    char *condition;
};

struct UnexpectedToken {
    char *token_name;
};

struct NoSuchLocalVariable {
    char *var_name;
};

struct TokAtEolWithoutExpression {
    char *token_name;
};

struct ComparisonAfterComparison {
    char *comparison;
};

struct CircularArgumentReference {
    char *arg_name;
};

struct CantAssignToNumparam {
    char *numparam;
};

struct CantSetVariable {
    char *var_name;
};

struct ReservedForNumparam {
    char *numparam;
};

struct NthRefIsTooBig {
    char *nth_ref;
};

struct RegexError {
    char *error;
};

struct InvalidSymbol {
    char *symbol;
};

union DiagnosticMessageData {
    struct UnterminatedHeredoc unterminated_heredoc;
    struct AmbiguousFirstArgument ambiguous_first_argument;
    struct AmbiguousOperator ambiguous_operator;
    struct InvalidCharacterSyntax invalid_character_syntax;
    struct TrailingCharInNumber trailing_char_in_number;
    struct InvalidChar invalid_char;
    struct InvalidGvarName invalid_gvar_name;
    struct InvalidIvarName invalid_ivar_name;
    struct InvalidCvarName invalid_cvar_name;
    struct UnknownRegexOptions unknown_regex_options;
    struct EncodingError encoding_error;
    struct AmbiguousTernaryOperator ambiguous_ternary_operator;
    struct UnexpectedToken unexpected_token;
    struct NoSuchLocalVariable no_such_local_variable;
    struct TokAtEolWithoutExpression tok_at_eol_without_expression;
    struct ComparisonAfterComparison comparison_after_comparison;
    struct CircularArgumentReference circular_argument_reference;
    struct CantAssignToNumparam cant_assign_to_numparam;
    struct CantSetVariable cant_set_variable;
    struct ReservedForNumparam reserved_for_numparam;
    struct NthRefIsTooBig nth_ref_is_too_big;
    struct RegexError regex_error;
    struct InvalidSymbol invalid_symbol;
    uint32_t other;
};

struct DiagnosticMessage {
    enum DiagnosticMessageType type;
    union DiagnosticMessageData data;
};

void diagnostic_message_free(struct DiagnosticMessage);

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_MESSAGE_H