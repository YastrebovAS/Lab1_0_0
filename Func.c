#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "headers.h"
//Functions only for one polynomial
void PrintPolynomial(const Pol* poly) {
	for (int j = 0; j < poly->max_degree; j++) {
		if (poly->Zero(poly->multipliers[j]) != 0) {
			printf("(");
			poly->Printpoly(poly->multipliers[j]);
			printf(")x%d", j);
			if (j < (poly->max_degree - 1))
				printf("+");
		}
	}
}
void FullPolynomial(const Pol* poly) {
	for (int j = 0; j < poly->max_degree; j++) {
		printf("(");
		poly->Printpoly(poly->multipliers[j]);
		printf(")x%d", j);
		if (j < (poly->max_degree - 1))
			printf("+");
	}
}

//Functions for one polynomial and numbers
void* ValueVariable(const Pol* poly, const void* variable){
	void* Value = poly->InitializationNULL();
	void* pointer;

	void* degree = poly->InitializationNULL();

	if (poly->Zero(variable) != 0)
		for (int i = 0; i < poly->size; i++) {
			pointer = degree;
			degree = poly->InitializationNULL();
			free(pointer);

			// degree = x
			pointer = degree;
			degree = poly->Addition(degree, variable);
			free(pointer);

			// degree = x^n = m
			for (int j = 1; j < i; j++) {
				pointer = degree;
				degree = poly->Multiplication(degree, variable);
				free(pointer);
			}

			// degree = k * m
			pointer = degree;
			degree = poly->Multiplication(degree, poly->multipliers[i]);
			free(pointer);

			// answer += degree
			pointer = Value;
			Value = poly->Multiplication(Value, degree);
			free(pointer);
		}

	return Value;
}

Pol MulScalar(const Pol* poly, const void* scalar){
	Pol Mulpoly;

	void* holder;

	if (poly->Zero(scalar) != 0) {
		Mulpoly = poly->Initialization(poly->max_degree);
		for (int i = 0; i < poly->max_degree; i++) {
			holder = Mulpoly.multipliers[i];
			Mulpoly.multipliers[i] = Mulpoly.Addition(Mulpoly.Multiplication(poly->multipliers[i],
				scalar),
				Mulpoly.multipliers[i]);
			free(holder);
		}
	}
	else {
		Mulpoly = poly->Initialization(1);
	}

	return Mulpoly;
}
Pol AddToPolynomial(const Pol* poly, const void* multiplier, int degree) {
	Pol added_element;
	void* holder;
	if (poly->max_degree < (degree + 1)) {
		added_element = poly->Initialization(degree + 1);
		for (int i = 0; i < poly->max_degree; i++) {
			holder = added_element.multipliers[i];
			added_element.multipliers[i] = poly->Addition(added_element.multipliers[i], poly->multipliers[i]);
			free(holder);
		}
		holder = added_element.multipliers[degree];
		added_element.multipliers[degree] = poly->Addition(added_element.multipliers[degree],multiplier);
		free(holder);
	}
	else {
		added_element = poly->Initialization(poly->max_degree);
		for (int i = 0; i < poly->max_degree; i++)
			memcpy(added_element.multipliers[i], poly->multipliers[i], poly->size);
		holder = added_element.multipliers[degree];
		added_element.multipliers[degree] = poly->Addition(added_element.multipliers[degree], multiplier);
		free(holder);
	}
	return added_element;
}

//Functions for two polynomials
Pol SumPolynomial(const Pol* pol1, const Pol* pol2) {
	Pol sum;
	void* holder;
	int minsize;
	const Pol* max;
	if (pol1->size == pol2->size) {
		if (pol1->max_degree < pol2->max_degree) {
			sum = pol2->Initialization(pol2->max_degree);
			minsize = pol1->max_degree;
			max = pol2;
		}
		else {
			sum = pol1->Initialization(pol1->max_degree);
			minsize = pol2->max_degree;
			max = pol1;
		}

		for (int i = 0; i < minsize; i++) {
			holder = sum.multipliers[i];
			sum.multipliers[i] = sum.Addition(pol1->multipliers[i],
				pol2->multipliers[i]);
			free(holder);
		}

		for (int i = minsize; i < sum.max_degree; i++) {
			holder = sum.multipliers[i];
			sum.multipliers[i] = sum.Addition(sum.multipliers[i],
				max->multipliers[i]);
			free(holder);
		}
	}
	return sum;
	}
Pol MulPolynomial(const Pol* pol1, const Pol* pol2){
	Pol Multiplied;

	void* pointer;

	if (pol1->size == pol2->size) {
		Multiplied = pol1->Initialization((pol1->max_degree - 1) + (pol2->max_degree - 1) + 1);
		for (int i = 0; i < pol1->max_degree; i++)
			for (int j = 0; j < pol2->max_degree; j++) {
				pointer = Multiplied.multipliers[i + j];
				Multiplied.multipliers[i + j] = Multiplied.Addition(Multiplied.Multiplication(pol1->multipliers[i],pol2->multipliers[j]),Multiplied.multipliers[i + j]);
				free(pointer);
			}
	}

	return Multiplied;
}
#endif //FUNCTIONS_H