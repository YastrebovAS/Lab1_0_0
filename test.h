#ifndef LAB1_TEST_H
#define LAB1_TEST_H
#include <stdio.h>
#include "stdlib.h"
#include "Menu.h"
#include "Matrix.h"
#include "MatrixInt.h"
#include "MatrixDouble.h"


void __testInitMatrix_int(int size, matrix_int* mx) {
    int** values;
    values = (int**)calloc(size, sizeof(int*));
    for (int i = 0; i < size; ++i) {
        values[i] = (int*)calloc(size, sizeof(int));
        for (int j = 0; j < size; ++j) {
            values[i][j] = rand() % 10;
        }
    }
    mx->MATRIX->size = size;
    mx->MATRIX->values = (void**)values;
}
void __testInitMatrix_double(int size, matrix_double* mx) {
    double** values;
    values = (double**)calloc(size, sizeof(double*));
    for (int i = 0; i < size; ++i) {
        values[i] = (double*)calloc(size, sizeof(double));
        for (int j = 0; j < size; ++j) {
            values[i][j] = (double)(rand() % 10) + (double)(rand() % 100) / 100;
        }
    }
    mx->MATRIX->size = size;
    mx->MATRIX->values = (void**)values;
}

void testMatrix_int() {

    printf("[TEST_MATRIX_OPERATIONS_INT]");
    matrix ROOT_A, ROOT_B, ROOT_CONTAINER_INT;
    struct matrix_int A = { &ROOT_A };
    struct matrix_int B = { &ROOT_B };
    struct matrix_int container_int = {
            &ROOT_CONTAINER_INT,
            &summInt,
            &minusInt,
            &multiplyOnAlphaInt,
            &multiplyInt,
            &getDeterminantInt,
            &transposeMatrixInt,
            &reverseMatrixInt,
            &linearcombInt
    };


    __testInitMatrix_int(3, &A);
    __testInitMatrix_int(3, &B);


    printf("\nA ");
    printMatrix_int(&A);
    printf("\nB ");
    printMatrix_int(&B);

    container_int.summ_int(&A, &B, &container_int);
    printf("\nSumm A + B ");
    printMatrix_int(&container_int);

    printf("\nSubstraction A - B ");
    container_int.minus_int(&A, &B, &container_int);
    printMatrix_int(&container_int);


    double alpha = 2;
    printf("\nMultiplied A on %.2lf ", alpha);
    container_int.multiplyOnAlpha_int(&A, alpha, &container_int);
    printMatrix_int(&container_int);

    printf("\nMultiply A * B ");
    container_int.multiply_int(&A, &B, &container_int);
    printMatrix_int(&container_int);


    printf("\nGet determinant A ");
    int det = container_int.getDeterminant_int(&A);
    printf("\nDet(A) = %d\n", det);


    printf("\nTranspose A ");
    container_int.transpose_int(&A, &container_int);
    printMatrix_int(&container_int);
    /*
    printf("\nReversed C ");
    container_int.reverseMatrix_int(&A, &container_int);
    printMatrix_double(&container_int);
    printf("\nLinear Combination\n");
    int line = 1;
    container_int.linearcomb_Int(&A, &container_int,line);
    printMatrix_double(&container_int);
    */

}
void testMatrix_double() {
    printf("\n[TEST_MATRIX_OPERATIONS_DOUBLE]");


    matrix ROOT_C, ROOT_D, ROOT_CONTAINER;
    struct matrix_double C = { &ROOT_C };
    struct matrix_double D = { &ROOT_D };
    struct matrix_double container_double = {
            &ROOT_CONTAINER,
            &summDouble,
            &minusDouble,
            &multiplyOnAlphaDouble,
            &multiplyDouble,
            &getDeterminantDouble,
            &transposeMatrixDouble,
            &reverseMatrixDouble,
            &linearcombDouble
    };


    __testInitMatrix_double(3, &C);
    __testInitMatrix_double(3, &D);

    printf("\nC ");
    printMatrix_double(&C);
    printf("\nB ");
    printMatrix_double(&D);

    container_double.summ_double(&C, &D, &container_double);
    printf("\nSumm C + D ");
    printMatrix_double(&container_double);

    printf("\nSubstraction C - D ");
    container_double.minus_double(&C, &D, &container_double);
    printMatrix_double(&container_double);

    double alpha = 3.1;
    printf("\nMultiplied C on %.2f ", alpha);
    container_double.multiplyOnAlpha_double(&C, alpha, &container_double);
    printMatrix_double(&container_double);

    printf("\nMultiply C * D ");
    container_double.multiply_double(&C, &D, &container_double);
    printMatrix_double(&container_double);

    printf("\nGet determinant C ");
    double* det = container_double.getDeterminant_double(&C);
    printf("\nDet(C) = %.2f\n", &det);

    printf("\nTranspose C ");
    container_double.transpose_double(&C, &container_double);
    printMatrix_double(&container_double);

    printf("\nReversed C ");
    container_double.reverseMatrix_double(&C, &container_double);
    printMatrix_double(&container_double);

    printf("\nLinear Combination \n");
    int line = 1;
    container_double.linearcomb_Double(&C, &container_double, line);
    printMatrix_double(&container_double);
}

void tests() {
    printf("[TEST]\n\n");

    printf("[TEST_MATRIX_OPERATIONS]\n\n");
    testMatrix_int();
    testMatrix_double();

}

#endif //LAB1_TEST_H