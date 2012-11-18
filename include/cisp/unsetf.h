/**
 * This file defines a macro to remove a field of a type.
 */

#ifndef CISP_UNSETF_H
#define CISP_UNSETF_H

#include <cisp/detail/token.h>
#include <cisp/detail/type.h>

#include <chaos/preprocessor/recursion/expr.h>


/**
 * Remove a field from a type. If there are many fields with the same key,
 * only the first one is removed. If there is no such field in the type,
 * nothing is done.
 * @param self The type to remove a field from.
 * @param key A valid cisp token representing the name of the field to remove.
 */
#define CISP_UNSETF(self, key) \
    CISP_UNSETF_S(CHAOS_PP_STATE(), self, key)

#define CISP_UNSETF_S(s, self, key) \
    CISP_I_REMOVE_FIRST_FIELD_S(s, self, CISP_I_TOKEN_TO_STRING(key))

#endif /* !CISP_UNSETF_H */
