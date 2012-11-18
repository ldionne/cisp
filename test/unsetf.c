/**
 * This file contains unit tests for the `UNSETF` family of macros.
 */

#include <cisp/unsetf.h>
#include <cisp/defclass.h>
#include <cisp/setf.h>


#define type CISP_DEFCLASS(a (setf b b) (setf c c) (setf d ~ ~ ~))

[[[
CISP_UNSETF(type, b) == CISP_DEFCLASS(a (setf c c) (setf d ~ ~ ~))
CISP_UNSETF(type, g) == type
CISP_UNSETF(CISP_I_EMPTY_TYPE(), b) == CISP_I_EMPTY_TYPE()

/* should replace the first matching field only */
CISP_UNSETF(((b, b)) ((b, b)), b) == ((b, b))
/* should work on field with a non C identifier value */
CISP_UNSETF(type, d) == CISP_DEFCLASS(a (setf b b) (setf c c))
]]]
