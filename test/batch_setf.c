/**
 * This file contains unit tests for the `BATCH_SETF` family of macros.
 */

#include <cisp/batch_setf.h>
#include <cisp/defclass.h>
#include <cisp/setf.h>


#define type CISP_DEFCLASS(a (setf b b) (setf c c) (setf d ~ ~ ~))
#define new_type CISP_DEFCLASS(a (setf b new b) (setf c new c) (setf d new d))


[[[
CISP_BATCH_SETF(type, new_type) == new_type
CISP_BATCH_SETF(type, CISP_DEFCLASS(a (setf e e) (setf b new b))) == CISP_DEFCLASS(a (setf b new b) (setf c c) (setf d ~ ~ ~) (setf e e))
CISP_BATCH_SETF(type, CISP_I_EMPTY_TYPE()) == type
CISP_BATCH_SETF(CISP_I_EMPTY_TYPE(), type) == type

CISP_DEFCLASS(a (batch_setf type)) == type
]]]
