/*//
//  hpl_struct_string.c
//  hpl-v3
//
//  Created by Hector Denis on 29/04/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#include "hpl_struct_string.h"
#include "hpl_alloc.h"

String* hpl_StringAlloc(size_t length) {
    String* str = hpl_Malloc(sizeof(*str));
    if (NULL == str) {
        return NULL;
    }
    
    str->str = hpl_Malloc(length * sizeof(*(str->str)));
    if (NULL == str->str) {
        hpl_StringFree(str);
        return NULL;
    }
    memset(str->str, 0, length);
    str->cur = 0;
    str->wri = length - 1;
    str->max = length;
    
    return str;
}

int hpl_StringFree(String* str) {
    if (NULL == str) {
        return -1;
    }
    free(str->str);
    str->str = NULL;
    free(str);
    return 1;
}

int hpl_StringPrintInfo(String* str, FILE *stream) {
    if (NULL == str || NULL == stream) {
        return -1;
    }
    str->cur = strlen(str->str);
    fprintf(stream, "%s\n", str->str);
    fprintf(stream, "%zu/", str->cur);
    fprintf(stream, "%zu:", str->wri);
    fprintf(stream, "%zu\n", str->max);
    return 1;
}
