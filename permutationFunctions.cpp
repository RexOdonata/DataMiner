#include "permutationFunctions.h"



unsigned int * createPermutation(unsigned int size)
{
    unsigned int * permutation = new unsigned int [size];

    std::vector<int> elements(size);
    for (unsigned int i=0; i<size; i++)
    {
        elements[i]=i+1;
    }

    int random;

    for (unsigned int i=0; i<size; i++)
    {
        random=rand()%elements.size();

        permutation[i]=elements.at(random);
        elements.erase(elements.begin()+random);

    }
    return permutation;
}

unsigned int * createBasePermutation(unsigned int size)
{
    unsigned int * permutation = new unsigned int [size];

        for (unsigned int i=0; i<size; i++)
    {
        permutation[i]=i+1;

    }
    return permutation;
}

unsigned int factorial(unsigned int input)
{
    unsigned int output=0;
    for (unsigned int i=0; i<input; i++)
    {
        output=output+=(i+1);
    }
    return output;
}

unsigned int * createPermutationMatrix(unsigned int size, unsigned int * permutationPtr)
{
    int sizeOfArray=factorial(size-1);

    unsigned int * matrixPtr = new unsigned int [sizeOfArray];

    int row, col, fVal, sVal;

    for (unsigned int i=0; i<size-1; i++)
    {
        fVal=permutationPtr[i];
        for (unsigned int j=i+1; j<size; j++)
        {
            sVal=permutationPtr[j];

            if (fVal>sVal)
            {
                row=sVal-1;
                col=fVal-1;
            }
            else
            {
                col=sVal-1;
                row=fVal-1;
            }
            matrixPtr[matrixIndex(row,col,size)] = abs(int(i)-int(j));
            //printf("Storing %u at index %u aka R%u:C%u - %p\n",matrixPtr[matrixIndex(row,col,size)], matrixIndex(row,col,size), row, col, &matrixPtr[matrixIndex(row,col,size)]);
        }

    }


    return matrixPtr;
}

unsigned int compareMatrices(unsigned int size, unsigned int * baseMat, unsigned int * compMat)
{
    int arraySize = factorial(size-1);

    unsigned int total=0;

    for (int i=0; i<arraySize; i++)
    {
        total+=abs(int(baseMat[i])-int(compMat[i]));
    }
    return total;
}

unsigned int matrixIndex(int row, int col, unsigned int size)
{
    int index = col-1;

    for (int i=0; i<row; i++)
    {
        index+=size-2-i;
    }
    return index;
}

void wipePermutation (unsigned int size, unsigned int * permutationPtr)
{
    for (unsigned int i=0; i<size; i++)
    {
        permutationPtr[i]=0;
    }
}

void wipeMatrix (unsigned int size, unsigned int * arrayPtr)
{
    unsigned int arraySize=factorial(size-1);
    for (unsigned int i=0; i<arraySize; i++)
    {
        arrayPtr[i]=0;
    }
}



void printPermutation(unsigned int size, unsigned int * arrayPtr)
{
    for (unsigned int i=0; i<size; i++)
    {
        printf(" [%u] ",arrayPtr[i]);

    }
    std::cout<<"\n";
}


void printMatrix(unsigned int size, unsigned int * arrayPtr)
{

    int sizeOfArray=factorial(size-1);

    int lineTrigger=size-1;
    int cRows=0;

    for (int i=0; i<sizeOfArray; i++)
    {
        std::cout<<" ["<<arrayPtr[i]<<"] ";
        lineTrigger--;
        if (lineTrigger==0&&i!=sizeOfArray-1)
        {
            std::cout<<"\n";
            for (int j=0; j<cRows+1; j++)
            {
                printf(" [x] ");
            }
            cRows++;
            lineTrigger=size-1-cRows;
        }
    }
    printf("\n");
}


