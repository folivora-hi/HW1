#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define TEST_DATA_CNT 1000000

void swap(int *a, int *b){
   	int temp = *a;
   	*a = *b;
	*b = temp;
}
void heapify(int arr[],int root,int len){
	int max = root;
	int leftChild = 2*root + 1;
	int rightChild = 2*root +2;
        if(leftChild < len && arr[leftChild] > arr[max]){
	        max = leftChild;
	}
	if(rightChild < len && arr[rightChild] > arr[max]){
	        max = rightChild;
	}
	if(max != root){
	        swap(&arr[root],&arr[max]);
	        heapify(arr,max,len);
	}
}
void heap_sort(int arr[],int len){
	int i;
   	/*Max Heap*/
   	for(i = len/2-1; i >= 0; i--){
	        heapify(arr,i,len);
	}
	/*sort*/
	for(i = len-1; i > 0; i--){
	        swap(&arr[0],&arr[i]);
	        heapify(arr,0,i);
	}
}
int main(){
	int i;
	int test_data[TEST_DATA_CNT];
	for(i = 0 ; i < TEST_DATA_CNT ; i++){
	        scanf("%d",&test_data[i]);
	}
	int len = sizeof(test_data)/sizeof(int);
	struct  timeval start;
	struct  timeval end;
	unsigned  long diff;
	gettimeofday(&start, NULL);
	heap_sort(test_data,len);
	gettimeofday(&end, NULL);
	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("heap sort(int): %ld us (equal %f sec)\n", diff, diff / 1000000.0);
	return 0;
}

