/**
 * This file contains unit tests for the `UNSETF` family of macros.
 */

#include <cisp/unsetf.h>
#include <cisp/defclass.h>
#include <cisp/setf.h>


#define type CISP_DEFCLASS((setf b b) (setf c c) (setf d ~ ~ ~))
#define CISP_TOKEN_field (f i e l d)
#define CISP_TOKEN_field2 (f i e l d 2)

[[[
CISP_UNSETF(type, b) == CISP_DEFCLASS((setf c c) (setf d ~ ~ ~))
CISP_UNSETF(type, g) == type
CISP_UNSETF(CISP_I_EMPTY_TYPE(), b) == CISP_I_EMPTY_TYPE()

/* should replace the first matching field only */
CISP_UNSETF(((b, b)) ((b, b)), b) == ((b, b))
/* should work on field with a non C identifier value */
CISP_UNSETF(type, d) == CISP_DEFCLASS((setf b b) (setf c c))
/* should work with long tokens */
CISP_UNSETF(CISP_DEFCLASS((setf field value)), field) == CISP_I_EMPTY_TYPE()
CISP_UNSETF(CISP_DEFCLASS((setf field value) (setf field2 value2)), field) == CISP_DEFCLASS((setf field2 value2))
]]]
