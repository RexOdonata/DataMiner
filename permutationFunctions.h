#ifndef PERMUTATIONFUNCTIONS_H
#define PERMUTATIONFUNCTIONS_H


#include <vector>
#include <stdlib.h>
#include <iostream>
#include <cmath>

unsigned int * createPermutation(unsigned int size);

unsigned int * createBasePermutation(unsigned int size);

unsigned int * createPermutationMatrix(unsigned int size, unsigned int * permutationPtr);

unsigned int compareMatrices(unsigned int size, unsigned int * baseMat, unsigned int * compMat);

unsigned int matrixIndex(int row, int col, unsigned int size);

unsigned int factorial(unsigned int input);

void wipePermutation (unsigned int size, unsigned int * permutationPtr);

void wipeMatrix (unsigned int size, unsigned int * permutationPtr);

void printPermutation(unsigned int size, unsigned int * arrayPtr);

void printMatrix(unsigned int size, unsigned int * arrayPtr);



#endif // PERMUTATIONFUNCTIONS_H
