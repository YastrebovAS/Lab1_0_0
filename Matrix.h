#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H
#include "string.h"
typedef struct matrix {
    void** values;
    int size;
    int isNull;
} matrix;



typedef struct matrix_int {
    matrix* MATRIX;
    void* (*summ_int)(struct matrix_int* this, struct matrix_int* other, struct matrix_int* container);
    void* (*minus_int)(struct matrix_int* this, struct matrix_int* other, struct matrix_int* container);
    void* (*multiplyOnAlpha_int)(struct matrix_int* this, double alpha, struct matrix_int* container);
    void* (*multiply_int)(struct matrix_int* this, struct matrix_int* other, struct matrix_int* container);
    int* (*getDeterminant_int)(struct matrix_int* this);
    void* (*transpose_int)(struct matrix_int* A, struct matrix_int* container);
    void* (*reverseMatrix_int)(struct matrix_int* A, struct matrix_int* container);
    void* (*linearcomb_Int)(struct matrix_int* A, struct matrix_int* container,int option);
} matrix_int;

typedef struct matrix_double {
    matrix* MATRIX;
    void* (*summ_double)(struct matrix_double* this, struct matrix_double* other, struct matrix_double* container);
    void* (*minus_double)(struct matrix_double* this, struct matrix_double* other, struct matrix_double* container);
    void* (*multiplyOnAlpha_double)(struct matrix_double* this, double alpha, struct matrix_double* container);
    void* (*multiply_double)(struct matrix_double* this, struct matrix_double* other, struct matrix_double* container);
    double* (*getDeterminant_double)(struct matrix_double* this);
    void* (*transpose_double)(struct matrix_double* A, struct matrix_double* container);
    void* (*reverseMatrix_double)(struct matrix_double* A, struct matrix_double* container);
    void* (*linearcomb_Double)(struct matrix_int* A, struct matrix_int* container,int option);
} matrix_double;


void swap();



#endif //LAB1_MATRIX_H