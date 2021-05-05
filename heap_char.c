#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#define TEST_DATA_CNT 1000000
char test_data[TEST_DATA_CNT][100];
void swap(char *a, char *b){
	char temp;
	for(int i = 0; i < 100; i++){
	        temp = *a;
	        *a = *b;
	        *b = temp;
	        a++,b++;
	}
}
void heapify(int root,int size){
	int max = root;
	int leftChild = 2*root + 1;
	int rightChild = 2*root +2;
        if(leftChild < size && strcmp(test_data[leftChild],test_data[max]) > 0){
	        max = leftChild;
	}
	if(rightChild < size && strcmp(test_data[rightChild],test_data[max]) > 0){
	        max = rightChild;
	}
	if(max != root){
	        swap(test_data[root],test_data[max]);
	        heapify(max,size);
	}
}
void heap_sort(int size){
	int i;
	for(i = size/2-1; i >= 0; i--){
	        heapify(i,size);
	}
	for(i = size-1; i > 0; i--){
	        swap(test_data[0],test_data[i]);
	        heapify(0,i);
	}
}
int main(){
	int i;
	for(i = 0 ; i < TEST_DATA_CNT ; i++){
		scanf("%s",test_data[i]);
	}
	int size = sizeof(test_data)/sizeof(test_data[0]);
	struct  timeval start;
	struct  timeval end;
	unsigned  long diff;
	gettimeofday(&start, NULL);
	heap_sort(size);
	gettimeofday(&end, NULL);
	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("heap sort(str): %ld us (equal %f sec)\n", diff, diff / 1000000.0);
	return 0;
}

