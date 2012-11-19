/**
 * This file contains unit tests for the `SETF` family of macros.
 */

#include <cisp/setf.h>
#include <cisp/defclass.h>


#define CISP_TOKEN_token (t o k e n)
#define CISP_TOKEN_other (o t h e r)

[[[
CISP_SETF(CISP_I_EMPTY_TYPE(), token, value) == (CISP_FIELD(t o k e n, value))
CISP_SETF(CISP_I_EMPTY_TYPE(), token, ~ ~ ~) == (CISP_FIELD(t o k e n, ~ ~ ~))
/* should replace the first existing field */
CISP_SETF((CISP_FIELD(t o k e n, value)), token, new value) == (CISP_FIELD(t o k e n, new value))
CISP_SETF((CISP_FIELD(t o k e n, value)) (CISP_FIELD(t o k e n, value)), token, new value) == (CISP_FIELD(t o k e n, new value)) (CISP_FIELD(t o k e n, value))
]]]

[[[
CISP_DEFCLASS((setf token value)) == (CISP_FIELD(t o k e n, value))
CISP_DEFCLASS((setf token ~ ~ ~)) == (CISP_FIELD(t o k e n, ~ ~ ~))
/* should be applied one after the other and therefore replace the existing field */
CISP_DEFCLASS((setf token value) (setf token new value)) == CISP_DEFCLASS((setf token new value))
/* should be applied in order */
CISP_DEFCLASS((setf token token) (setf other other)) == (CISP_FIELD(t o k e n, token)) (CISP_FIELD(o t h e r, other))
]]]
