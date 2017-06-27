/*//
//  hpl_iohandler.h
//  hpl-v3
//
//  Created by Hector Denis on 28/04/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#ifndef hpl_iohandler_h
#define hpl_iohandler_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>

/*
 Version: 1.0.0
 Changes: None.
 Goal: Clear the stream until EOF or \n.
 Params: #1 stream: stream to clear.
 Modifications: Changes stream status.
 Return: -1 if stream is NULL, 1 otherwise.
 Comment: None.
 */
int hpl_StreamClear(FILE* stream);

/*
 Version: 1.0.0
 Changes: None.
 Goal: Read a string from the input.
 Params: #1 str: str to store the result.
        #2 len: writable length of the string.
        #3 stream: stream to read from.
 Modifications: str if input success, stream status.
 Return: -1 if params are NULL or len less than 1.
          0 if read fails (nothing in buffer)
          2 if \n not found. Buffer is cleared.
          1 if read success, \n found.
 Comment: Different return values.
 */
int hpl_ReadString(char* str, int len, FILE* stream);

/*
 Version: 1.0.1
 Changes: 1.0.1: added SpaceClear.
 Goal: Read a *type* from the input.
 Params: #1 number: number to store the result.
        #2? base: base of the string input.
        #3 stream: stream to read from.
 Modifications: number to store the result (defaults to 0 if error), stream status.
 Return: -1 if params are NULL, -2 if read fails (nothing in buffer) or too large, 1 if success.
 Comment: Please keep them in sync! The unsigned versions dont compare number with a min, since the min is 0. INPUTSIZE_INT is currently 64. double64 is (in bit) 1 sign, 11 exp, 52 num. INPUTSIZE_FLT is currently 128.
 */
int hpl_ReadLong(long *number, int base, FILE *stream);
int hpl_ReadUnsignedLong(unsigned long *number, int base, FILE *stream);
int hpl_ReadInt(int *number, int base, FILE *stream);
int hpl_ReadUnsignedInt(unsigned int *number, int base, FILE *stream);

int hpl_ReadDouble(double *number, FILE *stream);
int hpl_ReadFloat(float *number, FILE *stream);

/*
 Version: 1.0.1
 Changes: 1.0.1: added message output stream.
 Goal: Read y or n.
 Params: #1 answer: int to store the answer. 1 yes, -1 no.
         #2 tell: tell user to stream.
         #3 stream: where to tell
 Modif: store answer, stream status.
 Return: -1 if params are NULL, 1 if success.
 Comment: Loops.
 */
int hpl_ReadYesNo(int* a, FILE* from, const char* tell, FILE* to);
/*
 Version: 1.0.0
 Changes: None.
 Goal: Remove trailing space from stream
 Params: #1 stream: the stream.
 Modif: stream status.
 Return: -1 if params are null, 1 if success.
 Comment: Nice <3.
 */
int hpl_SpaceClear(FILE* stream);

/*
 Version: 1.0.1
 Changes: 1.0.1: added output stream.
 Goal: Print remaining file, withoutchanging ftell position.
 Params: #1 from: the input stream.
         #2 to: the output stream.
 Modif: Only the output stream printing and status. Hopefully.
 Return: -1 if params are null, 1 if success.
 Comment: Debug power, tchou tchou!
 */
int hpl_FilePrintFromTo(FILE* from, FILE* to);

#endif /* hpl_iohandler_h */
