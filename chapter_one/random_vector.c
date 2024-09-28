#include <stdlib.h> 

int* rvector(int size, int low, int high) { 
	srand(0); 
	int* vector = (int *) calloc(sizeof(int), size);  
	for(int i = 0; i < size; i++) {
		vector[i] = rand() % (high - low) + low; 
	} 
	return vector; 
} 
