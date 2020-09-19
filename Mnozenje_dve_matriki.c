#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	int** matrika1 = malloc(m * sizeof(int*));
	for(int i = 0; i < m; i++){
		matrika1[i] = malloc(n * sizeof(int));
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &matrika1[i][j]);
		}
	}

	int r, q;
	scanf("%d %d", &r, &q);

	int** matrika2 = malloc(r * sizeof(int*));
	for(int i = 0; i < r; i++){
		matrika2[i] = malloc(q * sizeof(int));
	}

	for(int i = 0; i < r; i++){
		for(int j = 0; j < q; j++){
			scanf("%d", &matrika2[i][j]);
		}
	}

	printf("MATRIKA1:\n");
	for(int i = 0; i < m; i++){
		//printf("%d %d %d %d\n", m, n, r, q);
		for(int j = 0; j < n; j++){
			printf("%d ", matrika1[i][j]);
		}
		printf("\n");
	}
	printf("MATRIKA2:\n");
	for(int i = 0; i < r; i++){
		for(int j = 0; j < q; j++){
			printf("%d ", matrika2[i][j]);
		}
		printf("\n");
	}
	int** rezultat = malloc(m * sizeof(int*));
	for(int i = 0; i < m; i++){
		rezultat[i] = malloc(q * sizeof(int));
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < q; j++){
			//rezultat[i][j]
			int clen = 0;
			for(int k = 0; k < n /*==r*/; k++){
				//printf("%d * %d = ?", matrika1[i][k], matrika2[k][j]);
				clen += (matrika1[i][k] * matrika2[k][j]);
				//printf("clen = %d, ", clen);
			}

			rezultat[i][j] = clen;
		}
	}
	printf("REZULTAT:\n");
	for(int i = 0; i < m; i++){
		for(int j = 0; j < q; j++){
			printf("%d ", rezultat[i][j]);
		}
		printf("\n");
	}
	for(int i = 0; i < m; i++){
		free(matrika1[i]);
	}
	free(matrika1);
	for(int i = 0; i < r; i++){
		free(matrika2[i]);
	}
	free(matrika2);
	for(int i = 0; i < m; i++){
		free(rezultat[i]);
	}
	free(rezultat);
	return 0;
}