#include "stdlib.h"
#include "Matrix.h"
#include "MatrixInt.h"
#include <math.h>
#include "Errors.h"
// -----------------------------------------------------------------------------------------------------------------
// --------------------------------------------------/ Matrix Operations /------------------------------------------
// -----------------------------------------------------------------------------------------------------------------
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// --------------------------------------------------------/ INT /--------------------------------------------------

void summInt(matrix_int* A, matrix_int* B, matrix_int* summed) {
    int** A_values, ** B_values, ** summed_values;
    A_values = (int**)A->MATRIX->values;
    B_values = (int**)B->MATRIX->values;
    int size = A->MATRIX->size;
    if (A->MATRIX->size == B->MATRIX->size) {
        summed_values = (int**)calloc(size, sizeof(int*));
        for (int i = 0; i < size; ++i) {
            summed_values[i] = (int*)calloc(size, sizeof(int));
            for (int j = 0; j < A->MATRIX->size; ++j) {
                summed_values[i][j] = A_values[i][j] + B_values[i][j];
            }
        }
        summed->MATRIX->values = (void**)summed_values;
        summed->MATRIX->size = size;
    }
    else {
        summed->MATRIX->isNull = 1;
        Error(1, "Matrixes have different sizes");
    }


    //    free(A_values);
    //    free(B_values);
}

void minusInt(matrix_int* A, matrix_int* B, matrix_int* sub) {
    int** summed_values;
    int size = A->MATRIX->size;
    if (A->MATRIX->size == B->MATRIX->size) {
        summed_values = (int**)calloc(size, sizeof(int*));
        for (int i = 0; i < size; ++i) {
            summed_values[i] = ((int*)calloc(size, sizeof(int)));
            for (int j = 0; j < A->MATRIX->size; ++j) {
                summed_values[i][j] = (((int**)A->MATRIX->values)[i][j] - ((int**)B->MATRIX->values)[i][j]);
            }
        }
        sub->MATRIX->size = size;
        sub->MATRIX->values = (void**)summed_values;
    }
    else {
        sub->MATRIX->isNull = 1;
    }

}

void multiplyOnAlphaInt(matrix_int* Matrix, double alpha, matrix_int* multiplied) {
    // for the reason void -> double multiply double
    double** valuesOrigin = (double**)Matrix->MATRIX->values;
    double** valuesMult = (double**)multiplied->MATRIX->values;
    for (int i = 0; i < Matrix->MATRIX->size; ++i)
        for (int j = 0; j < Matrix->MATRIX->size; ++j)
            valuesMult[i][j] = valuesOrigin[i][j] * alpha;

    multiplied->MATRIX->values = (void**)valuesMult;
    multiplied->MATRIX->size = Matrix->MATRIX->size;
}

void multiplyInt(matrix_int* A, matrix_int* B, matrix_int* Result) {
    int** valuesA = (int**)A->MATRIX->values;
    int** valuesB = (int**)B->MATRIX->values;
    int** valuesResult;
    // Поскольку матрицы квадратные, имеем право проверять их на равенство size
    if (A->MATRIX->size == B->MATRIX->size) {
        int size = A->MATRIX->size;
        valuesResult = (int**)calloc(size, sizeof(int*));
        for (int i = 0; i < size; ++i) {
            valuesResult[i] = (int*)calloc(size, sizeof(int));
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k)
                    valuesResult[i][j] += valuesA[i][k] * valuesB[k][j];
            }
        }
        Result->MATRIX->size = size;
        Result->MATRIX->values = (void**)valuesResult;
    }
    else {
        Result->MATRIX->isNull = 1;
        Error(1, "Matrixes have different sizes");
    }
}

