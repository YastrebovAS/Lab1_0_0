#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <stdint.h>
typedef struct Polynomial {
	void** multipliers;
	uint32_t max_degree;
	uint8_t size;
	void* (*Printpoly)(const void*);
	int* (*Zero)(const void*);
	void* (*InitializationNULL)();
	void* (*Addition)(const void*);
	void* (*Multiplication)(const void*);
	struct Polynomial(*Initialization)(uint32_t);
}Pol;
#endif //POLYNOMIAL_H