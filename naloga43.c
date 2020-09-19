#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* table = malloc(2 * sizeof(int));

	int num = 0;
	int ix = 0;
	int tableSize = 2;

	scanf("%d", &num);
	while(num != -1){
		if(ix == tableSize - 1){
			tableSize *= 2;
			table = realloc(table, tableSize * sizeof(int));
		}
		table[ix] = num;

		ix++;
		scanf("%d", &num);
	}

	float povprecje = 0;

	printf("[");
	for(int i = 0; i < ix; i++){
		povprecje += table[i];

		if(i == 0){
			printf("%d", table[i]);
		} else {
			printf(", %d", table[i]);
		}

	}
	printf("]\n");

	povprecje = povprecje / ix;
	printf("%f\n", povprecje);

	free(table);
	return 0;
}