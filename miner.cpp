#include "miner.h"

void mineMax(unsigned int size, unsigned int * baseArray, unsigned int * data)
{
    unsigned int * permutation;

    unsigned int * matrix;

    unsigned int difference;

    while (1)
    {

        permutation = createPermutation(size);

        matrix = createPermutationMatrix(size, permutation);


        difference = compareMatrices(size,baseArray,matrix);

        if (difference>(*data))
        {
            *data=difference;
            printf("New Max found: %u\n",difference);
            printPermutation(size,permutation);
        }
        delete matrix;
        delete permutation;

    }




}
