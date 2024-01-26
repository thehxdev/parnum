#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "parnum.h"

void test_single_integers();


int main(void) {
    test_single_integers();
    return 0;
}


void test_single_integers() {
    printf("Testing single integer values... ");

    assert(12 == parnum_parse_int("Hello 12"));
    assert(81 == parnum_parse_int("81"));
    assert(35 == parnum_parse_int("this is a t35t"));
    assert(94123 == parnum_parse_int("Oh 94123 My 60d"));
    assert(-10 == parnum_parse_int("-10"));
    assert(-841 == parnum_parse_int("negati-841ve"));
    assert(0 == (parnum_parse_int("Hello World!")));

    printf("[PASSED]!\n");
}
