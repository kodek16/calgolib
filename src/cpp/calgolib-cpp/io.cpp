#include "io.hpp"

#include <stdio.h>

namespace algo {

//TODO add an error log if EOF was encoutered.
template <> void read<char *>(char *dest) {

    while( (*dest = getchar()) != EOF ) {
        if (*dest != '\n') {
            return;
        }
    }
}

//TODO add EOF logs
//Note: this function keeps reading digits ignoring int overflow. Not sure if this is the best behaviour.
template <> void read<int *>(int *dest) {

    *dest = 0;
    int sign = 1;

    //Skip whitespaces

    int spaceChar = getchar();
    while (spaceChar == ' ' || spaceChar == '\n' || spaceChar == '\t') {
        spaceChar = getchar();
    }

    if (spaceChar == EOF) {
        return;
    } else {
        ungetc(spaceChar, stdin);
    }

    //Read sign

    int signChar = getchar();
    if (signChar == EOF) {
        return;
    } else if (signChar == '-') {
        sign = -1;
    } else {
        ungetc(signChar, stdin);
    }

    //Read digits

    int digitChar = getchar();
    if (digitChar == EOF) {
        return;
    }
    if (digitChar < '0' || digitChar > '9') {
        return; //TODO add error log here.
    }

    while (digitChar != EOF && digitChar >= '0' && digitChar <= '9') {
        *dest *= 10;
        *dest += digitChar - '0';
        digitChar = getchar();
    }

    *dest *= sign;

}

}
