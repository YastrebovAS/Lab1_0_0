#ifndef LAB1_UI_H
#define LAB1_UI_H
#include "Matrix.h"

matrix_int initialization_martix_int(matrix_int* Matrix);
matrix_double initialization_martix_double(matrix_double* Matrix);

void printMatrix_int(matrix_int* Matrix);
void printMatrix_double(matrix_double* Matrix);

void chooseType(int* type);
void chooseOperation(int type, int* operation);
void conveyor(int type, int operation, matrix* RA, matrix* RB, matrix* RC);

void Menu();
#endif //LAB1_UI_H