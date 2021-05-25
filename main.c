#include "headers.h"
int main() {
	int TermNumber;
	Pol pol1 = InitializationInt(1);
	Pol pol2 = InitializationDouble(1);
	int degree;
	double multiplier;
	void** pointer;
	int oldSize;
	printf("Write num of terms in first Polynomial:");
	scanf("%u", &TermNumber);
	for (int n = 0; n < TermNumber; n++) {
		printf("Write degree of the %d term:",n);
		scanf("%u", &degree);
		printf("Write multiplier of the % d term : ",n);
		scanf("%u", &multiplier);
		oldSize = pol1.max_degree;
		pointer = pol1.multipliers;
		pol1 = AddToPolynomial(&pol1, &multiplier, &degree);
		for (int k = 0; k < oldSize; k++)
			free(pointer[k]);
		free(pointer);
	}
	printf("Write num of terms in second Polynomial:");
	scanf("%u", &TermNumber);
	for (int n = 0; n < TermNumber; n++) {
		printf("Write degree of the %d term:", n);
		scanf("%u", &degree);
		printf("Write multiplier of the % d term : ", n);
		scanf("%u", /*&*/multiplier);
		oldSize = pol2.max_degree;
		pointer = pol2.multipliers;
		pol2 = AddToPolynomial(&pol2, &multiplier, &degree);
		for (int k = 0; k < oldSize; k++)
			free(pointer[k]);
		free(pointer);
	}
	printf("First Polynomial:");
	PrintPolynomial(&pol1,"\n");
	printf("Second Polynomial:");
	PrintPolynomial(&pol2, "\n");


	oldSize = pol2.max_degree;
	pointer = pol2.multipliers;
	pol2 = MulPolynomial(&pol1, &pol2);
	for (int k = 0; k < oldSize; k++)
		free(pointer[k]);
	free(pointer);
	printf("Polynomials multiplied");
	PrintPolynomial(&pol2, "\n");


	printf("Write the number by which you want to multiply:");
	scanf("%u", &multiplier);
	oldSize = pol2.max_degree;
	pointer = pol2.multipliers;
	pol2 = MulScalar(&pol2, &multiplier);
	for (int k = 0; k < oldSize; k++)
		free(pointer[k]);
	free(pointer);

	printf("Polynomial and scalar multiplied");
	PrintPolynomial(&pol2, "\n");

	printf("Write the number for calculating a polynomial");
	scanf("%u", &multiplier);
	void* val;
	double* valdouble;
	oldSize = pol2.max_degree;
	pointer = pol2.multipliers;
	val = ValueVariable(&pol2, &multiplier);
	for (int k = 0; k < oldSize; k++)
		free(pointer[k]);
	free(pointer);
	valdouble = (double*)val;
	
	printf("Calculated value = %lf \n",valdouble);
	return 0;
}