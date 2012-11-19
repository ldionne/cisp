/**
 * Macros to manipulate individual fields.
 */

#ifndef CISP_DETAIL_FIELD_H
#define CISP_DETAIL_FIELD_H

#include <chaos/preprocessor/tuple/elem.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/string/compare.h>


/**
 * Create a field.
 *
 * @param key A valid preprocessor string.
 * @param value Anything: the value of the field.
 */
#define CISP_I_FIELD(key, value) (key, value)

/**
 * Return the key of a field.
 */
#define CISP_I_FIELD_KEY(field) CHAOS_PP_TUPLE_ELEM(2, 0, field)

/**
 * Return the value of a field.
 */
#define CISP_I_FIELD_VALUE(field) CHAOS_PP_TUPLE_ELEM(2, 1, field)

/**
 * Return whether a field has the same key as @p key.
 */
#define CISP_I_FIELD_COMPARE_KEY_OF(field, key) \
    CISP_I_FIELD_COMPARE_KEY_OF_S(CHAOS_PP_STATE(), field, key)

#define CISP_I_FIELD_COMPARE_KEY_OF_S(s, field, key) \
    CHAOS_PP_STRING_COMPARE(key, CISP_I_FIELD_KEY(field))

/**
 * Return whether two fields have the same key.
 */
#define CISP_I_FIELD_COMPARE_KEYS(field1, field2) \
    CISP_I_FIELD_COMPARE_KEYS_S(CHAOS_PP_STATE(), field1, field2)

#define CISP_I_FIELD_COMPARE_KEYS_S(s, field1, field2) \
    CISP_I_FIELD_COMPARE_KEY_OF_S(s, field1, CISP_I_FIELD_KEY(field2))

#endif /* !CISP_DETAIL_FIELD_H */
