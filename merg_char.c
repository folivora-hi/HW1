#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define TEST_DATA_CNT 1000000
char test_data[TEST_DATA_CNT + 5][105];
char left[TEST_DATA_CNT/2][105],right[TEST_DATA_CNT/2][105];
void merge(int head,int mid,int tail){
	int lenL = mid - head + 1;
	int lenR = tail - mid;
	int i,j,k;

	for(i = 0; i < lenL; i++){
		strcpy(left[i],test_data[head + i]);
	}
	for(j = 0; j < lenR; j++){
	        strcpy(right[j],test_data[mid + 1 + j]);
	}
	i = 0,j = 0, k = head;
	//printf("merge1\n");
	while (i < lenL && j < lenR){
		//printf("while1\n");
	        if (strcmp(left[i],right[j]) < 0){
			//printf("while2\n");
	        	strcpy(test_data[k],left[i]);
			//printf("while3\n");
	        	i++;
			//printf("while4\n");
		}
		else{
			strcpy(test_data[k],right[j]);
			//printf("while6\n");
			j++;
			//printf("while7\n");
		}
		//printf("while8\n");
		k++;
	}
	//printf("merge2\n");
	while (i < lenL){
		strcpy(test_data[k],left[i]);
		k++;
		i++;
	}
	//printf("merge3\n");
	while (j < lenR){
	        strcpy(test_data[k],right[j]);
		k++;
		j++;
	}
	//printf("merge4\n");
}
void merge_sort(int head, int tail){
	if(head < tail){
	        int mid = (head + tail) / 2;
	        merge_sort(head, mid);
	        merge_sort(mid+1, tail);
	        merge(head, mid, tail);
	}
}
int main(){
	int i;
	for(i = 0 ; i < TEST_DATA_CNT ; i++){
	        scanf("%s",test_data[i]);
	}
	struct  timeval start;
	struct  timeval end;
	unsigned  long diff;
	gettimeofday(&start, NULL);
	merge_sort(0,TEST_DATA_CNT-1);
	gettimeofday(&end, NULL);
	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	
	printf("merge sort(string): %ld us (equal %f sec)\n", diff, diff / 1000000.0);

	return 0;
}

