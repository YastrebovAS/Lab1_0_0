#include "headers.h"
static void printPolyDouble(const void* variable) {
	printf("%.1f", *((double*)variable));
}

int ComparatorZeroDouble(const void* variable) {
	double* pointer = (double*)variable;
	if (*pointer == 0.0)
		return 0;
	else if (*pointer < 0.0)
		return 1;
	else if (*pointer > 0.0)
		return -1;
}
static void* NullDouble() {
	void* answer = (void*)malloc(sizeof(double));
	double* pointer = (double*)answer;
	*pointer = 0.0;
	return answer;
}


void SumDouble(const void* var1, const void* var2) {
	void* number = (void*)malloc(sizeof(double));
	double* variable1 = (double*)var1;
	double* variable2 = (double*)var2;
	double* sum = (double*)number;
	*sum = *variable1 + *variable2;
	return sum;
}
void MulDouble(const void* var1, const void* var2) {
	void* number = (void*)malloc(sizeof(double));
	double* variable1 = (double*)var1;
	double* variable2 = (double*)var2;
	double* mul = (double*)number;
	*mul = *variable1 * *variable2;
	return mul;
}
Pol InitializationDouble(uint32_t size) {
	Pol Polynomial;
	Polynomial.size = sizeof(double);
	Polynomial.max_degree = size;
	if (size > 0) {
		Polynomial.multipliers = (void**)calloc(Polynomial.max_degree, sizeof(void*));
		for (int j = 0; j < Polynomial.max_degree; j++)
			Polynomial.multipliers[j] = NullDouble();
		Polynomial.Printpoly = printPolyDouble;
		Polynomial.Zero = ComparatorZeroDouble;
		Polynomial.Addition = SumDouble;
		Polynomial.Multiplication = MulDouble;
		Polynomial.Initialization = InitializationDouble;
		return Polynomial;
	}
}