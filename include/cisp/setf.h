/**
 * This file defines a macro to set a field of a type.
 */

#ifndef CISP_SETF_H
#define CISP_SETF_H

#include <cisp/detail/token.h>
#include <cisp/detail/type.h>

#include <chaos/preprocessor/recursion/expr.h>


/**
 * Set a field of a type. Any other field with the same key is overwritten.
 * @param self The type to modify.
 * @param key A valid cisp token representing the name of the field.
 * @param value Arbitrary data associated to the field.
 * @note The `value` of the field can not contain open commas if variadic
 *       macros are not supported.
 */
#define CISP_SETF(self, key, value) \
    CISP_SETF_S(CHAOS_PP_STATE(), self, key, value)

/* This is to make sure setf and batch_setf never go out of sync. */
#define CISP_I_SETF_UNDERLYING_SETTER(s, self, field) \
    CISP_I_SET_FIELD_UPDATE_FIRST_S(s, self, field)

/* Note: By always updating the first field, we are certain to never
 *       create duplicate fields.
 */
#define CISP_SETF_S(s, self, key, value)                                       \
    CISP_I_SETF_UNDERLYING_SETTER(                                             \
        s,                                                                     \
        self,                                                                  \
        CISP_FIELD(                                                            \
            CISP_I_TOKEN_TO_STRING(key),                                       \
            value))                                                            \
/**/

#define CISP_TOKEN_setf (s e t f)
#define CISP_INSTRUCTION_setf(s, self, key_value)                              \
    CISP_SETF_S(                                                               \
        s,                                                                     \
        self,                                                                  \
        CISP_I_TOKEN_STRING_HEAD(key_value),                                   \
        CISP_I_TOKEN_STRING_TAIL_UNSAFE(key_value))                            \
/**/

#endif /* !CISP_SETF_H */
