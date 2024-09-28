#include "quicksort.c" 
#include <stdlib.h> 
#include <time.h> 
#include "random_vector.c"

int kth_smallest_sorting(int* nums, int size, int k) {
	quick_sort(nums, 0, size-1, size); 
	return nums[size - k]; 
} 

int kth_smallest_selection(int* nums, int size, int k) {
	int* store = calloc(sizeof(int), k); 
	for(int i = 0; i < k; i++) {
		store[i] = nums[i]; 
	}; 

	quick_sort(store, 0, k-1, k); 

	for(int i = k; i < size; i++) {
		int j = 0; 
		if(nums[i] > store[j]) {
			while(store[j] < nums[i] && j < k) {
				j++; 
			}

			for(int m = 1; m < j; m++) {
				store[m-1] = store[m]; 
			} 

			store[j - 1] = nums[i]; 
		} 
	} 

	return store[0]; 
} 


int main(void) {
	int sizes[10] = {100, 200, 500, 1000, 2000, 10000, 50000, 100000, 200000, 250000};  
	int* vector; 
	double begin, end; 
	for(int i = 0; i < 10; i++) {
		vector = rvector(sizes[i], 0, 1000000); 
		begin = clock(); 
		int sorting_output = kth_smallest_sorting(vector, sizes[i], sizes[i]/2); 
		end = clock(); 

		printf("The time elapsed for sorting : %lf\n", (double) (end - begin) / CLOCKS_PER_SEC); 
		
		begin = clock(); 
		int selection_output = kth_smallest_selection(vector, 0, sizes[i] / 2); 
		end = clock(); 

		printf("The time elapsed for selection : %lf\n",(double) (end - begin) / CLOCKS_PER_SEC ); 
		if(sorting_output != selection_output) {
			printf("The sorting output %d is not equal to the selection output %d\n", sorting_output, selection_output);  
		} else {
			printf("The tests ran successfully! The results are above\n"); 
		} 

	}
} 
