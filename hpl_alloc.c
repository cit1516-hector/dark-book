/*//
//  hpl_alloc.c
//  hpl-v3
//
//  Created by Hector Denis on 28/04/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#include "hpl_alloc.h"

void* hpl_Malloc(size_t size) {
    void* new_ptr = NULL;
    if (size <= 0) {
        fprintf(stderr, "warning: (malloc of %zu bytes).\n", size);
        return NULL;
    }
    new_ptr = malloc(size);
    if (NULL == new_ptr) {
        fprintf(stderr, "fatal: memory exhausted (malloc of %zu bytes).\n", size);
        return NULL;
    }
    return new_ptr;
}

int hpl_FreeNull(void** p) {
    if (NULL == p) {
        return -1;
    }
    free(*p);
    *p = NULL;
    return 1;
}
