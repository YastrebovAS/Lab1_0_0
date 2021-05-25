#ifndef INT_H
#define INT_H
//#include <stdint.h>
#include "Polynomial.h"
void printPolyInt(const void* variable);
int ComparatorZeroInt(const void* variable);
static void* NullInt();


void SumInt(const void* var1, const void* var2);
void MulInt(const void* var1, const void* var2);
Pol InitializationInt(uint32_t size);
#endif //INT_H