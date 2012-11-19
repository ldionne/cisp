/**
 * This file contains unit tests for basic fields.
 */

#include <cisp/detail/field.h>


#define field CISP_I_FIELD(key, value)

[[[

CISP_I_FIELD_KEY(field) == key
CISP_I_FIELD_VALUE(field) == value
CISP_I_FIELD_COMPARE_KEY_OF(field, k e y) == 1
CISP_I_FIELD_COMPARE_KEY_OF(field, a b c) == 0
CISP_I_FIELD_COMPARE_KEYS(field, field) == 1
CISP_I_FIELD_COMPARE_KEYS(field, CISP_I_FIELD(o t h e r, other)) == 0

]]]
