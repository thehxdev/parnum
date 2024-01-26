/*
 * Parnum (Parse Number) C library.
 * Author: thehxdev
 */

#include <stdlib.h>
#include <string.h>
#include "parnum.h"


#if !defined(true) && !defined (false)
# define true  (1)
# define false (0)
#endif /* true & false */


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


const char *__strdup(const char *s) {
    if (s == NULL)
        return NULL;

    size_t s_len = strlen(s);
    char *new = (char*) calloc(s_len + 1, sizeof(char));
    if (new == NULL)
        return NULL;

    strcpy(new, s);
    return new;
}


static char *__substring(char *s, size_t left, size_t right) {
    if (s == NULL)
        return NULL;

    if (right <= left)
        return NULL;

    size_t last_idx = strlen(s) - 1;
    /* if the right-most index is out of range or
     * it's equal to 0, re-define it as last index. */
    if (right > last_idx || right == 0)
        right = last_idx + 1;

    s += left;
    s[right] = '\0';

    return s;
}


int *parnum_parse_int(const char *s) {
    int *num;
    char *tmp = (char*) strdup(s);
    int is_signed = 0, left, right;

    for (left = 0; tmp[left]; left++) {
        if (__is_ascii_num(tmp[left])) {
            is_signed = (__string_getchar(tmp, left - 1) == '-') ? 1 : 0;
            for (right = left + 1;
                __is_ascii_num(__string_getchar(tmp, right));
                right++);
            break;
        }
    }

    /* if all characters checked an the left pointer 
     * reached to the last null terminator character,
     * means the string `s` does not contain any valid
     * integer value, so return NULL */
    if (tmp[left] == '\0')
        return NULL;

    num = malloc(sizeof(int));
    *num = atoi(__substring(tmp, left, right));

    if (is_signed)
        (*num) *= -1;

    free(tmp);
    return num;
}
