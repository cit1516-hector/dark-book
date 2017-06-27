/*//
//  hpl_matrix.h
//  hpl-v3
//
//  Created by Hector Denis on 28/04/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#ifndef hpl_matrix_h
#define hpl_matrix_h


#include <stdio.h>
/* FILE* and io */
#include <stdlib.h>
/* NULL size_t */
#include "hpl_alloc.h"

typedef struct Matrix Matrix;
struct Matrix {
    long **mx;
    long lin;
    long col;
};

/*
 Version: 1.0.0
 Changes: None.
 Goal: Allocate struct Matrix with line/column, error checking.
 Params: #1 lines: number of lines to allocate.
         #2 columns: number of columns to allocate.
 Modif: None.
 Return: NULL if fail, pointer to matrix if success.
 Comment:
 */
Matrix* hpl_MatrixAlloc(long lines, long columns);

/*
 Version: 1.0.0
 Changes: None.
 Goal: Free struct Matrix.
 Params: #1 matrix: matrix to free.
         #2 lin: number of lines to free.
 Modif: Matrix is freed.
 Return: -1 if matrix is null, lin invalid (< 1), 1 for success.
 Comment: The pointer to matrix structure is not cleared.
 */
int hpl_MatrixFree(Matrix* m, long lines);

/*
 Version: 1.0.0
 Changes: None.
 Goal: Fill a matrix with a value.
 Params: #1 matrix: matrix to fill.
         #2 value: value that fills.
 Modif: matrix's values are changed.
 Return: -1 if params are null, 1 on success.
 Comment:
 */
int hpl_MatrixFill(Matrix* m, long value);

/*
 Version: 1.0.0
 Changes: None.
 Goal: Print a matrix line by line.
 Params: #1 matrix: matrix to print.
         #2 stream: where to print.
 Modif: stream status.
 Return: -1 if params are null, 1 on success.
 Comment:
 */
int hpl_MatrixPrint(Matrix *m, FILE *stream);

#endif /* hpl_matrix_h */
