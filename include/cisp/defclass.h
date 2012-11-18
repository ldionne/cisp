/**
 * This file defines a macro to incrementally build sequences of fields.
 */

#ifndef CISP_DEFCLASS_H
#define CISP_DEFCLASS_H

#include <cisp/detail/config.h>
#include <cisp/detail/token.h>
#include <cisp/detail/type.h>

#include <chaos/preprocessor/cat.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/fold_left.h>


/**
 * Incrementally build a type, i.e. a sequence of fields.
 *
 * @param name_and_instructions
 * A valid token representing the name of the type, followed by a sequence of
 * instructions of the form:
 * (instruction_1 [args...])
 * (instruction_2 [args...])
 *         ...
 * (instruction_n [args...])
 *
 * @note A valid instruction is defined by the `CISP_I_INSTRUCTION` macro.
 */
#define CISP_DEFCLASS(name_and_instructions) \
    CISP_DEFCLASS_S(CHAOS_PP_STATE(), name_and_instructions)

#define CISP_DEFCLASS_S(s, name_and_instructions)                              \
    CISP_I_DEFCLASS(                                                           \
        s,                                                                     \
        CISP_I_TOKEN_STRING_HEAD(name_and_instructions),                       \
        CISP_I_TOKEN_STRING_TAIL_UNSAFE(name_and_instructions))                \
/**/

#define CISP_I_DEFCLASS(s, name, instructions)                                 \
    CHAOS_PP_EXPR_S(s)(                                                        \
        CHAOS_PP_SEQ_FOLD_LEFT_S(                                              \
            s,                                                                 \
            CISP_I_EXECUTE_INSTRUCTION,                                        \
            instructions,                                                      \
            CISP_I_EMPTY_TYPE()))                                              \
/**/

/**
 * Execute a token string of the form:
 * instruction [arguments...]
 */
#define CISP_I_EXECUTE_INSTRUCTION(s, instruction_and_args, self)              \
    CISP_I_INSTRUCTION(CISP_I_TOKEN_STRING_HEAD(instruction_and_args))         \
    (s, self, CISP_I_TOKEN_STRING_TAIL_UNSAFE(instruction_and_args))           \
/**/

/**
 * Return the instruction macro associated to a token.
 * An instruction macro is a macro of the form:
 * `macro(s, type, arguments)`
 * Where:
 * `s` is the current recursion state.
 * `type` is the partially built sequence of fields.
 * `arguments` is arbitrary data.
 *
 * To create an instruction `xxx`, the following macro must be defined:
 * `#define CISP_INSTRUCTION_xxx(s, type, arguments) ...`
 * the name of the instruction must also be a valid cisp token, to the
 * following must also be defined:
 * `#define CISP_TOKEN_xxx (x x x)`
 */
#define CISP_I_INSTRUCTION(token) CHAOS_PP_CAT(CISP_INSTRUCTION_, token)

#endif /* !CISP_DEFCLASS_H */
