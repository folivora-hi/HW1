#include <stdio.h>
#include <stdlib.h>
#define TEST_DATA_CNT 1000000
unsigned char test_data[TEST_DATA_CNT][100] = {"NULL"};
int main(){
	int i,j;
        srand(10);
	for(i = 0 ; i < TEST_DATA_CNT ; i++){
		for(j = 0; j < 100; j++){
			test_data[i][j] = rand()%26 + 'a';
		}
		printf("%s\n",test_data[i]);
	}
	return 0;
}

