/**
 * Macros to manipulate individual fields.
 */

#ifndef CISP_DETAIL_FIELD_H
#define CISP_DETAIL_FIELD_H

#include <chaos/preprocessor/tuple/elem.h>


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

#endif /* !CISP_DETAIL_FIELD_H */
