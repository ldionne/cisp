/**
 * Macros to manipulate strings of tokens and preprocessor strings.
 *
 * @note This is strongly inspired by the Chaos preprocessor library. The
 *       reason I don't use their string/core operations is that I needed to
 *       be able to define tokens using the CISP_TOKEN_ construct.
 */

#ifndef CISP_DETAIL_TOKEN_H
#define CISP_DETAIL_TOKEN_H

#include <chaos/preprocessor/cat.h>
#include <chaos/preprocessor/detection/is_nullary.h>
#include <chaos/preprocessor/facilities/expand.h>
#include <chaos/preprocessor/facilities/unbox.h>


/**
 * Given a token, return a representation containing its preprocessor string
 * representation as well as parenthesis necessary to make it a valid
 * preprocessor string character.
 *
 * @note In order for this macro to work properly, the CISP_TOKEN_token
 *       macro must be defined to expand to the preprocessor string version
 *       of the token inside parenthesis.
 */
#define CISP_I_TOKEN(token) CHAOS_PP_CAT(CISP_TOKEN_, token)

#define CISP_I_TOKEN_TO_STRING(token) CHAOS_PP_UNBOX(CISP_I_TOKEN(token))

/**
 * Represents an empty token string.
 */
#define CISP_I_TOKEN_STRING_NIL() ()

/**
 * Return whether a token is a valid token. The token has to be at least
 * a valid C identifier.
 */
#define CISP_I_IS_VALID_TOKEN(token)                                           \
    CHAOS_PP_IS_NULLARY(                                                       \
        CHAOS_PP_EXPAND(                                                       \
            CISP_II_IS_VALID_TOKEN CISP_I_TOKEN(token)))                       \
/**/

#define CISP_II_IS_VALID_TOKEN(x) ()

/****************************************************************************/

#include <chaos/preprocessor/algorithm/size.h>
#include <chaos/preprocessor/cat.h>
#include <chaos/preprocessor/control/iif.h>
#include <chaos/preprocessor/control/inline_when.h>
#include <chaos/preprocessor/facilities/empty.h>
#include <chaos/preprocessor/facilities/expand.h>
#include <chaos/preprocessor/facilities/split.h>
#include <chaos/preprocessor/string/core.h>
#include <joy/cat.h>
#include <joy/string/to_tuple.h>


/**
 * Add a token to the beginning of a token string. Both the string and the
 * added token may be arbitrary data, excluding empty parenthesis.
 */
#define CISP_I_TOKEN_STRING_CONS(string, x)                                    \
    x CHAOS_PP_INLINE_WHEN(CISP_I_TOKEN_STRING_IS_NIL(string)) (               \
        CHAOS_PP_EMPTY                                                         \
    ) string                                                                   \
/**/

/**
 * Return the first token of a token string. The first token must be a valid
 * token, but the tail of the string may be arbitrary data.
 */
#define CISP_I_TOKEN_STRING_HEAD(string)                                       \
    CISP_I_TOKEN_STRING_HEAD_CONCAT(                                           \
        CISP_I_TOKEN_STRING_HEAD_EXTRACT_PP_STRING(string))                    \
/**/

#define CISP_I_TOKEN_STRING_HEAD_CONCAT(string)                                \
    CISP_I_TOKEN_STRING_HEAD_CONCAT_N(                                         \
        string,                                                                \
        CHAOS_PP_SIZE((CHAOS_PP_STRING) string))                               \
/**/

#define CISP_I_TOKEN_STRING_HEAD_CONCAT_N(string, length)                      \
    CHAOS_PP_EXPAND(                                                           \
        CHAOS_PP_CAT(JOY_CAT_NOEXP, length) JOY_STRING_TO_TUPLE(string))       \
/**/

#define CISP_I_TOKEN_STRING_HEAD_EXTRACT_PP_STRING(string)                     \
    CHAOS_PP_IIF(CISP_I_TOKEN_STRING_IS_NIL(string)) (                         \
        CISP_I_TOKEN_STRING_NIL_INPUT_EXCEPTION(!),                            \
                                                                               \
        CHAOS_PP_SPLIT(0,                                                      \
            CHAOS_PP_EXPAND(                                                   \
                CISP_I_TOKEN_STRING_HEAD_EXTRACT_PP_STRING_SPLIT               \
                    CHAOS_PP_PRIMITIVE_CAT(CISP_TOKEN_, string))))             \
/**/
#define CISP_I_TOKEN_STRING_HEAD_EXTRACT_PP_STRING_SPLIT(x) x, ~

/****************************************************************************/

#include <chaos/preprocessor/cat.h>
#include <chaos/preprocessor/control/iif.h>
#include <chaos/preprocessor/control/inline_unless.h>
#include <chaos/preprocessor/detection/is_empty.h>
#include <chaos/preprocessor/facilities/empty.h>
#include <chaos/preprocessor/facilities/expand.h>
#include <chaos/preprocessor/facilities/split.h>


/**
 * Return the string with its head removed. If the string is nil or if it
 * only has one token in it, `CISP_I_TOKEN_STRING_NIL()` is returned. If the
 * string has length 2 or more, the first and the second token must be valid
 * tokens.
 */
