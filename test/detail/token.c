/**
 * This file contains unit tests for the manipulation of token strings.
 */

#include <cisp/detail/token.h>


#define CISP_TOKEN_token (t o k e n)

[[[
CISP_I_TOKEN(token) == (t o k e n)
CISP_I_TOKEN_TO_STRING(token) == t o k e n
CISP_I_IS_VALID_TOKEN(token) == 1
CISP_I_IS_VALID_TOKEN(nontoken) == 0
]]]

[[[
/* should work with invalid tokens */
CISP_I_TOKEN_STRING_CONS(CISP_I_TOKEN_STRING_NIL(), nontoken) == nontoken
CISP_I_TOKEN_STRING_CONS(nontoken, nontoken) == nontoken nontoken
/* should work with valid tokens */
CISP_I_TOKEN_STRING_CONS(token, token) == token token
CISP_I_TOKEN_STRING_CONS(token, nontoken) == nontoken token
/* should work with non C identifiers */
CISP_I_TOKEN_STRING_CONS(~, nontoken) == nontoken ~
CISP_I_TOKEN_STRING_CONS(nontoken, ~) == ~ nontoken
]]]

[[[
/* the fact that bar is not a valid token should not matter */
CISP_I_TOKEN_STRING_HEAD(token nontoken) == token
/* should return only token because the tail of the string is empty */
CISP_I_TOKEN_STRING_HEAD(token) == token
/* should work even when the tail is a valid token */
CISP_I_TOKEN_STRING_HEAD(token token) == token
/* should work even when the tail is not a valid C identitifer */
CISP_I_TOKEN_STRING_HEAD(token ~ ~ ~) == token
]]]

[[[
/* since the string is nil, it should not remove anything and yield nil */
CISP_I_TOKEN_STRING_TAIL(CISP_I_TOKEN_STRING_NIL()) == CISP_I_TOKEN_STRING_NIL()
/* should remove the only token and yield nil */
CISP_I_TOKEN_STRING_TAIL(token) == CISP_I_TOKEN_STRING_NIL()
/* should strip the head only and yield the rest of the tokens */
CISP_I_TOKEN_STRING_TAIL(token token) == token
CISP_I_TOKEN_STRING_TAIL(token token token) == token token
/* only the first token should be required to be a valid token */
CISP_I_TOKEN_STRING_TAIL(token nontoken) == nontoken
CISP_I_TOKEN_STRING_TAIL(token nontoken nontoken) == nontoken nontoken
/* Since the second token, if present, is required to be a valid C identifier,
 * CISP_I_TOKEN_STRING_TAIL(token ~)
 * triggers an error.
 */
]]]

[[[
/* only a nil string should trigger an error */
CISP_I_TOKEN_STRING_TAIL_CHECK(token) == CISP_I_TOKEN_STRING_NIL()
CISP_I_TOKEN_STRING_TAIL_CHECK(token token) == token
CISP_I_TOKEN_STRING_TAIL_CHECK(token token token) == token token
CISP_I_TOKEN_STRING_TAIL_CHECK(token token nontoken nontoken) == token nontoken nontoken
]]]

[[[
/* since the string is nil, it should not remove anything and yield nil */
CISP_I_TOKEN_STRING_TAIL_UNSAFE(CISP_I_TOKEN_STRING_NIL()) == CISP_I_TOKEN_STRING_NIL()
/* should strip the head only and yield the rest of the tokens */
CISP_I_TOKEN_STRING_TAIL_UNSAFE(token token) == token
CISP_I_TOKEN_STRING_TAIL_UNSAFE(token token token) == token token
/* only the first token should be required to be a valid token */
CISP_I_TOKEN_STRING_TAIL_UNSAFE(token nontoken) == nontoken
CISP_I_TOKEN_STRING_TAIL_UNSAFE(token nontoken nontoken) == nontoken nontoken
/* the tail of the string should not be required to be valid identifiers */
CISP_I_TOKEN_STRING_TAIL_UNSAFE(token ~ ~ ~) == ~ ~ ~
/* With the _UNSAFE version, the string is required not to have exactly 1
 * token, and this triggers an error if empty macro arguments is not supported:
 * CISP_I_TOKEN_STRING_TAIL_UNSAFE(token)
 */
]]]

[[[
CISP_I_TOKEN_STRING_IS_CONS(CISP_I_TOKEN_STRING_NIL()) == 0
CISP_I_TOKEN_STRING_IS_CONS(token) == 1
CISP_I_TOKEN_STRING_IS_CONS(token token) == 1
CISP_I_TOKEN_STRING_IS_CONS(nontoken) == 1
CISP_I_TOKEN_STRING_IS_CONS(~~~) == 1
CISP_I_TOKEN_STRING_IS_CONS() == 0
]]]

[[[
CISP_I_TOKEN_STRING_TO_SEQ(token) == (token)
CISP_I_TOKEN_STRING_TO_SEQ(token token) == (token) (token)
CISP_I_TOKEN_STRING_TO_SEQ(CISP_I_TOKEN_STRING_NIL()) == CHAOS_PP_SEQ_NIL()
]]]
