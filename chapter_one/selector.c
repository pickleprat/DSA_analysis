#include "quicksort.c" 
#include <stdlib.h> 
#include <time.h> 
#include "random_vector.c"

// k = 50 
int kth_smallest_sorting(int* nums, int size, int k) {
	quick_sort(nums, 0, size-1, size); 
	return nums[size - k]; 
} 

void insert_sorted(int number, int* store, int size) {
	int i = 0; 
	while( store[i] < number && i < size ) { i++; } 
	i--; 
	for(int j = 0; j < i; j++) {
		store[j] = store[j+1]; 
	} 
	
	store[i] = number; 
} 


int kth_smallest_selection(int* nums, int size, int k) {
	int* store = (int* ) calloc(sizeof(int), k); 

	for(int i = 0; i < k; i++) { 
		store[i] = nums[i]; 
	} 

	quick_sort(store, 0, k-1, k); 
	
	for(int i = k; i < size; i++) {
		if(nums[i] > store[0]) {
			insert_sorted(nums[i], store, k); 
		} 

	} 

	return store[0]; 
} 

int main(void) {
	int sizes[10] = {100, 200, 300, 1000, 2000, 10000, 50000, 100000, 600000, 700000};  
	int* vector; 
	double begin, end; 
	int error = 0; 
	for(int i = 0; i < 10; i++) {
		
		vector = rvector(sizes[i], 0, 1000000); 
		printf("================================================================\n"); 
		printf("Test %d: element count: %d\n", i + 1, sizes[i]); 


		begin = clock(); 
		int selection_output = kth_smallest_selection(vector, sizes[i], sizes[i] / 2); 
		end = clock(); 

		printf("The time elapsed for selection : %lf s\n",(double) (end - begin) / CLOCKS_PER_SEC ); 


		begin = clock(); 
		int sorting_output = kth_smallest_sorting(vector, sizes[i], sizes[i]/2); 
		end = clock(); 

		printf("The time elapsed for sorting : %lf s\n", (double) (end - begin) / CLOCKS_PER_SEC); 
		
		if(sorting_output != selection_output) {
			error = 1; 
			printf("ERROR: The sorting output %d is not equal to the selection output %d\n", sorting_output, selection_output);  
		}
		printf("=====================================================================\n");
	}

	if(error == 0) {
		printf("The test succeeded!\n"); 
	} 
		

	
} 
