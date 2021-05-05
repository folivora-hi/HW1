#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#define TEST_DATA_CNT 1000000

char test_data[TEST_DATA_CNT][100];

void swap(char *a, char *b){
	char temp;
	for(int i =0; i < 100; i++){
		temp = *a;
		*a = *b;
		*b = temp;
		a++,b++;
	}
}
int Partition(int head, int tail){
	char *pivot = test_data[tail];
	int i = head -1;
	int j,k;
	for(j = head; j < tail; j++) {
		if(strcmp(test_data[j],pivot) < 0){
			i++;
			swap(test_data[i], test_data[j]);
		}
	}
	i++;
	swap(test_data[i], test_data[tail]);
	return i;
}
void quick_sort(int head,int tail){
	if(head < tail){
		int pivot = Partition(head,tail);
		quick_sort(head,pivot-1);
		quick_sort(pivot+1,tail);
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
	quick_sort(0,TEST_DATA_CNT-1);
	gettimeofday(&end, NULL);
	
	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("quick sort(str): %ld us (equal %f sec)\n", diff, diff / 1000000.0);
	return 0;
}

