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

]]]
