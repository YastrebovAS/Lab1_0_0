#ifndef LAB1_ERROREXCEPTIONS_H
#define LAB1_ERROREXCEPTIONS_H
#include <stdlib.h>
#include <stdio.h>
void Error(int code, char* message) {
    printf("Error(%d): %s", code, message);
    printf("\n");
    system("pause");
    exit(0);
}

#endif //LAB1_ERROREXCEPTIONS_H