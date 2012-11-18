/**
 * Internal configuration file to enable/disable features depending on the
 * platform.
 */

#ifndef CISP_DETAIL_CONFIG_H
#define CISP_DETAIL_CONFIG_H

/**
 * This flag is on whenever we are being compiled using the C99 dialect.
 */
#if !__cplusplus && __STDC_VERSION__ >= 199901L
#   define CISP_CONFIG_C99 1
#else
#   define CISP_CONFIG_C99 0
#endif

/**
 * This flag is on whenever we are being compiled using C++11.
 */
#if defined(__cplusplus) && __cplusplus >= 201103L
#   define CISP_CONFIG_CPP11 1
#else
#   define CISP_CONFIG_CPP11 0
#endif

/**
 * This flag is enabled when it is allowed to pass empty arguments to macros.
 */
#if CISP_CONFIG_C99 || CISP_CONFIG_CPP11
#   define CISP_CONFIG_EMPTY_MACRO_ARGS 1
#else
#   define CISP_CONFIG_EMPTY_MACRO_ARGS 0
#endif

/**
 * This flag is enabled when variadic macros are supported.
 */
#if CISP_CONFIG_C99 || CISP_CONFIG_CPP11
#   define CISP_CONFIG_VARIADIC_MACROS 1
#else
#   define CISP_CONFIG_VARIADIC_MACROS 0
#endif

/**
 * This flag determines whether shorter names are defined for the interface.
 * For example, `defclass` will be defined to `CISP_DEFCLASS` if this is
 * enabled. By default, this is enabled.
 */
#if !defined(CISP_CONFIG_GENERATE_SHORT_NAMES)
#   define CISP_CONFIG_GENERATE_SHORT_NAMES 1
#endif

#endif /* !CISP_DETAIL_CONFIG_H */
