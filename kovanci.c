#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nacini(int n, int k){
	if(k < 0){
		return 0;
	}
	else if(n == 0){
		return 1;
	}

	int edinica = nacini(n-1, k+1);
	int dvojka = nacini(n-1, k-1);

	return edinica + dvojka;
}

int main() {
	int n, int k;
	scanf("%d %d", &n, &k);

	printf("%d", nacini(n,k));
	return 0;
}