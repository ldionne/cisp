/**
 * Macros to manipulate types, i.e. sequences of fields.
 */

#ifndef CISP_DETAIL_TYPE_H
#define CISP_DETAIL_TYPE_H

#include <chaos/preprocessor/seq/core.h>


/**
 * Create an empty sequence of fields.
 */
#define CISP_I_EMPTY_TYPE() CHAOS_PP_SEQ_NIL()

/****************************************************************************/

#include <cisp/detail/field.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/core.h>


/**
 * Set a new field without checking whether there already exists a field
 * with the same key.
 */
#define CISP_I_SET_FIELD_NO_UPDATE(type, field) \
    CISP_I_SET_FIELD_NO_UPDATE_S(CHAOS_PP_STATE(), type, field)

#define CISP_I_SET_FIELD_NO_UPDATE_S(s, type, field) \
    CHAOS_PP_SEQ_CONS(type, field)

/****************************************************************************/

#include <cisp/detail/field.h>

#include <chaos/preprocessor/control/iif.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/core.h>


/**
 * Set a field. If there already exists fields with the same key, update the
 * first of them to be associated with the new value.
 */
#define CISP_I_SET_FIELD_UPDATE_FIRST(type, field) \
    CISP_I_SET_FIELD_UPDATE_FIRST_S(CHAOS_PP_STATE(), type, field)

#define CISP_I_SET_FIELD_UPDATE_FIRST_S(s, type, field)                        \
    CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_CONS(type)) (                                 \
                                                                               \
        CHAOS_PP_EXPR_S(s)(                                                    \
            CISP_II_SET_FIELD_UPDATE_FIRST(                                    \
                CHAOS_PP_OBSTRUCT(),                                           \
                CHAOS_PP_NEXT(s),                                              \
                CHAOS_PP_SEQ_HEAD(type),                                       \
                CHAOS_PP_SEQ_TAIL(type),                                       \
                field)),                                                       \
                                                                               \
        CHAOS_PP_SEQ_CONS(                                                     \
            CHAOS_PP_SEQ_NIL(),                                                \
            field))                                                            \
/**/

/* Perform a linear search on the sequence of fields. When we find the field,
 * we replace it and stop. If we don't find it, we append the new field to
 * the sequence.
 * Precondition: head is a valid field.
 */
#define CISP_II_SET_FIELD_UPDATE_FIRST(_, s, head, tail, field)                \
    CHAOS_PP_IIF _(CISP_FIELD_COMPARE_KEYS_S _(s, head, field)) (              \
        /* If we have found the field, replace it and stop. */                 \
        CHAOS_PP_SEQ_CONS _(tail, field),                                      \
                                                                               \
        CHAOS_PP_IIF _(CHAOS_PP_SEQ_IS_NIL _(tail)) (                          \
            /* If this is the end of the sequence, append the new field. */    \
            CHAOS_PP_SEQ_CONS _(                                               \
                CHAOS_PP_SEQ_CONS _(                                           \
                    CHAOS_PP_SEQ_NIL(),                                        \
                    field),                                                    \
                head),                                                         \
            /* Otherwise, call ourselves on the tail, recursively. */          \
            CHAOS_PP_SEQ_CONS _(                                               \
                CHAOS_PP_EXPR_S _(s)(CISP_II_SET_FIELD_UPDATE_FIRST_ID _()(    \
                    CHAOS_PP_OBSTRUCT _(),                                     \
                    CHAOS_PP_NEXT(s),                                          \
                    CHAOS_PP_SEQ_HEAD _(tail),                                 \
                    CHAOS_PP_SEQ_TAIL _(tail),                                 \
                    field)),                                                   \
                head)))                                                        \
/**/

#define CISP_II_SET_FIELD_UPDATE_FIRST_ID() CISP_II_SET_FIELD_UPDATE_FIRST

/****************************************************************************/

#include <cisp/detail/field.h>

#include <chaos/preprocessor/control/iif.h>
#include <chaos/preprocessor/logical/compl.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/core.h>
#include <chaos/preprocessor/seq/filter.h>


