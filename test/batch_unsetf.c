/**
 * This file contains unit tests for the `BATCH_UNSETF` family of macros.
 */

#include <cisp/batch_unsetf.h>
#include <cisp/defclass.h>
#include <cisp/setf.h>


#define type CISP_DEFCLASS((setf a a) (setf b b) (setf c ~ ~ ~))

[[[
CISP_BATCH_UNSETF(type, a b c) == CISP_I_EMPTY_TYPE()
CISP_BATCH_UNSETF(CISP_I_EMPTY_TYPE(), a b c) == CISP_I_EMPTY_TYPE()
CISP_BATCH_UNSETF(type, CISP_I_TOKEN_STRING_NIL()) == type
CISP_BATCH_UNSETF(CISP_I_EMPTY_TYPE(), CISP_I_TOKEN_STRING_NIL()) == CISP_I_EMPTY_TYPE()
CISP_BATCH_UNSETF(type, a b) == CISP_DEFCLASS((setf c ~ ~ ~))
CISP_BATCH_UNSETF(type, a a) == CISP_BATCH_UNSETF(type, a)
]]]
