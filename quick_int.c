#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define TEST_DATA_CNT 100000
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(int *arr, int head, int tail){
	int pivot = arr[tail];
	int i = head -1;
	for (int j = head; j < tail; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	i++;
	swap(&arr[i], &arr[tail]);
	return i;
}
void quick_sort(int arr[],int head,int tail){
	if(head < tail){
		int pivot = Partition(arr,head,tail);
	        quick_sort(arr,head,pivot-1);
	        quick_sort(arr,pivot+1,tail);
	}
}
int main(){
	int i;
	int test_data[TEST_DATA_CNT + 5];
	for(i = 0 ; i < TEST_DATA_CNT ; i++){
	        scanf("%d",&test_data[i]);
	}
	struct  timeval start;
	struct  timeval end;
	unsigned  long diff;
	gettimeofday(&start, NULL);
	quick_sort(test_data,0,TEST_DATA_CNT-1);
	gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("quick sort(int): %ld us (equal %f sec)\n", diff, diff / 1000000.0);
	return 0;
}

