#include <stdio.h>
#include <stdlib.h>
#define TEST_DATA_CNT 1000000
int main(){
    int i;
    int test_data[TEST_DATA_CNT];
    srand(10);
    for(i = 0 ; i < TEST_DATA_CNT ; i++){
	test_data[i] = rand();
	printf("%d\n",test_data[i]);
    }
    return 0;
}
