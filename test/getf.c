/**
 * This file contains unit tests for the `GETF` family of macros.
 */

#include <cisp/getf.h>
#include <cisp/defclass.h>
#include <cisp/setf.h>


#define type CISP_DEFCLASS(a (setf b b) (setf c c) (setf d ~ ~ ~))

[[[
CISP_GETF(type, b) == b
CISP_GETF(type, c) == c
CISP_GETF(type, d) == ~ ~ ~

"" CISP_GETF(type, e) == ""
"" CISP_GETF(CISP_I_EMPTY_TYPE(), a) == ""
]]]
