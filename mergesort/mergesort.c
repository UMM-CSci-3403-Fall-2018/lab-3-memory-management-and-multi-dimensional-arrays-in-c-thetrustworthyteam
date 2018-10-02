#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "mergesort.h"
int* merge(int* sizes, int** values) {
	int sum = 0;
        for(int i = 0; i < 2; i++) {
        sum += sizes[i];
        }
        int* destination = (int*) calloc(sum, sizeof(int));
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < sizes[0] && j < sizes[1]) {
                if(values[0][i] < values[1][j]) {
                        destination[k] = values[0][i];
                        i++;
                } else {
                        destination[k] = values[1][j];
                        j++;
                }
                k++;
        }
        while(i < sizes[0]) {
                destination[k] = values[0][i];
                i++;
                k++;
        }
        while(j < sizes[1]) {
                destination[k] = values[1][j];
                j++;
                k++;
        }
        return destination;
}

void mergesort(int size, int values[]) {
	if (size > 1) {
	int midPoint = (size/2);
	int* firstHalf = (int*) calloc(midPoint, sizeof(int));
	int* lastHalf = (int*) calloc(size-midPoint, sizeof(int));
	int j = 0;
	
        //memcpy(firstHalf, values, midPoint * sizeof(int));
	for (int i = 0; i < midPoint; i++) {
                firstHalf[i] = values[i];
        }

	for (int i = midPoint; i < size; i++) {
		lastHalf[j] = values[i];
		j++;
	}
	
	mergesort(midPoint, firstHalf);
	mergesort(size-midPoint, lastHalf);
	int sizes[2];
	sizes[0] = midPoint;
	sizes[1] = size - midPoint;
	
	// this is the 2d array 'values' in array_merge
	int* arrays[2];
	arrays[0] = firstHalf;
	arrays[1] = lastHalf;
	int* sorted = merge(sizes, arrays);

	//memcpy(values, sorted, size * sizeof(int));
	for (int i = 0; i < size; i++) {
		values[i] = sorted[i];
	}
	free(sorted);
	free(firstHalf);
	free(lastHalf);
}
}
