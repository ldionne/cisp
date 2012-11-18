/**
 * This file defines a macro to unset many fields at once.
 */

#ifndef CISP_BATCH_UNSETF_H
#define CISP_BATCH_UNSETF_H

#include <cisp/detail/token.h>
#include <cisp/unsetf.h>

#include <chaos/preprocessor/control/iif.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/core.h>
#include <chaos/preprocessor/seq/fold_left.h>


/**
 * Unset several fields at once. This is equivalent to calling `CISP_UNSETF`
 * with each key in the sequence.
 * @param self The type to remove fields from.
 * @param keys A string of keys to remove.
 */
#define CISP_BATCH_UNSETF(self, keys) \
    CISP_BATCH_UNSETF_S(CHAOS_PP_STATE(), self, keys)

#define CISP_BATCH_UNSETF_S(s, self, keys)                                     \
    CHAOS_PP_IIF(CISP_I_TOKEN_STRING_IS_CONS(keys)) (                          \
        CHAOS_PP_EXPR_S(s)(                                                    \
            CHAOS_PP_SEQ_FOLD_LEFT_S(                                          \
                s,                                                             \
                CISP_I_BATCH_UNSETF,                                           \
                CISP_I_TOKEN_STRING_TO_SEQ_S(s, keys),                         \
                self)),                                                        \
        self)                                                                  \
/**/

#define CISP_I_BATCH_UNSETF(s, key, self) CISP_UNSETF_S(s, self, key)

#endif /* !CISP_BATCH_UNSETF_H */