void __getMatrixWithoutRowAndColInt(matrix_int* MatrixA, int row, int col, matrix_int* newMatrix) {
    int offsetRow = 0; //Смещение индекса строки в матрице
    int offsetCol = 0; //Смещение индекса столбца в матрице
    int size = MatrixA->MATRIX->size;

    int** valuesA = (int**)MatrixA->MATRIX->values;
    int** valuesNew = (int**)calloc((size - 1), sizeof(int*));
    for (int i = 0; i < size - 1; i++) {
        //Пропустить row-ую строку
        if (i == row) {
            offsetRow = 1; //Как только встретили строку, которую надо пропустить, делаем смещение для исходной матрицы
        }
        offsetCol = 0; //Обнулить смещение столбца
        valuesNew[i] = (int*)calloc((size - 1), sizeof(int));
        for (int j = 0; j < size - 1; j++) {
            //Пропустить col-ый столбец
            if (j == col) {
                offsetCol = 1; //Встретили нужный столбец, проускаем его смещением
            }
            valuesNew[i][j] = valuesA[i + offsetRow][j + offsetCol];
        }
    }
    newMatrix->MATRIX->size = (size - 1);
    newMatrix->MATRIX->values = (void**)valuesNew;
}

int getDeterminantInt(matrix_int* MatrixA) {
    int size = MatrixA->MATRIX->size;
    int** values = (int**)MatrixA->MATRIX->values;

    if (MatrixA->MATRIX->size == 2) {
        return values[0][0] * values[1][1] - values[0][1] * values[1][0];
    }
    else {
        int res = 0;
        for (int i = 0; i < size; ++i) {
            int itemMult = values[i][0];
            matrix ROOTMX;
            matrix_int subMatrix = { &ROOTMX };
            __getMatrixWithoutRowAndColInt(MatrixA, i, 0, &subMatrix);
            res += pow(-1, i) * itemMult * getDeterminantInt(&subMatrix);
        }
        return res;
    }
}

void transposeMatrixInt(matrix_int* MatrixA, matrix_int* Result) {
    int** values = (int**)MatrixA->MATRIX->values;
    int size = MatrixA->MATRIX->size;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (i != j) {
                swap(&values[i][j], &values[j][i]);
            }
        }
    }
    Result->MATRIX->size = size;
    Result->MATRIX->values = (void**)values;
}

void reverseMatrixInt(matrix_int* MatrixA, matrix_int* other) {
    int detA = getDeterminantInt(MatrixA);
    if (detA != 0) {
        int size = MatrixA->MATRIX->size;
        int** values = (int**)calloc(size, sizeof(int*));
        for (int i = 0; i < size; ++i) {
            values[i] = (int*)calloc(size, sizeof(int));
            for (int j = 0; j < size; ++j) {
                matrix ROOT_AlgAdd;
                matrix_int AlgAdd = { &ROOT_AlgAdd };
                __getMatrixWithoutRowAndColInt(MatrixA, i, j, &AlgAdd);
                transposeMatrixInt(&AlgAdd, &AlgAdd);
                int tmpDet = getDeterminantInt(&AlgAdd);
                int k = i + j;
                values[i][j] = pow(-1, k) * tmpDet;
            }
        }
        other->MATRIX->values = (void**)values;
        //reversedMatrix.MATRIX->size = MatrixA->MATRIX->size;
        multiplyOnAlphaInt(other, 1.0 / (double)detA, other);
        transposeMatrixInt(other, other);
    }
    else {
        other->MATRIX->isNull = 1;
        Error(1, "Determinant = 0");
    }
}

void linearcombInt(struct matrix_int* A, struct matrix_int* container, int line) {
    printf("Adding linear combinations to %d line\n", line);
    int size = A->MATRIX->size;
    int** values = (int**)A->MATRIX->values;
    int** summed_values = (int**)calloc(size, sizeof(int*));
    for (int i = 0; i < size; ++i) {
        summed_values[i] = (int*)calloc(size, sizeof(int));
        for (int j = 0; j < size; ++j)
            summed_values[i][j] = values[i][j];

    }
    for (int i = 0; i < size; ++i) {
        if (i == line - 1) {
            for (int k = 0; k < size; ++k) {
                summed_values[line - 1][k] = values[line - 1][k];
                for (int j = 0; j < size; ++j) {
                    summed_values[line - 1][k] += (rand() % 5) * values[j][k];
                }
            }
        }
        container->MATRIX->values = (void**)summed_values;
        container->MATRIX->size = size;
    }
}