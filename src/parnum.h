/*
 * Parnum (Parse Number) C library.
 * Author: thehxdev
 */

#ifndef PARNAM_H
#define PARNAM_H


#define PARNAM_VERSION "0.1.0"

#if !defined(_GNU_SOURCE) \
    || !defined(__USE_XOPEN_EXTENDED) \
    || _XOPEN_SOURCE < 500 \
    || _POSIX_C_SOURCE < 200809L
char *__strdup(const char *s);
# define strdup __strdup
#endif /* __strdup */


/* Parse a single integer value from a string.
 * It searches in the string to find a valid integer */
int parnum_parse_int(const char *s);

#endif /* PARNAM_H */
