/**
 * This file contains unit tests for basic type functionalities.
 */

#include <cisp/detail/type.h>


[[[

/* should append field */
CISP_I_SET_FIELD_UPDATE_FIRST(CISP_I_EMPTY_TYPE(), CISP_FIELD(k e y, value)) == ((k e y, value))
/* should replace the only field */
CISP_I_SET_FIELD_UPDATE_FIRST(((k e y, value)), CISP_FIELD(k e y, new value)) == ((k e y, new value))
/* should replace first f o o field only */
CISP_I_SET_FIELD_UPDATE_FIRST(((f o o, foo)) ((b a r, bar)) ((f o o, foo)), CISP_FIELD(f o o, new foo)) == ((f o o, new foo)) ((b a r, bar)) ((f o o, foo))
/* should append the new field */
CISP_I_SET_FIELD_UPDATE_FIRST(((f o o, foo)) ((b a r, bar)), CISP_FIELD(b a z, baz)) == ((f o o, foo)) ((b a r, bar)) ((b a z, baz))

/* should append field */
CISP_I_SET_FIELD_UPDATE_ALL(CISP_I_EMPTY_TYPE(), CISP_FIELD(k e y, value)) == ((k e y, value))
/* should replace the only field */
CISP_I_SET_FIELD_UPDATE_ALL(((k e y, value)), CISP_FIELD(k e y, new value)) == ((k e y, new value))
/* should replace first f o o field and remove the other f o o fields */
CISP_I_SET_FIELD_UPDATE_ALL(((f o o, foo)) ((b a r, bar)) ((f o o, foo)), CISP_FIELD(f o o, new foo)) == ((f o o, new foo)) ((b a r, bar))
/* should append the new field */
CISP_I_SET_FIELD_UPDATE_ALL(((f o o, foo)) ((b a r, bar)), CISP_FIELD(b a z, baz)) == ((f o o, foo)) ((b a r, bar)) ((b a z, baz))

/* should not remove anything from the empty type and therefore yield the empty type */
CISP_I_REMOVE_FIRST_FIELD(CISP_I_EMPTY_TYPE(), k e y) == CISP_I_EMPTY_TYPE()
/* should not be able to find the field and therefore should not remove anything */
CISP_I_REMOVE_FIRST_FIELD(((f o o, foo)) ((b a r, bar)), i n e x i s t a n t  k e y) == ((f o o, foo)) ((b a r, bar))
/* should remove the only field and yield the empty type */
CISP_I_REMOVE_FIRST_FIELD(((f o o, foo)), f o o) == CISP_I_EMPTY_TYPE()
/* should remove only the first matching field */
CISP_I_REMOVE_FIRST_FIELD(((f o o, foo)) ((b a r, bar)) ((f o o, foo)), f o o) == ((b a r, bar)) ((f o o, foo))

/* should not remove anything from the empty type and therefore yield the empty type */
CISP_I_REMOVE_ALL_FIELDS(CISP_I_EMPTY_TYPE(), k e y) == CISP_I_EMPTY_TYPE()
/* should not be able to find the field and therefore should not remove anything */
CISP_I_REMOVE_ALL_FIELDS(((f o o, foo)) ((b a r, bar)), i n e x i s t a n t  k e y) == ((f o o, foo)) ((b a r, bar))
/* should remove the only field and yield the empty type */
CISP_I_REMOVE_ALL_FIELDS(((f o o, foo)), f o o) == CISP_I_EMPTY_TYPE()
/* should remove all matching fields */
CISP_I_REMOVE_ALL_FIELDS(((f o o, foo)) ((b a r, bar)) ((f o o, foo)), f o o) == ((b a r, bar))

]]]
