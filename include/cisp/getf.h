/**
 * This file defines a macro to get a field of a type.
 */

#ifndef CISP_GETF_H
#define CISP_GETF_H

#include <cisp/detail/config.h>
#include <cisp/detail/token.h>
#include <cisp/detail/type.h>

#include <chaos/preprocessor/control/iif.h>
#include <chaos/preprocessor/control/inline_when.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/core.h>
#include <chaos/preprocessor/string/compare.h>


/**
 * Get a field of a type. If there are many fields with the same key, the
 * value of the first encountered is returned.
 * @param self The type to get a field from.
 * @param key A valid cisp token representing the name of the field.
 */
#define CISP_GETF(self, key) \
    CISP_GETF_S(CHAOS_PP_STATE(), self, key)

#define CISP_GETF_S(s, self, key)                                              \
    CHAOS_PP_EXPR_S(s)(                                                        \
        CISP_I_GETF(                                                           \
            CHAOS_PP_OBSTRUCT(),                                               \
            CHAOS_PP_NEXT(s),                                                  \
            self, key))                                                        \
/**/

#define CISP_I_GETF_ID() CISP_I_GETF
#define CISP_I_GETF(_, s, self, key)                                           \
    CHAOS_PP_INLINE_WHEN _(CHAOS_PP_SEQ_IS_CONS _(self)) (                     \
        CHAOS_PP_IIF _(                                                        \
            CHAOS_PP_STRING_COMPARE _(                                         \
                key,                                                           \
                CISP_I_FIELD_KEY _(CHAOS_PP_SEQ_HEAD _(self)))) (              \
                                                                               \
            CISP_I_FIELD_VALUE _(CHAOS_PP_SEQ_HEAD _(self)),                   \
                                                                               \
            CHAOS_PP_EXPR_S _(s)(                                              \
                CISP_I_GETF_ID _()(                                            \
                    CHAOS_PP_OBSTRUCT _(),                                     \
                    CHAOS_PP_NEXT(s),                                          \
                    CHAOS_PP_SEQ_TAIL _(self),                                 \
                    key))))                                                    \
/**/

#if CISP_CONFIG_GENERATE_SHORT_NAMES
#   define getf(self, key) CISP_GETF(self, key)
#   define getf_s(s, self, key) CISP_GETF_S(s, self, key)
#endif

#endif /* !CISP_GETF_H */
