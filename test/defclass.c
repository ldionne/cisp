/**
 * This file contains unit tests for the creation of types.
 */

#include <cisp/defclass.h>


#define CISP_TOKEN_name (n a m e)

#define CISP_TOKEN_nothing (n o t h i n g)
#define CISP_INSTRUCTION_nothing(s, type, args) type

#define CISP_TOKEN_print (p r i n t)
#define CISP_INSTRUCTION_print(s, type, x) type (x)

[[[
/* works without argument */
CISP_DEFCLASS(name (nothing)) == CISP_I_EMPTY_TYPE()
/* and with argument */
CISP_DEFCLASS(name (nothing ~~~~)) == CISP_I_EMPTY_TYPE()
/* make sure instructions can modify the type and that modifications are in order */
CISP_DEFCLASS(name (print 1) (print 2) (print 3)) == CISP_I_EMPTY_TYPE() (1) (2) (3)
]]]
