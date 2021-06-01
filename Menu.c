#include <stdio.h>
#include "stdlib.h"
#include "MatrixInt.h"
#include "Matrixdouble.h"
#include "Matrix.h"
#include "Menu.h"

void Menu() {
    int type, operation;
    matrix ROOT_A, ROOT_B, ROOT_CONTAINER;
    double alpha;
    chooseType(&type);
    chooseOperation(type, &operation);
    //    printf("%d, %d", type, operation);
    conveyor(type, operation, &ROOT_A, &ROOT_B, &ROOT_CONTAINER);
}
//Input types
matrix_int initialization_martix_int(matrix_int* Matrix) {
    int** values;
    int size;
    printf("Enter count elements: \n");
    scanf("%d", &size);

    values = (int**)calloc(size, sizeof(int*));
    printf("Enter values for matrix: \n");
    for (int i = 0; i < size; ++i) {
        values[i] = (int*)calloc(size, sizeof(int));
        for (int j = 0; j < size; ++j) {
            scanf("%d", &values[i][j]);
        }
    }
    Matrix->MATRIX->size = size;
    Matrix->MATRIX->values = (void**)values;
    return *Matrix;
}
matrix_double initialization_martix_double(matrix_double* Matrix) {
    double** values;
    int size;
    printf("Enter count elements: \n");
    scanf("%d", &size);

    values = (double**)calloc(size, sizeof(double*));
    printf("Enter values for matrix: \n");
    for (int i = 0; i < size; ++i) {
        values[i] = (double*)calloc(size, sizeof(double));
        for (int j = 0; j < size; ++j) {
            scanf("%lf", &values[i][j]);
        }
    }
    Matrix->MATRIX->size = size;
    Matrix->MATRIX->values = (void**)values;
    return *Matrix;
}

//output types
void printMatrix_int(matrix_int* Matrix) {

    printf("matrix:  \n");
    for (int i = 0; i < Matrix->MATRIX->size; ++i) {
        for (int j = 0; j < Matrix->MATRIX->size; ++j) {
            printf("%d ", ((int**)Matrix->MATRIX->values)[i][j]);
        }
        printf("\n");
    }
}
void printMatrix_double(matrix_double* Matrix) {
    double** values = (double**)Matrix->MATRIX->values;

    printf("matrix:  \n");
    for (int i = 0; i < Matrix->MATRIX->size; ++i) {
        for (int j = 0; j < Matrix->MATRIX->size; ++j) {
            printf("%.2f ", values[i][j]);
        }
        printf("\n");
    }
}



//Choosing type
void chooseType(int* type) {
    printf("Choose type for elements: \n");
    printf("1. Int \n");
    printf("2. Double \n");
    scanf("%d", type);
}
//Choosing operation
void chooseOperation(int type, int* operation) {
    printf("Choose operation for elements: \n");
    switch (type) {
    case 1:
    case 2: {
        printf("1. Summ \n");
        printf("2. Minus \n");
        printf("3. Multiply \n");
        printf("4. Multiply on alpha \n");
        printf("5. Get determinant \n");
        printf("6. Get transpose matrix \n");
        //printf("7. Get reverse matrix \n");
        printf("7. Add Linear combination \n");
    }; break;
    default: {
        printf("Error! You entered incorrect operation.");
    }
    }

    scanf("%d", operation);
}
//Magic happens here
void conveyor(int type, int operation, matrix* RA, matrix* RB, matrix* RC) {
    switch (type) {
    case 1: {
        matrix_int A = { RA };
        matrix_int B = { RB };
        matrix_int cont = {
                RC,
                &summInt,
                &minusInt,
                &multiplyOnAlphaInt,
                &multiplyInt,
                &getDeterminantInt,
                &transposeMatrixInt,
                &reverseMatrixInt,
                &linearcombInt
        };
        A = initialization_martix_int(&A);
        B = initialization_martix_int(&B);

        printf("\nA ");
        printMatrix_int(&A);
        printf("\nB ");
        printMatrix_int(&B);

        switch (operation) {
        case 1: {
            cont.summ_int(&A, &B, &cont);
            printf("\nSumm A + B ");
            printMatrix_int(&cont);
        }; break;
        case 2: {
            cont.minus_int(&A, &B, &cont);
            printf("\nSub A - B ");
            printMatrix_int(&cont);
        }; break;
        case 3: {
            cont.multiply_int(&A, &B, &cont);
            printf("\nMult A * B ");
            printMatrix_int(&cont);
        }; break;
        case 4: {
            int alpha;
            printf("Enter alpha: \n");
            scanf("%d", &alpha);
            cont.multiplyOnAlpha_int(&A, alpha, &cont);
            printf("\nMult on alpha A ");
            printMatrix_int(&cont);
        }; break;
        case 5: {
            cont.getDeterminant_int(&A);
            printf("\ndet(A) ");
            printMatrix_int(&cont);
        }; break;
        case 6: {
            cont.transpose_int(&A, &cont);
            printf("\ntranspose A ");
            printMatrix_int(&cont);
        }; break;
            /*
        case 7: {
            cont.reverseMatrix_int(&A, &cont);
            printf("\nReversed A ");
            printMatrix_int(&cont);
        }; break;
        */
        case 7: {
            int alpha;
            printf("Enter the line: \n");
            scanf("%d", &alpha);
            cont.linearcomb_Int(&A, &cont,alpha);
            printf("\nLinear Combination A ");
            printMatrix_int(&cont);
        }; break;
        }
    }; break;
    case 2: {
        matrix_double A = { RA };
        matrix_double B = { RB };
        matrix_double cont = {
                RC,
                &summDouble,
                &minusDouble,
                &multiplyOnAlphaDouble,
                &multiplyDouble,
                &getDeterminantDouble,
                &transposeMatrixDouble,
                &reverseMatrixDouble,
                &linearcombDouble
        };
        A = initialization_martix_double(&A);
        B = initialization_martix_double(&B);

        printf("\nA ");
        printMatrix_double(&A);
        printf("\nB ");
        printMatrix_double(&B);

        switch (operation) {
        case 1: {
            cont.summ_double(&A, &B, &cont);
            printf("\nSumm A + B ");
            printMatrix_double(&cont);
        }; break;
        case 2: {
            cont.minus_double(&A, &B, &cont);
            printf("\nSub A - B ");
            printMatrix_double(&cont);
        }; break;
        case 3: {
            cont.multiply_double(&A, &B, &cont);
            printf("\nMult A * B ");
            printMatrix_double(&cont);
        }; break;
        case 4: {
            int alpha;
            printf("Enter alpha: \n");
            scanf("%d", &alpha);
            cont.multiplyOnAlpha_double(&A, alpha, &cont);
            printf("\nMult on alpha A ");
            printMatrix_double(&cont);
        }; break;
        case 5: {
            cont.getDeterminant_double(&A);
            printf("\ndet(A) ");
            printMatrix_double(&cont);
        }; break;
        case 6: {
            cont.transpose_double(&A, &cont);
            printf("\ntranspose A ");
            printMatrix_double(&cont);
        }; break;
        case 7: {
            cont.reverseMatrix_double(&A, &cont);
            printf("\nReverse A ");
            printMatrix_double(&cont);
        }; break;
        case 8: {
            int alpha;
            printf("Enter the line: \n");
            scanf("%d", &alpha);
            cont.linearcomb_Double(&A, &cont, alpha);
            printf("\nLinear combination A ");
            printMatrix_double(&cont);
        }; break;
        }
    }; break;
    }
}
