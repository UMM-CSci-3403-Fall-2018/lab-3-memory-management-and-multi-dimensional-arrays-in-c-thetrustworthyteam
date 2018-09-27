#include <stdlib.h>
#include <string.h>

#include "../array_merge/array_merge.h"
#include "mergesort.h"

void mergesort(int size, int values[]) {
	if (size > 1) {
	int midPoint = (size/2);
	int firstHalf[midPoint];
	int lastHalf[size-midPoint];
	int j = 0;
	
        memcpy(firstHalf, values, midPoint * sizeof(int));
		for (int i = midPoint + 1; i < size; i++) {
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
	int* sorted = array_merge(2, sizes, arrays);	

	memcpy(values, sorted, size * sizeof(int));
	}	
}