/**
 * Set a field. If there already exists a field with the same key, the type is
 * updated so the key appears only once and is associated with the new value.
 */
#define CISP_I_SET_FIELD_UPDATE_ALL(type, field) \
    CISP_I_SET_FIELD_UPDATE_ALL_S(CHAOS_PP_STATE(), type, field)

#define CISP_I_SET_FIELD_UPDATE_ALL_S(s, type, field)                          \
    CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_CONS(type)) (                                 \
                                                                               \
        CHAOS_PP_EXPR_S(s)(                                                    \
            CISP_II_SET_FIELD_UPDATE_ALL(                                      \
                CHAOS_PP_OBSTRUCT(),                                           \
                CHAOS_PP_NEXT(s),                                              \
                CHAOS_PP_SEQ_HEAD(type),                                       \
                CHAOS_PP_SEQ_TAIL(type),                                       \
                field)),                                                       \
                                                                               \
        CHAOS_PP_SEQ_CONS(                                                     \
            CHAOS_PP_SEQ_NIL(),                                                \
            field))                                                            \
/**/

/* Perform a linear search on the sequence of fields. When we find the field,
 * we replace it and remove any subsequent field with the same key. If we
 * don't find it, we prepend the new field to the sequence.
 * Precondition: head is a valid field.
 */
#define CISP_II_SET_FIELD_UPDATE_ALL(_, s, head, tail, field)                  \
    CHAOS_PP_IIF _(CISP_FIELD_COMPARE_KEYS_S _(s, head, field)) (              \
        /* If we have found the field, replace it and erase any     */         \
        /* subsequent field with the same key.                      */         \
        CHAOS_PP_SEQ_CONS _(                                                   \
            CHAOS_PP_IIF _(CHAOS_PP_SEQ_IS_NIL _(tail)) (                      \
                CHAOS_PP_SEQ_NIL(),                                            \
                CHAOS_PP_EXPR_S _(s)(                                          \
                    CHAOS_PP_SEQ_FILTER_S _(                                   \
                        CHAOS_PP_NEXT(s),                                      \
                        CISP_II_SFU_ALL_CONTINUE_PRED,                         \
                        tail,                                                  \
                        field))),                                              \
            field),                                                            \
                                                                               \
        CHAOS_PP_IIF _(CHAOS_PP_SEQ_IS_NIL _(tail)) (                          \
            /* If this is the end of the sequence, append the new field. */    \
            CHAOS_PP_SEQ_CONS _(                                               \
                CHAOS_PP_SEQ_CONS _(                                           \
                    CHAOS_PP_SEQ_NIL(),                                        \
                    field),                                                    \
                head),                                                         \
            /* Otherwise, call ourselves on the tail to continue. */           \
            CHAOS_PP_SEQ_CONS _(                                               \
                CHAOS_PP_EXPR_S _(s)(                                          \
                    CISP_II_SET_FIELD_UPDATE_ALL_ID _()(                       \
                        CHAOS_PP_OBSTRUCT _(),                                 \
                        CHAOS_PP_NEXT(s),                                      \
                        CHAOS_PP_SEQ_HEAD _(tail),                             \
                        CHAOS_PP_SEQ_TAIL _(tail),                             \
                        field)),                                               \
                head)))                                                        \
/**/

#define CISP_II_SET_FIELD_UPDATE_ALL_ID() CISP_II_SET_FIELD_UPDATE_ALL

/*Return whether the field has a key different from that of the other field.*/
#define CISP_II_SFU_ALL_CONTINUE_PRED(s, field1, field2) \
    CHAOS_PP_COMPL(CISP_FIELD_COMPARE_KEYS_S(s, field1, field2))

/****************************************************************************/

#include <cisp/detail/field.h>

#include <chaos/preprocessor/control/iif.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/core.h>


/**
 * Remove the first field with a key equal to @p key. Nothing is done if
 * there is no such field in the type.
 */
#define CISP_I_REMOVE_FIRST_FIELD(type, key) \
    CISP_I_REMOVE_FIRST_FIELD_S(CHAOS_PP_STATE(), type, key)

