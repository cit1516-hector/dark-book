/*//
//  hpl_iohandler.c
//  hpl-v3
//
//  Created by Hector Denis on 28/04/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#include "hpl_iohandler.h"
#define INPUTSIZE_INT (64)
#define INPUTSIZE_FLT (128)

int hpl_StreamClear(FILE* stream) {
    int ch = '\0';
    if (NULL == stream) {
        return -1;
    }
    while ('\n' != ch && EOF != ch) {
        ch = getc(stream);
    }
    return 1;
}

int hpl_ReadString(char *str, int len, FILE *stream) {
    char* ch = NULL;
    
    if (NULL == str || NULL == stream || len < 1) {
        return -1;
    }
    
    if (NULL == fgets(str, len, stream)) {
        hpl_StreamClear(stream);
        return 0;
    }
    ch = strchr(str, '\n');
    if (NULL != ch) {
        *ch = '\0';
    } else {
        hpl_StreamClear(stream);
        return 2;
    }
    return 1;
}

int hpl_ReadLong(long *number, int base, FILE *stream) {
    char input[INPUTSIZE_INT] = "";
    char *endptr = NULL;
    
    if (NULL == number || NULL == stream) {
        return -1;
    }
    hpl_SpaceClear(stream);
    hpl_ReadString(input, sizeof(input), stream);
    *number = strtol(input, &endptr, base);
    if (endptr == input || *number == LONG_MAX || *number == LONG_MIN) {
        *number = 0;
        return -2;
    }
    return 1;
}

int hpl_ReadUnsignedLong(unsigned long *number, int base, FILE *stream) {
    char input[INPUTSIZE_INT] = "";
    char *endptr = NULL;
    if (NULL == number || NULL == stream) {
        return -1;
    }
    hpl_SpaceClear(stream);
    hpl_ReadString(input, sizeof(input), stream);
    *number = (unsigned long) strtol(input, &endptr, base);
    if (endptr == input || *number == LONG_MAX) {
        *number = 0;
        return -2;
    }
    return 1;
}

int hpl_ReadInt(int *number, int base, FILE *stream) {
    char input[INPUTSIZE_INT] = "";
    char *endptr = NULL;
    if (NULL == number || NULL == stream) {
        return -1;
    }
    hpl_SpaceClear(stream);
    hpl_ReadString(input, sizeof(input), stream);
    *number = (int)strtol(input, &endptr, base);
    if (endptr == input || *number == INT_MAX || *number == INT_MIN) {
        *number = 0;
        return -2;
    }
    return 1;
}

int hpl_ReadUnsignedInt(unsigned int *number, int base, FILE *stream) {
    char input[INPUTSIZE_INT] = "";
    char *endptr = NULL;
    if (NULL == number || NULL == stream) {
        return -1;
    }
    hpl_SpaceClear(stream);
    hpl_ReadString(input, sizeof(input), stream);
    *number = (unsigned int) strtol(input, &endptr, base);
    if (endptr == input || *number == UINT_MAX) {
        *number = 0;
        return -2;
    }
    return 1;
}

int hpl_ReadDouble(double *number, FILE *stream) {
    char input[INPUTSIZE_FLT] = "";
    char *endptr = NULL;
    if (NULL == number || NULL == stream) {
        return -1;
    }
    hpl_SpaceClear(stream);
    hpl_ReadString(input, sizeof(input), stream);
    *number = strtod(input, &endptr);
    
    if (endptr == input || *number == DBL_MAX || *number == DBL_MIN) {
        *number = 0;
        return -2;
    }
    return 1;
}

int hpl_ReadFloat(float *number, FILE *stream) {
    char input[INPUTSIZE_FLT] = "";
    char *endptr = NULL;
    if (NULL == number || NULL == stream) {
        return -1;
    }
    hpl_SpaceClear(stream);
    hpl_ReadString(input, sizeof(input), stream);
    *number = (float) strtod(input, &endptr);
    
    if (endptr == input || *number == FLT_MAX || *number == FLT_MIN) {
        *number = 0;
        return -2;
    }
    return 1;
}

int hpl_ReadYesNo(int* answer, FILE* from, const char* tell, FILE* to) {
    char input[8] = "";
    if (NULL == answer || NULL == tell || NULL == from || NULL == to) {
        return -1;
    }
    *answer = 0;
    while (0 == *answer) {
        fprintf(to, "%s", tell);
        hpl_ReadString(input, sizeof(input), from);
        
        input[0] = (char) tolower(input[0]);
        
        if (0 == strcmp(input, "y")) {
            *answer = 1;
        } else if (0 == strcmp(input, "n")) {
            *answer = -1;
        }
    }
    return 1;
}


int hpl_SpaceClear(FILE* stream) {
    int c = 'a';
    if (NULL == stream) {
        return -1;
    }
    
    do {
        c = fgetc(stream);
    } while (isspace(c));
    if (0 == isspace(c)) {
        ungetc(c, stream);
    }
    return 1;
}

int hpl_FilePrintFromTo(FILE* from, FILE* to) {
    long save = 0;
    int c = '\0';
    
    if (NULL == from || NULL == to) {
        return -1;
    }
    save = ftell(from);
    while (EOF != (c = fgetc(from))) {
        putc(c, to);
    }
    fseek(from, save, SEEK_SET);
    
    return 1;
}
