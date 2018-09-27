#include <stdlib.h>

#include "array_merge.h"
#include "mergesort.h"

void mergesort(int size, int values[]) {
	if (size > 1) {
	int midPoint = (size/2);
	int firstHalf[midPoint];
	int lastHalf[size-midPoint];
	int j = 0;
	
        memcpy(firstHalf, values, midPoint * sizeof(int));
		for (i = midPoint + 1; i < size; i++) {
		lastHalf[j] = values[i];
		j++;
		}
	}

	mergesort(midPoint, firstHalf);
	mergesort(size-midPoint, lastHalf);
	// call array_merge here
}
