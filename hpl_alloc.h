/*//
//  hpl_alloc.h
//  hpl-v3
//
//  Created by Hector Denis on 28/04/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#ifndef hpl_alloc_h
#define hpl_alloc_h

#include <stdio.h>
#include <stdlib.h>

/*
 Version: 1.0.0
 Changes: None.
 Goal: Allocate memory, with error handling.
 Params: #1 size: size to allocate.
 Modif: None.
 Return: NULL if size less than zero or malloc error, otherwise ptr.
 Comment: None.
 */
void* hpl_Malloc(size_t size);

/*
 Version: 1.0.0
 Changes: None.
 Goal: Free memory.
 Params: #1 p: adress of pointer.
 Modif: Frees the pointer then set it to NULL.
 Return: -1 if p is NULL, 1 if success.
 Comment: We dont care if *p is NULL, as free is gentle, and we can dereference p happily.
 */
int hpl_FreeNull(void** p);

#endif /* hpl_alloc_h */
