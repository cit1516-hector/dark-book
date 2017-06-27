/*//
//  hpl_string.h
//  hpl-v3
//
//  Created by Hector Denis on 29/04/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#ifndef hpl_string_h
#define hpl_string_h

#include <ctype.h>
/* toupper, tolower */

/*
 Version: 1.0.0
 Changes: None.
 Goal: Convert a string to upper case.
 Params: #1 str: string to convert.
 Modif: string caracters.
 Return: -1 if string is null, 1 on success.
 Comment:
 */
int hpl_StrUpper(char* str);

/*
 Version: 1.0.0
 Changes: None.
 Goal: Convert a string to lower case.
 Params: #1 str: string to convert.
 Modif: string caracters.
 Return: -1 if string is null, 1 on success.
 Comment:
 */
int hpl_StrLower(char* str);

/*
 Version: 1.0.0
 Changes: None.
 Goal: Clear a string (set to \0).
 Params: #1 str: string to clear/set.
 Modif: string caracters.
 Return: -1 if string is null, 1 on success.
 Comment: len is needed as the final \0 of the original string might not indicate the end of the char[].
 */
int hpl_StrClear(char* str, size_t len);
#endif /* hpl_string_h */
