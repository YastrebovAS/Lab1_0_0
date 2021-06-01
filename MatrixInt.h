#include "Matrix.h"
#ifndef LAB1_ALGEBRA_INT_H
#define LAB1_ALGEBRA_INT_H

void summInt(matrix_int* A, matrix_int* B, matrix_int* summed);
void minusInt(matrix_int* A, matrix_int* B, matrix_int* sub);
void multiplyOnAlphaInt(matrix_int* Matrix, double alpha, matrix_int* multiplied);
void multiplyInt(matrix_int* A, matrix_int* B, matrix_int* Result);
void __getMatrixWithoutRowAndColInt(matrix_int* MatrixA, int row, int col, matrix_int* newMatrix);
int getDeterminantInt(matrix_int* MatrixA);
void transposeMatrixInt(matrix_int* MatrixA, matrix_int* Result);
void reverseMatrixInt(matrix_int* MatrixA, matrix_int* other);
void linearcombInt(struct matrix_int* MatrixA, struct matrix_int* container, int option);

#endif //LAB1_ALGEBRA_INT_H