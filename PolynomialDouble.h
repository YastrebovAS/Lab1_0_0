#ifndef DOUBLE_H
#define DOUBLE_H
#include "headers.h"
void printPolyDouble(const void* variable);
int ComparatorZeroDouble(const void* variable);
static void* NullDouble();


void SumDouble(const void* var1, const void* var2);
void MulDouble(const void* var1, const void* var2);
Pol InitializationDouble(uint32_t size);
#endif //DOUBLEL_H