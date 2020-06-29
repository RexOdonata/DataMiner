#include <iostream>

#include <thread>
#include <time.h>
#include <stdlib.h>

#include <future>

#include "permutationFunctions.h"
#include "miner.h"

using namespace std;

int main()
{
    int threads;

    printf("Num Possible Threads: %u\n",std::thread::hardware_concurrency());

    printf("Threads=");
    cin>>threads;

    unsigned int maxData[threads];


    unsigned int size;

    printf("N=");
    cin>>size;

    unsigned int * baseMatrix = createPermutationMatrix(size,createBasePermutation(size));

    for (int i=0; i<threads; i++)
    {
        maxData[i]=0;
        std::thread(mineMax,size,baseMatrix,&maxData[i]).detach();
    }

    unsigned int max=0;

    while(1)
    {
        for (int i=0; i<threads; i++)
        {
            if (maxData[i]>max) max=maxData[i];
            else maxData[i]=max;
        }


    }




    return 0;
}
