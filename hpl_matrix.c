/*//
//  hpl_matrix.c
//  hpl-v3
//
//  Created by Hector Denis on 28/04/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#include "hpl_matrix.h"

Matrix* hpl_MatrixAlloc(long lines, long columns) {
    Matrix* matrix = hpl_Malloc(sizeof(*matrix));
    long i = 0;
    if (NULL == matrix || lines < 1 || columns < 1) {
        return NULL;
    }
    
    matrix->mx = hpl_Malloc((size_t) lines * sizeof(long*));
    if (NULL == matrix) {
        hpl_MatrixFree(matrix, lines);
        return NULL;
    }
    
    /* Clear garbage values on pointers -> clean with free possible. */
    for (i = 0; i < lines; i++) {
        matrix->mx[i] = NULL;
    }
    
    for (i = 0; i < lines; i++) {
        matrix->mx[i] = hpl_Malloc((size_t) columns * sizeof(long));
        
        if (NULL == matrix->mx[i]) {
            hpl_MatrixFree(matrix, lines);
            return NULL;
        }
    }
    matrix->lin = lines;
    matrix->col = columns;
    
    return matrix;
}
int hpl_MatrixFree(Matrix* m, long lin) {
    long i = 0;
    if (NULL == m || lin < 1) {
        return -1;
    }
    if (NULL != m->mx) {
        for (i = 0; i < lin; i++) {
            if (NULL != m->mx[i]) {
                free(m->mx[i]);
                m->mx[i] = NULL;
            }
        }
    }
    
    free(m->mx);
    m->mx = NULL;
    free(m);
    return 1;
}
int hpl_MatrixFill(Matrix* m, long value) {
    int l = 0;
    int c = 0;
    if (NULL == m) {
        return -1;
    }
    
    for (l = 0; l < m->lin; l++) {
        for (c = 0; c < m->col; c++) {
            m->mx[l][c] = value;
        }
    }
    return 1;
}
int hpl_MatrixPrint(Matrix* m, FILE *stream) {
    long l = 0;
    long c = 0;
    if (NULL == m || NULL == stream) {
        return -1;
    }
    
    for (l = 0; l < m->lin; l++) {
        for (c = 0; c < m->col; c++)
            fprintf(stream, "%ld ", m->mx[l][c]);
        fprintf(stream, "\n");
    }
    return 1;
}
