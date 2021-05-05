#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define TEST_DATA_CNT 1000000
void merge(int arr[],int head,int mid,int tail){
	int lenL = mid - head + 1;
	int lenR = tail - mid;
	int left[lenL+1],right[lenR+1];
	int i,j,k;
	for(i = 0; i < lenL; i++){
		left[i] = arr[head + i];
	}
	for(j = 0; j < lenR; j++){
	        right[j] = arr[mid + 1 + j];
	}
	i = 0,j = 0, k = head;
	while (i < lenL && j < lenR){
	        if (left[i] <= right[j]){
		        arr[k] = left[i];
		        i++;
		}
		else{
		        arr[k] = right[j];
		        j++;
		}
		k++;
	}
	while (i < lenL){
	        arr[k] = left[i];
	        k++;
	        i++;
	}
	while (j < lenR){
		arr[k] = right[j];
		k++;
		j++;
	}
}
void merge_sort(int arr[], int head, int tail){
	if(head < tail){
		int mid = (head + tail) / 2;
		merge_sort(arr, head, mid);
		merge_sort(arr, mid+1, tail);
		merge(arr, head, mid, tail);
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
	merge_sort(test_data,0,TEST_DATA_CNT-1);
	gettimeofday(&end, NULL);
	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("merge sort(int): %ld us (equal %f sec)\n", diff, diff / 1000000.0);
	return 0;
}

