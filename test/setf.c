/**
 * This file contains unit tests for the `SETF` family of macros.
 */

#include <cisp/setf.h>
#include <cisp/defclass.h>


#define CISP_TOKEN_token (t o k e n)
#define CISP_TOKEN_other (o t h e r)
#define CISP_TOKEN_name (n a m e)

[[[
CISP_SETF(CISP_I_EMPTY_TYPE(), token, value) == ((t o k e n, value))
CISP_SETF(CISP_I_EMPTY_TYPE(), token, ~ ~ ~) == ((t o k e n, ~ ~ ~))
/* should replace the first existing field */
CISP_SETF(((t o k e n, value)), token, new value) == ((t o k e n, new value))
CISP_SETF(((t o k e n, value)) ((t o k e n, value)), token, new value) == ((t o k e n, new value)) ((t o k e n, value))
]]]

[[[
CISP_DEFCLASS(name (setf token value)) == ((t o k e n, value))
CISP_DEFCLASS(name (setf token ~ ~ ~)) == ((t o k e n, ~ ~ ~))
/* should be applied one after the other and therefore replace the existing field */
CISP_DEFCLASS(name (setf token value) (setf token new value)) == CISP_DEFCLASS(name (setf token new value))
/* should be aplpied in order */
CISP_DEFCLASS(name (setf token token) (setf other other)) == ((t o k e n, token)) ((o t h e r, other))
]]]