#define CISP_I_TOKEN_STRING_TAIL(string)                                       \
    CHAOS_PP_IIF(CISP_I_TOKEN_STRING_IS_NIL(string)) (                         \
        CISP_I_TOKEN_STRING_NIL(),                                             \
                                                                               \
        CISP_III_TOKEN_STRING_TAIL(                                            \
            CHAOS_PP_SPLIT(1,                                                  \
                CHAOS_PP_EXPAND(                                               \
                    CISP_II_TOKEN_STRING_TAIL                                  \
                    CHAOS_PP_PRIMITIVE_CAT(CISP_TOKEN_, string)))))            \
/**/

#define CISP_II_TOKEN_STRING_TAIL(x) x, ()

#define CISP_III_TOKEN_STRING_TAIL(r)                                          \
    CHAOS_PP_INLINE_UNLESS(CHAOS_PP_IS_EMPTY(CHAOS_PP_EMPTY r))(               \
        CHAOS_PP_EMPTY                                                         \
    ) r                                                                        \
/**/

/**
 * Return the string with its head removed. If the input is nil, a
 * preprocessor error is triggered. Otherwise, it is the same as
 * calling `CISP_I_TOKEN_STRING_TAIL`.
 */
#define CISP_I_TOKEN_STRING_TAIL_CHECK(string)                                 \
    CHAOS_PP_IIF(CISP_I_TOKEN_STRING_IS_NIL(string)) (                         \
        CISP_I_TOKEN_STRING_NIL_INPUT_EXCEPTION(!),                            \
        CISP_I_TOKEN_STRING_TAIL(string))                                      \
/**/

/**
 * Return the string with its head removed.
 *
 * The difference between this and @em `CISP_I_TOKEN_STRING_TAIL()` is that this
 * macro will trigger an error if the string has a length of exactly 1 token
 * and empty macro arguments is not supported. However, it does not require
 * the tail of the string to be a valid tokens or even C identifiers.
 */
#define CISP_I_TOKEN_STRING_TAIL_UNSAFE(string)                                \
    CHAOS_PP_IIF(CISP_I_TOKEN_STRING_IS_NIL(string)) (                         \
        CISP_I_TOKEN_STRING_NIL(),                                             \
                                                                               \
        CHAOS_PP_SPLIT(1,                                                      \
            CHAOS_PP_EXPAND(                                                   \
                CISP_II_TOKEN_STRING_TAIL_UNSAFE                               \
                CHAOS_PP_PRIMITIVE_CAT(CISP_TOKEN_, string))))                 \
/**/

#define CISP_II_TOKEN_STRING_TAIL_UNSAFE(x) x,

/****************************************************************************/

#include <chaos/preprocessor/detection/is_nullary.h>
#include <chaos/preprocessor/logical/compl.h>


/**
 * Return whether a token string has tokens in it.
 */
#define CISP_I_TOKEN_STRING_IS_CONS(string) \
    CHAOS_PP_COMPL(CISP_I_TOKEN_STRING_IS_NIL(string))

/**
 * Return whether a token string is empty.
 */
#define CISP_I_TOKEN_STRING_IS_NIL(string) CHAOS_PP_IS_NULLARY(string())

/****************************************************************************/

#include <chaos/preprocessor/control/iif.h>
#include <chaos/preprocessor/control/inline_unless.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/seq/core.h>


/**
 * Convert a token string into a sequence of tokens.
 */
#define CISP_I_TOKEN_STRING_TO_SEQ(string) \
    CISP_I_TOKEN_STRING_TO_SEQ_S(CHAOS_PP_STATE(), string)

#define CISP_I_TOKEN_STRING_TO_SEQ_S(s, string)                                \
    CHAOS_PP_IIF(CISP_I_TOKEN_STRING_IS_NIL(string)) (                         \
        CHAOS_PP_SEQ_NIL(),                                                    \
                                                                               \
        CHAOS_PP_EXPR_S(s)(                                                    \
            CISP_II_TOKEN_STRING_TO_SEQ(                                       \
                CHAOS_PP_NEXT(s),                                              \
                string)))                                                      \
/**/

#define CISP_I_TOKEN_STRING_NIL_INPUT_EXCEPTION()

#define CISP_II_TOKEN_STRING_TO_SEQ_ID() CISP_II_TOKEN_STRING_TO_SEQ
#define CISP_II_TOKEN_STRING_TO_SEQ(s, string)                                 \
    (CISP_I_TOKEN_STRING_HEAD(string))                                         \
                                                                               \
    CISP_II_TOKEN_STRING_TO_SEQ_CONTINUE(                                      \
        CHAOS_PP_OBSTRUCT(),                                                   \
        s,                                                                     \
        /* It would be useless to use the _UNSAFE version here because */      \
        /* we need the next token to be valid anyway. */                       \
        CISP_I_TOKEN_STRING_TAIL(string))                                      \
/**/

#define CISP_II_TOKEN_STRING_TO_SEQ_CONTINUE(_, s, tail)                       \
    CHAOS_PP_INLINE_UNLESS(CISP_I_TOKEN_STRING_IS_NIL(tail)) _(                \
        CHAOS_PP_EXPR_S _(s)(                                                  \
            CISP_II_TOKEN_STRING_TO_SEQ_ID _()(                                \
                CHAOS_PP_NEXT(s),                                              \
                tail)))                                                        \
/**/

#endif /* !CISP_DETAIL_TOKEN_H */
