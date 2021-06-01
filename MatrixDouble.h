#ifndef LAB1_ALGEBRA_DOUBLE_H
#define LAB1_ALGEBRA_DOUBLE_H
#include "Matrix.h"


void summDouble(matrix_int* A, matrix_int* B, matrix_int* summed);
void minusDouble(matrix_int* A, matrix_int* B, matrix_int* summed);
void multiplyOnAlphaDouble(matrix_double* Matrix, double alpha, matrix_double* multiplied);
void multiplyDouble(matrix_double* A, matrix_double* B, matrix_double* Result);
void __getMatrixWithoutRowAndColDouble(matrix_double* MatrixA, int row, int col, matrix_double* newMatrix);
double getDeterminantDouble(matrix_double* MatrixA);
void transposeMatrixDouble(matrix_double* MatrixA, matrix_double* Result);
void reverseMatrixDouble(matrix_double* MatrixA, matrix_double* other);
void linearcombDouble(struct matrix_int* A, struct matrix_int* container,int option);

#endif //LAB1_ALGEBRA_DOUBLE_H