use crate::bindings;
use crate::diagnostic_payload::*;

impl From<lib_ruby_parser::DiagnosticMessage> for bindings::DiagnosticMessage {
    fn from(message: lib_ruby_parser::DiagnosticMessage) -> Self {
        match message {
            lib_ruby_parser::DiagnosticMessage::FractionAfterNumeric {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::FRACTION_AFTER_NUMERIC,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::NoDigitsAfterDot {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::NO_DIGITS_AFTER_DOT,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::UnknownTypeOfPercentString {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::UNKNOWN_TYPE_OF_PERCENT_STRING,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::NumericLiteralWithoutDigits {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::NUMERIC_LITERAL_WITHOUT_DIGITS,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedList {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::UNTERMINATED_LIST,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedRegexp {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::UNTERMINATED_REGEXP,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedString {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::UNTERMINATED_STRING,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedQuotedString {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::UNTERMINATED_QUOTED_STRING,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidUnicodeEscape {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::INVALID_UNICODE_ESCAPE,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::TooLargeUnicodeCodepoint {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::TOO_LARGE_UNICODE_CODEPOINT,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidUnicodeCodepoint {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::INVALID_UNICODE_CODEPOINT,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::MultipleCodepointAtSingleChar {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::MULTIPLE_CODEPOINT_AT_SINGLE_CHAR,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidEscapeCharacter {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::INVALID_ESCAPE_CHARACTER,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidHexEscape {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::INVALID_HEX_ESCAPE,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedHeredoc { heredoc_id } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::UNTERMINATED_HEREDOC,
                    data: bindings::DiagnosticMessageData {
                        unterminated_heredoc: bindings::UnterminatedHeredoc { heredoc_id: DiagnosticPayload::new(heredoc_id).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedHeredocId {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::UNTERMINATED_HEREDOC_ID,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::SlashRAtMiddleOfLine {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::SLASH_R_AT_MIDDLE_OF_LINE,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::DStarInterpretedAsArgPrefix {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::D_STAR_INTERPRETED_AS_ARG_PREFIX,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::StarInterpretedAsArgPrefix {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::STAR_INTERPRETED_AS_ARG_PREFIX,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::AmpersandInterpretedAsArgPrefix {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::AMPERSAND_INTERPRETED_AS_ARG_PREFIX,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::TripleDotAtEol {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::TRIPLE_DOT_AT_EOL,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::ParenthesesIterpretedAsArglist {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::PARENTHESES_ITERPRETED_AS_ARGLIST,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::AmbiguousFirstArgument { operator } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::AMBIGUOUS_FIRST_ARGUMENT,
                    data: bindings::DiagnosticMessageData {
                        ambiguous_first_argument: bindings::AmbiguousFirstArgument { operator_: DiagnosticPayload::new(operator).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::AmbiguousOperator { operator, interpreted_as } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::AMBIGUOUS_OPERATOR,
                    data: bindings::DiagnosticMessageData {
                        ambiguous_operator: bindings::AmbiguousOperator { operator_: DiagnosticPayload::new(operator).unwrap(), interpreted_as: DiagnosticPayload::new(interpreted_as).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidCharacterSyntax { suggestion } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::INVALID_CHARACTER_SYNTAX,
                    data: bindings::DiagnosticMessageData {
                        invalid_character_syntax: bindings::InvalidCharacterSyntax { suggestion: DiagnosticPayload::new(suggestion).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidOctalDigit {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::INVALID_OCTAL_DIGIT,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::TrailingCharInNumber { c } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::TRAILING_CHAR_IN_NUMBER,
                    data: bindings::DiagnosticMessageData {
                        trailing_char_in_number: bindings::TrailingCharInNumber { c: DiagnosticPayload::new(c).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::EmbeddedDocumentMeetsEof {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::EMBEDDED_DOCUMENT_MEETS_EOF,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidChar { c } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::INVALID_CHAR,
                    data: bindings::DiagnosticMessageData {
                        invalid_char: bindings::InvalidChar { c: DiagnosticPayload::new(c).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::IncompleteCharacterSyntax {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::INCOMPLETE_CHARACTER_SYNTAX,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::GvarWithoutId {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::GVAR_WITHOUT_ID,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidGvarName { c } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::INVALID_GVAR_NAME,
                    data: bindings::DiagnosticMessageData {
                        invalid_gvar_name: bindings::InvalidGvarName { c: DiagnosticPayload::new(c).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::IvarWithoutId {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::IVAR_WITHOUT_ID,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidIvarName { c } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::INVALID_IVAR_NAME,
                    data: bindings::DiagnosticMessageData {
                        invalid_ivar_name: bindings::InvalidIvarName { c: DiagnosticPayload::new(c).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::CvarWithoutId {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CVAR_WITHOUT_ID,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidCvarName { c } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::INVALID_CVAR_NAME,
                    data: bindings::DiagnosticMessageData {
                        invalid_cvar_name: bindings::InvalidCvarName { c: DiagnosticPayload::new(c).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::UnknownRegexOptions { options } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::UNKNOWN_REGEX_OPTIONS,
                    data: bindings::DiagnosticMessageData {
                        unknown_regex_options: bindings::UnknownRegexOptions { options: DiagnosticPayload::new(options).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedUnicodeEscape {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::UNTERMINATED_UNICODE_ESCAPE,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::EncodingError { error } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::ENCODING_ERROR,
                    data: bindings::DiagnosticMessageData {
                        encoding_error: bindings::EncodingError { error: DiagnosticPayload::new(error).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::AmbiguousTernaryOperator { condition } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::AMBIGUOUS_TERNARY_OPERATOR,
                    data: bindings::DiagnosticMessageData {
                        ambiguous_ternary_operator: bindings::AmbiguousTernaryOperator { condition: DiagnosticPayload::new(condition).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::AmbiguousRegexp {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::AMBIGUOUS_REGEXP,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::ElseWithoutRescue {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::ELSE_WITHOUT_RESCUE,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::BeginNotAtTopLevel {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::BEGIN_NOT_AT_TOP_LEVEL,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::AliasNthRef {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::ALIAS_NTH_REF,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::CsendInsideMasgn {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CSEND_INSIDE_MASGN,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::ClassOrModuleNameMustBeConstant {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CLASS_OR_MODULE_NAME_MUST_BE_CONSTANT,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::EndlessSetterDefinition {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::ENDLESS_SETTER_DEFINITION,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::UnexpectedToken { token_name } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::UNEXPECTED_TOKEN,
                    data: bindings::DiagnosticMessageData {
                        unexpected_token: bindings::UnexpectedToken { token_name: DiagnosticPayload::new(token_name).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::ClassDefinitionInMethodBody {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CLASS_DEFINITION_IN_METHOD_BODY,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::ModuleDefinitionInMethodBody {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::MODULE_DEFINITION_IN_METHOD_BODY,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidReturnInClassOrModuleBody {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::INVALID_RETURN_IN_CLASS_OR_MODULE_BODY,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::ConstArgument {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CONST_ARGUMENT,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::IvarArgument {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::IVAR_ARGUMENT,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::GvarArgument {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::GVAR_ARGUMENT,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::CvarArgument {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CVAR_ARGUMENT,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::NoSuchLocalVariable { var_name } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::NO_SUCH_LOCAL_VARIABLE,
                    data: bindings::DiagnosticMessageData {
                        no_such_local_variable: bindings::NoSuchLocalVariable { var_name: DiagnosticPayload::new(var_name).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::OrdinaryParamDefined {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::ORDINARY_PARAM_DEFINED,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::NumparamUsed {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::NUMPARAM_USED,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::TokAtEolWithoutExpression { token_name } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::TOK_AT_EOL_WITHOUT_EXPRESSION,
                    data: bindings::DiagnosticMessageData {
                        tok_at_eol_without_expression: bindings::TokAtEolWithoutExpression { token_name: DiagnosticPayload::new(token_name).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::EndInMethod {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::END_IN_METHOD,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::ComparisonAfterComparison { comparison } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::COMPARISON_AFTER_COMPARISON,
                    data: bindings::DiagnosticMessageData {
                        comparison_after_comparison: bindings::ComparisonAfterComparison { comparison: DiagnosticPayload::new(comparison).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::CircularArgumentReference { arg_name } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CIRCULAR_ARGUMENT_REFERENCE,
                    data: bindings::DiagnosticMessageData {
                        circular_argument_reference: bindings::CircularArgumentReference { arg_name: DiagnosticPayload::new(arg_name).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::DynamicConstantAssignment {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::DYNAMIC_CONSTANT_ASSIGNMENT,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToSelf {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CANT_ASSIGN_TO_SELF,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToNil {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CANT_ASSIGN_TO_NIL,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToTrue {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CANT_ASSIGN_TO_TRUE,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToFalse {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CANT_ASSIGN_TO_FALSE,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToFile {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CANT_ASSIGN_TO_FILE,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToLine {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CANT_ASSIGN_TO_LINE,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToEncoding {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CANT_ASSIGN_TO_ENCODING,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToNumparam { numparam } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CANT_ASSIGN_TO_NUMPARAM,
                    data: bindings::DiagnosticMessageData {
                        cant_assign_to_numparam: bindings::CantAssignToNumparam { numparam: DiagnosticPayload::new(numparam).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::CantSetVariable { var_name } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::CANT_SET_VARIABLE,
                    data: bindings::DiagnosticMessageData {
                        cant_set_variable: bindings::CantSetVariable { var_name: DiagnosticPayload::new(var_name).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::BlockGivenToYield {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::BLOCK_GIVEN_TO_YIELD,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::BlockAndBlockArgGiven {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::BLOCK_AND_BLOCK_ARG_GIVEN,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::SymbolLiteralWithInterpolation {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::SYMBOL_LITERAL_WITH_INTERPOLATION,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::ReservedForNumparam { numparam } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::RESERVED_FOR_NUMPARAM,
                    data: bindings::DiagnosticMessageData {
                        reserved_for_numparam: bindings::ReservedForNumparam { numparam: DiagnosticPayload::new(numparam).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::KeyMustBeValidAsLocalVariable {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::KEY_MUST_BE_VALID_AS_LOCAL_VARIABLE,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::DuplicateVariableName {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::DUPLICATE_VARIABLE_NAME,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::DuplicateKeyName {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::DUPLICATE_KEY_NAME,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::SingletonLiteral {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::SINGLETON_LITERAL,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::NthRefIsTooBig { nth_ref } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::NTH_REF_IS_TOO_BIG,
                    data: bindings::DiagnosticMessageData {
                        nth_ref_is_too_big: bindings::NthRefIsTooBig { nth_ref: DiagnosticPayload::new(nth_ref).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::DuplicatedArgumentName {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::DUPLICATED_ARGUMENT_NAME,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::RegexError { error } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::REGEX_ERROR,
                    data: bindings::DiagnosticMessageData {
                        regex_error: bindings::RegexError { error: DiagnosticPayload::new(error).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidSymbol { symbol } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::INVALID_SYMBOL,
                    data: bindings::DiagnosticMessageData {
                        invalid_symbol: bindings::InvalidSymbol { symbol: DiagnosticPayload::new(symbol).unwrap() },
                    },
                }
            },
            lib_ruby_parser::DiagnosticMessage::VoidValueExpression {  } => {
                bindings::DiagnosticMessage {
                    type_: bindings::DiagnosticMessageType::VOID_VALUE_EXPRESSION,
                    data: bindings::DiagnosticMessageData {
                        other: 42
                    },
                }
            }
        }
    }
}

impl From<bindings::DiagnosticMessage> for lib_ruby_parser::DiagnosticMessage {
    fn from(message: bindings::DiagnosticMessage) -> Self {
        match message.type_ {
            bindings::DiagnosticMessageType::FRACTION_AFTER_NUMERIC => {
                
                lib_ruby_parser::DiagnosticMessage::FractionAfterNumeric {  }
            },
            bindings::DiagnosticMessageType::NO_DIGITS_AFTER_DOT => {
                
                lib_ruby_parser::DiagnosticMessage::NoDigitsAfterDot {  }
            },
            bindings::DiagnosticMessageType::UNKNOWN_TYPE_OF_PERCENT_STRING => {
                
                lib_ruby_parser::DiagnosticMessage::UnknownTypeOfPercentString {  }
            },
            bindings::DiagnosticMessageType::NUMERIC_LITERAL_WITHOUT_DIGITS => {
                
                lib_ruby_parser::DiagnosticMessage::NumericLiteralWithoutDigits {  }
            },
            bindings::DiagnosticMessageType::UNTERMINATED_LIST => {
                
                lib_ruby_parser::DiagnosticMessage::UnterminatedList {  }
            },
            bindings::DiagnosticMessageType::UNTERMINATED_REGEXP => {
                
                lib_ruby_parser::DiagnosticMessage::UnterminatedRegexp {  }
            },
            bindings::DiagnosticMessageType::UNTERMINATED_STRING => {
                
                lib_ruby_parser::DiagnosticMessage::UnterminatedString {  }
            },
            bindings::DiagnosticMessageType::UNTERMINATED_QUOTED_STRING => {
                
                lib_ruby_parser::DiagnosticMessage::UnterminatedQuotedString {  }
            },
            bindings::DiagnosticMessageType::INVALID_UNICODE_ESCAPE => {
                
                lib_ruby_parser::DiagnosticMessage::InvalidUnicodeEscape {  }
            },
            bindings::DiagnosticMessageType::TOO_LARGE_UNICODE_CODEPOINT => {
                
                lib_ruby_parser::DiagnosticMessage::TooLargeUnicodeCodepoint {  }
            },
            bindings::DiagnosticMessageType::INVALID_UNICODE_CODEPOINT => {
                
                lib_ruby_parser::DiagnosticMessage::InvalidUnicodeCodepoint {  }
            },
            bindings::DiagnosticMessageType::MULTIPLE_CODEPOINT_AT_SINGLE_CHAR => {
                
                lib_ruby_parser::DiagnosticMessage::MultipleCodepointAtSingleChar {  }
            },
            bindings::DiagnosticMessageType::INVALID_ESCAPE_CHARACTER => {
                
                lib_ruby_parser::DiagnosticMessage::InvalidEscapeCharacter {  }
            },
            bindings::DiagnosticMessageType::INVALID_HEX_ESCAPE => {
                
                lib_ruby_parser::DiagnosticMessage::InvalidHexEscape {  }
            },
            bindings::DiagnosticMessageType::UNTERMINATED_HEREDOC => {
                let heredoc_id = unsafe { message.data.unterminated_heredoc }.heredoc_id;
                lib_ruby_parser::DiagnosticMessage::UnterminatedHeredoc { heredoc_id: DiagnosticPayload::new(heredoc_id).unwrap() }
            },
            bindings::DiagnosticMessageType::UNTERMINATED_HEREDOC_ID => {
                
                lib_ruby_parser::DiagnosticMessage::UnterminatedHeredocId {  }
            },
            bindings::DiagnosticMessageType::SLASH_R_AT_MIDDLE_OF_LINE => {
                
                lib_ruby_parser::DiagnosticMessage::SlashRAtMiddleOfLine {  }
            },
            bindings::DiagnosticMessageType::D_STAR_INTERPRETED_AS_ARG_PREFIX => {
                
                lib_ruby_parser::DiagnosticMessage::DStarInterpretedAsArgPrefix {  }
            },
            bindings::DiagnosticMessageType::STAR_INTERPRETED_AS_ARG_PREFIX => {
                
                lib_ruby_parser::DiagnosticMessage::StarInterpretedAsArgPrefix {  }
            },
            bindings::DiagnosticMessageType::AMPERSAND_INTERPRETED_AS_ARG_PREFIX => {
                
                lib_ruby_parser::DiagnosticMessage::AmpersandInterpretedAsArgPrefix {  }
            },
            bindings::DiagnosticMessageType::TRIPLE_DOT_AT_EOL => {
                
                lib_ruby_parser::DiagnosticMessage::TripleDotAtEol {  }
            },
            bindings::DiagnosticMessageType::PARENTHESES_ITERPRETED_AS_ARGLIST => {
                
                lib_ruby_parser::DiagnosticMessage::ParenthesesIterpretedAsArglist {  }
            },
            bindings::DiagnosticMessageType::AMBIGUOUS_FIRST_ARGUMENT => {
                let operator = unsafe { message.data.ambiguous_first_argument }.operator_;
                lib_ruby_parser::DiagnosticMessage::AmbiguousFirstArgument { operator: DiagnosticPayload::new(operator).unwrap() }
            },
            bindings::DiagnosticMessageType::AMBIGUOUS_OPERATOR => {
                let operator = unsafe { message.data.ambiguous_operator }.operator_;
                let interpreted_as = unsafe { message.data.ambiguous_operator }.interpreted_as;
                lib_ruby_parser::DiagnosticMessage::AmbiguousOperator { operator: DiagnosticPayload::new(operator).unwrap(), interpreted_as: DiagnosticPayload::new(interpreted_as).unwrap() }
            },
            bindings::DiagnosticMessageType::INVALID_CHARACTER_SYNTAX => {
                let suggestion = unsafe { message.data.invalid_character_syntax }.suggestion;
                lib_ruby_parser::DiagnosticMessage::InvalidCharacterSyntax { suggestion: DiagnosticPayload::new(suggestion).unwrap() }
            },
            bindings::DiagnosticMessageType::INVALID_OCTAL_DIGIT => {
                
                lib_ruby_parser::DiagnosticMessage::InvalidOctalDigit {  }
            },
            bindings::DiagnosticMessageType::TRAILING_CHAR_IN_NUMBER => {
                let c = unsafe { message.data.trailing_char_in_number }.c;
                lib_ruby_parser::DiagnosticMessage::TrailingCharInNumber { c: DiagnosticPayload::new(c).unwrap() }
            },
            bindings::DiagnosticMessageType::EMBEDDED_DOCUMENT_MEETS_EOF => {
                
                lib_ruby_parser::DiagnosticMessage::EmbeddedDocumentMeetsEof {  }
            },
            bindings::DiagnosticMessageType::INVALID_CHAR => {
                let c = unsafe { message.data.invalid_char }.c;
                lib_ruby_parser::DiagnosticMessage::InvalidChar { c: DiagnosticPayload::new(c).unwrap() }
            },
            bindings::DiagnosticMessageType::INCOMPLETE_CHARACTER_SYNTAX => {
                
                lib_ruby_parser::DiagnosticMessage::IncompleteCharacterSyntax {  }
            },
            bindings::DiagnosticMessageType::GVAR_WITHOUT_ID => {
                
                lib_ruby_parser::DiagnosticMessage::GvarWithoutId {  }
            },
            bindings::DiagnosticMessageType::INVALID_GVAR_NAME => {
                let c = unsafe { message.data.invalid_gvar_name }.c;
                lib_ruby_parser::DiagnosticMessage::InvalidGvarName { c: DiagnosticPayload::new(c).unwrap() }
            },
            bindings::DiagnosticMessageType::IVAR_WITHOUT_ID => {
                
                lib_ruby_parser::DiagnosticMessage::IvarWithoutId {  }
            },
            bindings::DiagnosticMessageType::INVALID_IVAR_NAME => {
                let c = unsafe { message.data.invalid_ivar_name }.c;
                lib_ruby_parser::DiagnosticMessage::InvalidIvarName { c: DiagnosticPayload::new(c).unwrap() }
            },
            bindings::DiagnosticMessageType::CVAR_WITHOUT_ID => {
                
                lib_ruby_parser::DiagnosticMessage::CvarWithoutId {  }
            },
            bindings::DiagnosticMessageType::INVALID_CVAR_NAME => {
                let c = unsafe { message.data.invalid_cvar_name }.c;
                lib_ruby_parser::DiagnosticMessage::InvalidCvarName { c: DiagnosticPayload::new(c).unwrap() }
            },
            bindings::DiagnosticMessageType::UNKNOWN_REGEX_OPTIONS => {
                let options = unsafe { message.data.unknown_regex_options }.options;
                lib_ruby_parser::DiagnosticMessage::UnknownRegexOptions { options: DiagnosticPayload::new(options).unwrap() }
            },
            bindings::DiagnosticMessageType::UNTERMINATED_UNICODE_ESCAPE => {
                
                lib_ruby_parser::DiagnosticMessage::UnterminatedUnicodeEscape {  }
            },
            bindings::DiagnosticMessageType::ENCODING_ERROR => {
                let error = unsafe { message.data.encoding_error }.error;
                lib_ruby_parser::DiagnosticMessage::EncodingError { error: DiagnosticPayload::new(error).unwrap() }
            },
            bindings::DiagnosticMessageType::AMBIGUOUS_TERNARY_OPERATOR => {
                let condition = unsafe { message.data.ambiguous_ternary_operator }.condition;
                lib_ruby_parser::DiagnosticMessage::AmbiguousTernaryOperator { condition: DiagnosticPayload::new(condition).unwrap() }
            },
            bindings::DiagnosticMessageType::AMBIGUOUS_REGEXP => {
                
                lib_ruby_parser::DiagnosticMessage::AmbiguousRegexp {  }
            },
            bindings::DiagnosticMessageType::ELSE_WITHOUT_RESCUE => {
                
                lib_ruby_parser::DiagnosticMessage::ElseWithoutRescue {  }
            },
            bindings::DiagnosticMessageType::BEGIN_NOT_AT_TOP_LEVEL => {
                
                lib_ruby_parser::DiagnosticMessage::BeginNotAtTopLevel {  }
            },
            bindings::DiagnosticMessageType::ALIAS_NTH_REF => {
                
                lib_ruby_parser::DiagnosticMessage::AliasNthRef {  }
            },
            bindings::DiagnosticMessageType::CSEND_INSIDE_MASGN => {
                
                lib_ruby_parser::DiagnosticMessage::CsendInsideMasgn {  }
            },
            bindings::DiagnosticMessageType::CLASS_OR_MODULE_NAME_MUST_BE_CONSTANT => {
                
                lib_ruby_parser::DiagnosticMessage::ClassOrModuleNameMustBeConstant {  }
            },
            bindings::DiagnosticMessageType::ENDLESS_SETTER_DEFINITION => {
                
                lib_ruby_parser::DiagnosticMessage::EndlessSetterDefinition {  }
            },
            bindings::DiagnosticMessageType::UNEXPECTED_TOKEN => {
                let token_name = unsafe { message.data.unexpected_token }.token_name;
                lib_ruby_parser::DiagnosticMessage::UnexpectedToken { token_name: DiagnosticPayload::new(token_name).unwrap() }
            },
            bindings::DiagnosticMessageType::CLASS_DEFINITION_IN_METHOD_BODY => {
                
                lib_ruby_parser::DiagnosticMessage::ClassDefinitionInMethodBody {  }
            },
            bindings::DiagnosticMessageType::MODULE_DEFINITION_IN_METHOD_BODY => {
                
                lib_ruby_parser::DiagnosticMessage::ModuleDefinitionInMethodBody {  }
            },
            bindings::DiagnosticMessageType::INVALID_RETURN_IN_CLASS_OR_MODULE_BODY => {
                
                lib_ruby_parser::DiagnosticMessage::InvalidReturnInClassOrModuleBody {  }
            },
            bindings::DiagnosticMessageType::CONST_ARGUMENT => {
                
                lib_ruby_parser::DiagnosticMessage::ConstArgument {  }
            },
            bindings::DiagnosticMessageType::IVAR_ARGUMENT => {
                
                lib_ruby_parser::DiagnosticMessage::IvarArgument {  }
            },
            bindings::DiagnosticMessageType::GVAR_ARGUMENT => {
                
                lib_ruby_parser::DiagnosticMessage::GvarArgument {  }
            },
            bindings::DiagnosticMessageType::CVAR_ARGUMENT => {
                
                lib_ruby_parser::DiagnosticMessage::CvarArgument {  }
            },
            bindings::DiagnosticMessageType::NO_SUCH_LOCAL_VARIABLE => {
                let var_name = unsafe { message.data.no_such_local_variable }.var_name;
                lib_ruby_parser::DiagnosticMessage::NoSuchLocalVariable { var_name: DiagnosticPayload::new(var_name).unwrap() }
            },
            bindings::DiagnosticMessageType::ORDINARY_PARAM_DEFINED => {
                
                lib_ruby_parser::DiagnosticMessage::OrdinaryParamDefined {  }
            },
            bindings::DiagnosticMessageType::NUMPARAM_USED => {
                
                lib_ruby_parser::DiagnosticMessage::NumparamUsed {  }
            },
            bindings::DiagnosticMessageType::TOK_AT_EOL_WITHOUT_EXPRESSION => {
                let token_name = unsafe { message.data.tok_at_eol_without_expression }.token_name;
                lib_ruby_parser::DiagnosticMessage::TokAtEolWithoutExpression { token_name: DiagnosticPayload::new(token_name).unwrap() }
            },
            bindings::DiagnosticMessageType::END_IN_METHOD => {
                
                lib_ruby_parser::DiagnosticMessage::EndInMethod {  }
            },
            bindings::DiagnosticMessageType::COMPARISON_AFTER_COMPARISON => {
                let comparison = unsafe { message.data.comparison_after_comparison }.comparison;
                lib_ruby_parser::DiagnosticMessage::ComparisonAfterComparison { comparison: DiagnosticPayload::new(comparison).unwrap() }
            },
            bindings::DiagnosticMessageType::CIRCULAR_ARGUMENT_REFERENCE => {
                let arg_name = unsafe { message.data.circular_argument_reference }.arg_name;
                lib_ruby_parser::DiagnosticMessage::CircularArgumentReference { arg_name: DiagnosticPayload::new(arg_name).unwrap() }
            },
            bindings::DiagnosticMessageType::DYNAMIC_CONSTANT_ASSIGNMENT => {
                
                lib_ruby_parser::DiagnosticMessage::DynamicConstantAssignment {  }
            },
            bindings::DiagnosticMessageType::CANT_ASSIGN_TO_SELF => {
                
                lib_ruby_parser::DiagnosticMessage::CantAssignToSelf {  }
            },
            bindings::DiagnosticMessageType::CANT_ASSIGN_TO_NIL => {
                
                lib_ruby_parser::DiagnosticMessage::CantAssignToNil {  }
            },
            bindings::DiagnosticMessageType::CANT_ASSIGN_TO_TRUE => {
                
                lib_ruby_parser::DiagnosticMessage::CantAssignToTrue {  }
            },
            bindings::DiagnosticMessageType::CANT_ASSIGN_TO_FALSE => {
                
                lib_ruby_parser::DiagnosticMessage::CantAssignToFalse {  }
            },
            bindings::DiagnosticMessageType::CANT_ASSIGN_TO_FILE => {
                
                lib_ruby_parser::DiagnosticMessage::CantAssignToFile {  }
            },
            bindings::DiagnosticMessageType::CANT_ASSIGN_TO_LINE => {
                
                lib_ruby_parser::DiagnosticMessage::CantAssignToLine {  }
            },
            bindings::DiagnosticMessageType::CANT_ASSIGN_TO_ENCODING => {
                
                lib_ruby_parser::DiagnosticMessage::CantAssignToEncoding {  }
            },
            bindings::DiagnosticMessageType::CANT_ASSIGN_TO_NUMPARAM => {
                let numparam = unsafe { message.data.cant_assign_to_numparam }.numparam;
                lib_ruby_parser::DiagnosticMessage::CantAssignToNumparam { numparam: DiagnosticPayload::new(numparam).unwrap() }
            },
            bindings::DiagnosticMessageType::CANT_SET_VARIABLE => {
                let var_name = unsafe { message.data.cant_set_variable }.var_name;
                lib_ruby_parser::DiagnosticMessage::CantSetVariable { var_name: DiagnosticPayload::new(var_name).unwrap() }
            },
            bindings::DiagnosticMessageType::BLOCK_GIVEN_TO_YIELD => {
                
                lib_ruby_parser::DiagnosticMessage::BlockGivenToYield {  }
            },
            bindings::DiagnosticMessageType::BLOCK_AND_BLOCK_ARG_GIVEN => {
                
                lib_ruby_parser::DiagnosticMessage::BlockAndBlockArgGiven {  }
            },
            bindings::DiagnosticMessageType::SYMBOL_LITERAL_WITH_INTERPOLATION => {
                
                lib_ruby_parser::DiagnosticMessage::SymbolLiteralWithInterpolation {  }
            },
            bindings::DiagnosticMessageType::RESERVED_FOR_NUMPARAM => {
                let numparam = unsafe { message.data.reserved_for_numparam }.numparam;
                lib_ruby_parser::DiagnosticMessage::ReservedForNumparam { numparam: DiagnosticPayload::new(numparam).unwrap() }
            },
            bindings::DiagnosticMessageType::KEY_MUST_BE_VALID_AS_LOCAL_VARIABLE => {
                
                lib_ruby_parser::DiagnosticMessage::KeyMustBeValidAsLocalVariable {  }
            },
            bindings::DiagnosticMessageType::DUPLICATE_VARIABLE_NAME => {
                
                lib_ruby_parser::DiagnosticMessage::DuplicateVariableName {  }
            },
            bindings::DiagnosticMessageType::DUPLICATE_KEY_NAME => {
                
                lib_ruby_parser::DiagnosticMessage::DuplicateKeyName {  }
            },
            bindings::DiagnosticMessageType::SINGLETON_LITERAL => {
                
                lib_ruby_parser::DiagnosticMessage::SingletonLiteral {  }
            },
            bindings::DiagnosticMessageType::NTH_REF_IS_TOO_BIG => {
                let nth_ref = unsafe { message.data.nth_ref_is_too_big }.nth_ref;
                lib_ruby_parser::DiagnosticMessage::NthRefIsTooBig { nth_ref: DiagnosticPayload::new(nth_ref).unwrap() }
            },
            bindings::DiagnosticMessageType::DUPLICATED_ARGUMENT_NAME => {
                
                lib_ruby_parser::DiagnosticMessage::DuplicatedArgumentName {  }
            },
            bindings::DiagnosticMessageType::REGEX_ERROR => {
                let error = unsafe { message.data.regex_error }.error;
                lib_ruby_parser::DiagnosticMessage::RegexError { error: DiagnosticPayload::new(error).unwrap() }
            },
            bindings::DiagnosticMessageType::INVALID_SYMBOL => {
                let symbol = unsafe { message.data.invalid_symbol }.symbol;
                lib_ruby_parser::DiagnosticMessage::InvalidSymbol { symbol: DiagnosticPayload::new(symbol).unwrap() }
            },
            bindings::DiagnosticMessageType::VOID_VALUE_EXPRESSION => {
                
                lib_ruby_parser::DiagnosticMessage::VoidValueExpression {  }
            }
        }
    }
}

pub(crate) fn inner_diagnostic_message_free(message: bindings::DiagnosticMessage) {
    match message.type_ {
        bindings::DiagnosticMessageType::UNTERMINATED_HEREDOC => {
            let ptr = unsafe { message.data.unterminated_heredoc }.heredoc_id; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::AMBIGUOUS_FIRST_ARGUMENT => {
            // free_byte(operator)
        }
        bindings::DiagnosticMessageType::AMBIGUOUS_OPERATOR => {
            let ptr = unsafe { message.data.ambiguous_operator }.operator_; unsafe { std::ffi::CString::from_raw(ptr) };
            let ptr = unsafe { message.data.ambiguous_operator }.interpreted_as; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::INVALID_CHARACTER_SYNTAX => {
            let ptr = unsafe { message.data.invalid_character_syntax }.suggestion; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::TRAILING_CHAR_IN_NUMBER => {
            // free_byte(c)
        }
        bindings::DiagnosticMessageType::INVALID_CHAR => {
            // free_byte(c)
        }
        bindings::DiagnosticMessageType::INVALID_GVAR_NAME => {
            // free_byte(c)
        }
        bindings::DiagnosticMessageType::INVALID_IVAR_NAME => {
            // free_byte(c)
        }
        bindings::DiagnosticMessageType::INVALID_CVAR_NAME => {
            // free_byte(c)
        }
        bindings::DiagnosticMessageType::UNKNOWN_REGEX_OPTIONS => {
            let ptr = unsafe { message.data.unknown_regex_options }.options; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::ENCODING_ERROR => {
            let ptr = unsafe { message.data.encoding_error }.error; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::AMBIGUOUS_TERNARY_OPERATOR => {
            let ptr = unsafe { message.data.ambiguous_ternary_operator }.condition; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::UNEXPECTED_TOKEN => {
            let ptr = unsafe { message.data.unexpected_token }.token_name; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::NO_SUCH_LOCAL_VARIABLE => {
            let ptr = unsafe { message.data.no_such_local_variable }.var_name; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::TOK_AT_EOL_WITHOUT_EXPRESSION => {
            let ptr = unsafe { message.data.tok_at_eol_without_expression }.token_name; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::COMPARISON_AFTER_COMPARISON => {
            let ptr = unsafe { message.data.comparison_after_comparison }.comparison; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::CIRCULAR_ARGUMENT_REFERENCE => {
            let ptr = unsafe { message.data.circular_argument_reference }.arg_name; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::CANT_ASSIGN_TO_NUMPARAM => {
            let ptr = unsafe { message.data.cant_assign_to_numparam }.numparam; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::CANT_SET_VARIABLE => {
            let ptr = unsafe { message.data.cant_set_variable }.var_name; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::RESERVED_FOR_NUMPARAM => {
            let ptr = unsafe { message.data.reserved_for_numparam }.numparam; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::NTH_REF_IS_TOO_BIG => {
            let ptr = unsafe { message.data.nth_ref_is_too_big }.nth_ref; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::REGEX_ERROR => {
            let ptr = unsafe { message.data.regex_error }.error; unsafe { std::ffi::CString::from_raw(ptr) };
        }
        bindings::DiagnosticMessageType::INVALID_SYMBOL => {
            let ptr = unsafe { message.data.invalid_symbol }.symbol; unsafe { std::ffi::CString::from_raw(ptr) };
        },
        _ => {}
    }
}
