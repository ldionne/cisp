/**
 * This file defines a macro to set many fields at once.
 */

#ifndef CISP_BATCH_SETF_H
#define CISP_BATCH_SETF_H

#include <cisp/detail/config.h>
#include <cisp/detail/token.h>
#include <cisp/detail/type.h>
#include <cisp/setf.h>

#include <chaos/preprocessor/control/iif.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/core.h>
#include <chaos/preprocessor/seq/fold_left.h>


/**
 * Set a sequence of fields at once. This is equivalent to calling
 * `CISP_SETF` with the key and value of each field.
 * @param self The type to update with new fields.
 * @param fields A sequence of fields.
 * @note A type is a valid sequence of fields and may be used to simulate
 *       inheritance.
 */
#define CISP_BATCH_SETF(self, fields) \
    CISP_BATCH_SETF_S(CHAOS_PP_STATE(), self, fields)

#define CISP_BATCH_SETF_S(s, self, fields)                                     \
    CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_CONS(fields)) (                               \
        CHAOS_PP_EXPR_S(s)(                                                    \
            CHAOS_PP_SEQ_FOLD_LEFT_S(s, CISP_I_BATCH_SETF, fields, self)),     \
        self)                                                                  \
/**/

#define CISP_I_BATCH_SETF(s, field, self) \
    CISP_SETF_S(s, self, CISP_I_FIELD_KEY(field), CISP_I_FIELD_VALUE(field))

#define CISP_TOKEN_batch_setf (b a t c h _ s e t f)
#define CISP_INSTRUCTION_batch_setf(s, self, fields) \
    CISP_BATCH_SETF_S(s, self, fields)

#endif /* !CISP_BATCH_SETF_H */
