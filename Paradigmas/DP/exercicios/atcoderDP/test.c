#include <stdio.h>

int n = 100000;

int main(){
	printf("%d %d %d %d\n", n, n - 1, 1, n);

	for(int i = 1 ; i <= n - 1 ; i++){
		printf("%d %d\n", i, i + 1);
	}

	printf("\n");

	return 0;
}