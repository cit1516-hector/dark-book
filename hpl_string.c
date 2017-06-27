/*//
//  hpl_string.c
//  hpl-v3
//
//  Created by Hector Denis on 29/04/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#include "hpl_string.h"

int hpl_StrUpper(char* str) {
    size_t i = 0;
    if (NULL == str) {
        return -1;
    }
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = (char) toupper(str[i]);
    }
    return 1;
}

int hpl_StrLower(char* str) {
    size_t i = 0;
    if (NULL == str) {
        return -1;
    }
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = (char)tolower(str[i]);
    }
    return 1;
}

int hpl_StrClear(char* str, size_t len) {
    size_t i = 0;
    if (NULL == str) {
        return -1;
    }
    for (i = 0; i < len; i++) {
        str[i] = '\0';
    }
    return 1;
}
