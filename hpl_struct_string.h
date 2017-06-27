/*//
//  hpl_struct_string.h
//  hpl-v3
//
//  Created by Hector Denis on 29/04/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#ifndef hpl_struct_string_h
#define hpl_struct_string_h

#include <string.h>
#include "hpl_alloc.h"

typedef struct String String;
struct String {
    char* str;
    size_t cur;
    size_t wri;
    size_t max;
    /* len_wri and max should not be changed. */
};

/*
 Version: 1.0.0
 Changes: None.
 Goal: Allocate memory for struct String, with error check.
 Params: #1 length: requested string length.
 Modif: None.
 Return: NULL if fail, pointer to struct String on success.
 Comment:
 */
String* hpl_StringAlloc(size_t length);

/*
 Version: 1.0.1
 Changes: 1.0.1: Added set str->str to NULL;
 Goal: Free memory allocated for struct String.
 Params: #1 str: string to free.
 Modif: str becomes invalid, and is freed.
 Return: -1 if params null, 1 on success.
 Comment: str is not null after the function, because we only make a copy of the pointer.
 */
int hpl_StringFree(String* str);

/*
 Version: 1.0.0
 Changes: None.
 Goal: Print struct String's string and some info.
 Params: #1 str: string and its info.
         #2 stream: where to print
 Modif: stream status, and updates len_wri to print a correct value.
 Return: -1 if params null, 1 on success.
 Comment: Updates String's len_wri(table)
 */
int hpl_StringPrintInfo(String* str, FILE *stream);

#endif /* hpl_struct_string_h */
