#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Polynomial.h"

//Functions only for one polynomial
void PrintPolynomial(const Pol* poly);
void FullPolynomial(const Pol* poly);

//Functions for one polynomial and numbers
void* ValueVariable(const Pol* poly, const void* variable);
Pol MulScalar(const Pol* poly1, const void* scalar);
Pol AddToPolynomial(const Pol* poly,const void* multiplier, uint32_t degree);

//Functions for two polynomials
Pol SumPolynomial(const Pol* pol1, const Pol* pol2);
Pol MulPolynomial(const Pol* pol1, const Pol* pol2);
#endif //FUNCTIONS_H