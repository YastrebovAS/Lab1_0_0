#include "MatrixDouble.h"
#include "stdlib.h"
#include <math.h>
// -----------------------------------------------------------------------------------------------------------------
// --------------------------------------------------/ Matrix Operations /------------------------------------------
// -----------------------------------------------------------------------------------------------------------------


// --------------------------------------------------------/ DOUBLE /--------------------------------------------------

void summDouble(matrix_int* A, matrix_int* B, matrix_int* summed) {
    double** A_values, ** B_values, ** summed_values;
    A_values = (double**)A->MATRIX->values;
    B_values = (double**)B->MATRIX->values;
    int size = A->MATRIX->size;
    if (A->MATRIX->size == B->MATRIX->size) {
        summed_values = (double**)calloc(size, sizeof(double*));
        for (int i = 0; i < size; ++i) {
            summed_values[i] = (double*)calloc(size, sizeof(double));
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

void minusDouble(matrix_int* A, matrix_int* B, matrix_int* summed) {
    double** A_values, ** B_values, ** summed_values;
    A_values = (double**)A->MATRIX->values;
    B_values = (double**)B->MATRIX->values;
    int size = A->MATRIX->size;
    if (A->MATRIX->size == B->MATRIX->size) {
        summed_values = (double**)calloc(size, sizeof(double*));
        for (int i = 0; i < size; ++i) {
            summed_values[i] = (double*)calloc(size, sizeof(double));
            for (int j = 0; j < A->MATRIX->size; ++j) {
                summed_values[i][j] = A_values[i][j] - B_values[i][j];
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

void multiplyOnAlphaDouble(matrix_double* Matrix, double alpha, matrix_double* multiplied) {
    // for the reason void -> double multiply double
    double** valuesOrigin = (double**)Matrix->MATRIX->values;
    double** valuesMult = (double**)multiplied->MATRIX->values;
    for (int i = 0; i < Matrix->MATRIX->size; ++i)
        for (int j = 0; j < Matrix->MATRIX->size; ++j)
            valuesMult[i][j] = valuesOrigin[i][j] * alpha;

    multiplied->MATRIX->values = (void**)valuesMult;

    //    free(valuesMult);
    //    free(valuesOrigin);
}

void multiplyDouble(matrix_double* A, matrix_double* B, matrix_double* Result) {
    double** valuesA = (double**)A->MATRIX->values;
    double** valuesB = (double**)B->MATRIX->values;
    double** valuesResult;
    // Поскольку матрицы квадратные, имеем право проверять их на равенство size
    int size = A->MATRIX->size;
    if (A->MATRIX->size == B->MATRIX->size) {
        valuesResult = (double**)calloc(size, sizeof(double*));
        for (int i = 0; i < size; ++i) {
            valuesResult[i] = (double*)calloc(size, sizeof(double));
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

void __getMatrixWithoutRowAndColDouble(matrix_double* MatrixA, int row, int col, matrix_double* newMatrix) {
    int offsetRow = 0; //Смещение индекса строки в матрице
    int offsetCol = 0; //Смещение индекса столбца в матрице
    int size = MatrixA->MATRIX->size;

    double** valuesA = (double**)MatrixA->MATRIX->values;
    double** valuesNew = (double**)calloc((size - 1), sizeof(double*));
    for (int i = 0; i < size - 1; i++) {
        //Пропустить row-ую строку
        if (i == row) {
            offsetRow = 1; //Как только встретили строку, которую надо пропустить, делаем смещение для исходной матрицы
        }
        offsetCol = 0; //Обнулить смещение столбца
        valuesNew[i] = (double*)calloc((size - 1), sizeof(double));
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

double getDeterminantDouble(matrix_double* MatrixA) {
    int size = MatrixA->MATRIX->size;
    double** values = (double**)MatrixA->MATRIX->values;

    if (size == 2) {
        return values[0][0] * values[1][1] - values[0][1] * values[1][0];
    }
    else {
        double res = 0;
        for (int i = 0; i < size; ++i) {
            double itemMult = values[i][0];
            matrix ROOTMX;
            matrix_double subMatrix = { &ROOTMX };
            __getMatrixWithoutRowAndColDouble(MatrixA, i, 0, &subMatrix);
            res += (double)pow(-1, i) * itemMult * getDeterminantDouble(&subMatrix);
        }
        return res;
    }
}

void transposeMatrixDouble(matrix_double* MatrixA, matrix_double* Result) {
    double** values = (double**)MatrixA->MATRIX->values;
    int size = MatrixA->MATRIX->size;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (i != j) {
                double t = values[i][j];
                values[i][j] = values[j][i];
                values[j][i] = t;
            }
        }
    }
    Result->MATRIX->size = size;
    Result->MATRIX->values = (void**)values;
}

void reverseMatrixDouble(matrix_double* MatrixA, matrix_double* other) {
    double detA = getDeterminantDouble(MatrixA);
    if (detA != 0) {
        int size = MatrixA->MATRIX->size;
        double** values = (double**)calloc(size, sizeof(double*));
        for (int i = 0; i < size; ++i) {
            values[i] = (double*)calloc(size, sizeof(double));
            for (int j = 0; j < size; ++j) {
                matrix ROOT_AlgAdd;
                matrix_double AlgAdd = { &ROOT_AlgAdd };
                __getMatrixWithoutRowAndColDouble(MatrixA, i, j, &AlgAdd);
                transposeMatrixDouble(&AlgAdd, &AlgAdd);
                double tmpDet = getDeterminantDouble(&AlgAdd);
                int k = i + j;
                values[i][j] =pow(-1, k) * tmpDet;
            }
        }
        other->MATRIX->values = (void**)values;
        transposeMatrixDouble(other, other);
        multiplyOnAlphaDouble(other, 1.0 / detA, other);
    }
    else {
        other->MATRIX->isNull = 1;
        Error(1, "Deternimant = 0");
    }
}

void linearcombDouble(struct matrix_int* A, struct matrix_int* container, int line) {
    printf("Adding linear combinations to %d line\n", line);
    int size = A->MATRIX->size;
    double** values = (double**)A->MATRIX->values;
    double** summed_values = (double**)calloc(size, sizeof(double*));
    for (int i = 0; i < size; ++i) {
        summed_values[i] = (double*)calloc(size, sizeof(double));
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