/**
 * This file contains unit tests for the `GETF` family of macros.
 */

#include <cisp/getf.h>
#include <cisp/defclass.h>
#include <cisp/setf.h>


#define CISP_TOKEN_field (f i e l d)
#define type CISP_DEFCLASS((setf b b) (setf c c) (setf d ~ ~ ~) (setf field value))

[[[
CISP_GETF(type, b) == b
CISP_GETF(type, c) == c
CISP_GETF(type, d) == ~ ~ ~

"" CISP_GETF(type, e) == ""
"" CISP_GETF(CISP_I_EMPTY_TYPE(), a) == ""
CISP_GETF(type, field) == value
]]]
