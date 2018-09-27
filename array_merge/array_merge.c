#include <stdlib.h>

#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
	int sum = 0;
	for(int i = 0; i < num_arrays; i++) {
	sum += sizes[i];
	}
	int destination[sum];
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
