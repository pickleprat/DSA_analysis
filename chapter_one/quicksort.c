#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void view(int *nums, int size) {
	printf("( ");
	for (int i = 0; i < size; i++) {
		printf("%d ", nums[i]);
	}
	printf(")\n");
}


// two misconceptions about pivot sort 
// 1: The pivot sort is NOT responsible for swapping a pivot number to its correct index. 
//    It is simply responsible for obtaining the index in which our pivot number should be 
// 2: The pivot sort does not compare the low and the high numbers with each other, but instead 
//    with the pivot number
int pivot_sort(int *nums, int start_index, int end_index, int size ) {
	int left = start_index, right = end_index;
	int pivot_item = *(nums + end_index);

	while (left <= right) {
		while(nums[left] < pivot_item && left <= end_index ) { left++; } 
		while(nums[right] >= pivot_item && right >= start_index ) { right--; } 

		if(left < right) {
			swap(nums + left, nums + right); 
		} 
	}

	swap(nums + end_index, nums + left);
	return left; 
}

void quick_sort(int* nums, int start_index, int end_index, int size){

	if(end_index - start_index <= 0) {
		return; 
	} 

	int index = pivot_sort(nums, start_index, end_index, size); 
	quick_sort(nums, start_index, index-1, size); 
	quick_sort(nums, index+1, end_index, size); 
} 


// int main(void) {
// 	int case_a[10] = {9, 4, 3, 5, 2, 5, 67, -2, 9, 3};
// 	int case_b[5] = {100, -100, 4, 150, 200};
// 	int case_oh[2] = {1, -1};
// 	int case_c[7] = {5, 5, 9, 4, 2, 1, 6}; 
// 	int case_d[4] = {3, 1, 2, 4};  
// 	
// 	quick_sort(case_c, 0, 6, 7); 
// 	view(case_c, 7); 
//
// 	// int size; 
// 	// size = sizeof(case_a) / sizeof(int);  
// 	// quick_sort(case_a, 0, size-1);  
// 	// view(case_a, size); 
// 	//
// 	// size = sizeof(case_b) / sizeof(int);  
// 	// quick_sort(case_b, 0, size-1); 
// 	// view(case_b, size); 
// 	//
// 	// size = sizeof(case_oh) / sizeof(int);  
// 	// quick_sort(case_oh, 0, size-1); 
// 	// view(case_oh, size); 
// 	//
// 	// size = sizeof(case_c) / sizeof(int);  
// 	// quick_sort(case_c, 0, size-1); 
// 	// view(case_c, size); 
// 	//
// 	// size = sizeof(case_d) / sizeof(int);  
// 	// quick_sort(case_d, 0, size-1); 
// 	// view(case_d, size); 
// 	
// }
