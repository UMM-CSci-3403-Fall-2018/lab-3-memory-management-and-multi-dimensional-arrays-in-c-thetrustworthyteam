#include <stdlib.h>

#include "array_merge.h"
#include "../mergesort/mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
	int sum = 0;
	for(int i = 0; i < num_arrays; i++) {
	sum += sizes[i];
	}

	if(sum <= 0) {
	  int* result = (int*) calloc(1, sizeof(int));
	  return result;
	}
	
	int* destination = (int*) calloc(sum, sizeof(int));

	// combine all values into one array, including duplicates
	int k = 0;
	for(int i = 0; i < num_arrays; i++) {
	  for(int j = 0; j < sizes[i]; j++) {
	    destination[k] = values[i][j];
	    k++;
	  }
	}

	// sort values
	mergesort(sum, destination);

	// remove duplicates
	int duplicates = 0;
	for(int i = sum - 1; i > 0; i--){
	  // set duplicates out of bounds
	  if (destination[i] == destination[i-1]) {
	    destination[i] = -1;
	    duplicates++;
	  }
	}

	int* finalDestination = (int*) calloc(sum - duplicates + 1, sizeof(int));

	for(int i = 0, j = 1; i < sum; i++) {
	  if(destination[i] != -1) {
	    finalDestination[j] = destination[i];
	    j++;
	  }
	}

	free(destination);

	// put the number of elements at index 0
	finalDestination[0] = sum - duplicates;
	
	return finalDestination;
}