#define CISP_I_REMOVE_FIRST_FIELD_S(s, type, key)                              \
    CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_CONS(type)) (                                 \
        CHAOS_PP_EXPR_S(s)(                                                    \
            CISP_II_REMOVE_FIRST_FIELD(                                        \
                CHAOS_PP_OBSTRUCT(),                                           \
                CHAOS_PP_NEXT(s),                                              \
                CHAOS_PP_SEQ_HEAD(type),                                       \
                CHAOS_PP_SEQ_TAIL(type),                                       \
                key)),                                                         \
                                                                               \
        CISP_I_EMPTY_TYPE())                                                   \
/**/

#define CISP_II_REMOVE_FIRST_FIELD(_, s, head, tail, key)                      \
    CHAOS_PP_IIF _(CISP_FIELD_COMPARE_KEY_OF_S _(s, head, key)) (              \
            /* If we have found the field, remove it and stop. */              \
            tail,                                                              \
                                                                               \
            CHAOS_PP_IIF _(CHAOS_PP_SEQ_IS_NIL _(tail)) (                      \
                /* If the tail is empty, keep the head and stop. */            \
                CHAOS_PP_SEQ_CONS _(CHAOS_PP_SEQ_NIL(), head),                 \
                                                                               \
                /* Otherwise, call ourselves on the tail to continue. */       \
                CHAOS_PP_SEQ_CONS _(                                           \
                    CHAOS_PP_EXPR_S _(s)(                                      \
                        CISP_II_REMOVE_FIRST_FIELD_ID _()(                     \
                            CHAOS_PP_OBSTRUCT _(),                             \
                            CHAOS_PP_NEXT(s),                                  \
                            CHAOS_PP_SEQ_HEAD _(tail),                         \
                            CHAOS_PP_SEQ_TAIL _(tail),                         \
                            key)),                                             \
                    head)))                                                    \
/**/

#define CISP_II_REMOVE_FIRST_FIELD_ID() CISP_II_REMOVE_FIRST_FIELD

/****************************************************************************/

#include <cisp/detail/field.h>

#include <chaos/preprocessor/control/iif.h>
#include <chaos/preprocessor/facilities/empty.h>
#include <chaos/preprocessor/logical/compl.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/core.h>
#include <chaos/preprocessor/seq/filter.h>


/**
 * Remove all fields whose key is @p key.
 */
#define CISP_I_REMOVE_ALL_FIELDS(type, key) \
    CISP_I_REMOVE_ALL_FIELDS_S(CHAOS_PP_STATE(), type, key)

#define CISP_I_REMOVE_ALL_FIELDS_S(s, type, key)                               \
    CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_NIL(type)) (                                  \
        CISP_I_EMPTY_TYPE(),                                                   \
                                                                               \
        CISP_II_REMOVE_ALL_FIELDS(                                             \
            CHAOS_PP_EXPR_S(s)(                                                \
                /* this hack is to avoid having an empty macro argument */     \
                () CHAOS_PP_SEQ_FILTER_S(                                      \
                    CHAOS_PP_NEXT(s),                                          \
                    CISP_I_REMOVE_ALL_FIELDS_PRED,                             \
                    type,                                                      \
                    key))))                                                    \
/**/

#define CISP_I_REMOVE_ALL_FIELDS_PRED(s, field, key) \
    CHAOS_PP_COMPL(CISP_FIELD_COMPARE_KEY_OF_S(s, field, key))

/* Detect whether @p type is empty. We need to eat the leading parenthesis
 * that we introduced in `CISP_I_REMOVE_ALL_FIELDS` to avoid having an empty
 * macro argument, which is invalid in C89.
 */
#define CISP_II_REMOVE_ALL_FIELDS(type)                                        \
    CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_NIL(CHAOS_PP_EMPTY type)) (                   \
        CISP_I_EMPTY_TYPE(),                                                   \
        CHAOS_PP_EMPTY type)                                                   \
/**/

#endif /* !CISP_DETAIL_TYPE_H */
