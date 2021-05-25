/*
#include "Polynomial.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

Lin* Sumint(Lin* a, Lin* b) {
    if (a->length != b->length) {
        printf("Length a != Length b, rewrite one of your forms");
        return NULL;
    };
    if (a->elementSize == sizeof(double) || b->elementSize == sizeof(double)) {
        printf("One of element sizes is wrong, rewrite one of your forms");
        return NULL;
    }
    Lin* C = malloc(sizeof(Lin));

    size_t l = a->length;

    size_t x;
    x = sizeof(int);
    int* iar;
    iar = malloc(x * l);
    for (int i = 0; i < l; ++i) {
        int a1 = ((int*)a->coefs)[i];
        int b1 = ((int*)b->coefs)[i];
        iar[i] = a1 + b1;
        //printf("\n%d+%d=%d\n",a1,b1,iar[i]);
    };
    C = GenerateLin(l, x, iar);

    return C;
}

Lin* Minint(Lin* a, Lin* b) {
    Revers(b);
    if (a->length != b->length) {
        printf("Length a != Length b, rewrite one of your forms");
        return NULL;
    };
    if (a->elementSize == sizeof(double) || b->elementSize == sizeof(double)) {
        printf("One of element sizes is wrong, rewrite one of your forms");
        return NULL;
    }
    Lin* C = malloc(sizeof(Lin));

    size_t l = a->length;

    size_t x;
    x = sizeof(int);
    int* iar;
    iar = malloc(x * l);
    for (int i = 0; i < l; ++i) {
        int a1 = ((int*)a->coefs)[i];
        int b1 = ((int*)b->coefs)[i];
        iar[i] = a1 + b1;
        //printf("\n%d+%d=%d\n",a1,b1,iar[i]);
    };
    C = GenerateLin(l, x, iar);

    return C;
}

Lin* Multint(Lin* a, int x) {
    if (a->elementSize != sizeof(int) || sizeof(x) != sizeof(int)) {
        printf("Wrong type of elements! Remake your form or remamake your value");
        return NULL;
    }
    Lin* C = malloc(sizeof(Lin));

    int* temp = malloc(a->length * sizeof(int));
    for (int i = 0; i < a->length; ++i) {
        int z = ((int*)a->coefs)[i];
        temp[i] = z * x;
    };
    size_t l = a->length;
    /*for(int i=0;i<a->length;++i){
        printf("%d ",temp[i]);
    };
    C = GenerateLin(l, sizeof(int), temp);
    return C;
}
*/