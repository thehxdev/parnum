/*
 * Parnum (Parse Number) C library.
 * Author: thehxdev
 */

#include <stdlib.h>
#include <string.h>
#include "parnum.h"


#if !defined(true)
# define true  (1)
#endif /* true */

#if !defined(false)
# define false (0)
#endif /* false */


static int __is_ascii_num(char c) {
    return (c >= '0' && c <= '9') ? true : false;
}


/* for lookahead and lookbehined functionalities while parsing */
static char __string_getchar(const char *s, size_t idx) {
    if (s == NULL)
        return '\0';
    size_t s_len = strlen(s);
    return (idx >= s_len) ? '\0' : s[idx];
}


char *__strdup(const char *s) {
    if (s == NULL)
        return NULL;

    size_t s_len = strlen(s);
    char *new = (char*) malloc((s_len + 1) * sizeof(char));
    if (new == NULL)
        return NULL;

    strcpy(new, s);
    return new;
}


static char *__substring(char *s, const size_t left, const size_t right) {
    if (s == NULL)
        return NULL;

    if (right <= left)
        return NULL;

    s += left;
    /* if the right-most index is out of range or
     * it's equal to 0, don't apply it */
    if (right != 0 || right < strlen(s))
        s[right] = '\0';

    return s;
}


int parnum_parse_int(const char *s) {
    int num;
    char *tmp = (char*) strdup(s);
    int is_signed = false, left, right = 0;

    for (left = 0; tmp[left]; left++) {
        if (__is_ascii_num(tmp[left])) {
            is_signed = (__string_getchar(tmp, left - 1) == '-');
            for (right = left + 1;
                __is_ascii_num(__string_getchar(tmp, right));
                right++);
            break;
        }
    }

    /* if all characters checked an the left pointer 
     * reached to the last null terminator character,
     * means the string `s` does not contain any valid
     * integer value, so return 0 */
    if (tmp[left] == '\0') {
        free(tmp);
        return 0;
    }

    num = atoi(__substring(tmp, left, right));
    if (is_signed)
        num *= -1;

    free(tmp);
    return num;
}


double parnum_parse_float(const char *s) {
    double num;
    char *tmp = strdup(s);
    int is_signed = false, met_fpoint = false, left, right = 0;

    for (left = 0; tmp[left]; left++) {
        if (__is_ascii_num(tmp[left])) {
            is_signed = (__string_getchar(tmp, left - 1) == '-');

            right = left + 1;
            while (tmp[right]) {
                if (__is_ascii_num(__string_getchar(tmp, right))) {
                    right++;
                } else if (
                    (__string_getchar(tmp, right) == '.')
                    && (__is_ascii_num(__string_getchar(tmp, right+1)))
                    && (!met_fpoint)
                ) {
                    met_fpoint = true;
                    right++;
                } else {
                    break;
                }
            }

            break;
        }
    }

    /* if all characters checked an the left pointer 
     * reached to the last null terminator character,
     * means the string `s` does not contain any valid
     * float value, so return 0 */
    if (tmp[left] == '\0') {
        free(tmp);
        return 0.0;
    }

    num = atof(__substring(tmp, left, right));
    if (is_signed)
        num *= -1;

    free(tmp);
    return num;
}
