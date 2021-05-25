#include "headers.h"
static void printPolyInt(const void* variable){
	printf("%d", *((int*)variable));}

int ComparatorZeroInt(const void* variable) {
	int* pointer = (int*)variable;
	if (*pointer == 0)
	return 0;
	else if (*pointer < 0)
	return 1;
	else if (*pointer > 0)
	return -1;
}
static void* NullInt(){
		void* answer = (void*) malloc(sizeof(int));

		int* pointer = (int*)answer;
	*pointer=0;
	return answer;
}


void SumInt(const void* var1, const void* var2){
	void* number = (void*)malloc(sizeof(int));
	int* variable1 = (int*)var1;
	int* variable2 = (int*)var2;
	int* sum = (int*)number;
	*sum = *variable1 + *variable2;
	return sum;
}
void MulInt(const void* var1, const void* var2){
	void* number = (void*)malloc(sizeof(int));
	int* variable1 = (int*)var1;
	int* variable2 = (int*)var2;
	int* mul = (int*)number;
	*mul = *variable1 * *variable2;
	return mul;
}
Pol InitializationInt(uint32_t size){
	Pol Polynomial;
	Polynomial.size = sizeof(int);
	Polynomial.max_degree = size;
	if (size > 0) {
		Polynomial.multipliers = (void**)calloc(Polynomial.max_degree, sizeof(void*));
		for (int j = 0; j < Polynomial.max_degree; j++)
			Polynomial.multipliers[j] = NullInt();
	}
	Polynomial.Printpoly = printPolyInt;
	Polynomial.Zero = ComparatorZeroInt;
	Polynomial.Addition = SumInt;
	Polynomial.Multiplication = MulInt;
	Polynomial.Initialization = InitializationInt;
	return Polynomial;
}