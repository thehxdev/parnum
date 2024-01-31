#include <stdio.h>
#include <assert.h>
#include "parnum.h"

void test_single_integers();
void test_single_floats();


int main(void) {
    test_single_integers();
    test_single_floats();
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
    assert(0 == parnum_parse_int("Hello World!"));

    printf("[PASSED]!\n");
}

void test_single_floats() {
    printf("Testing single float values... ");

    assert(12.12 == parnum_parse_float("Hello 12.12"));
    assert(81.345 == parnum_parse_float("81.345"));
    assert(35.0 == parnum_parse_float("this is a t35.0t"));
    assert(-10.9 == parnum_parse_float("-10.9"));
    assert(-841.34 == parnum_parse_float("negati-841.34ve"));
    assert(-3.14 == parnum_parse_float("(-PI) = -3.14"));
    assert(-153.21 == parnum_parse_float("-153.21.51.535"));
    assert(0.0 == parnum_parse_float("Hello World!"));

    printf("[PASSED]!\n");
}
