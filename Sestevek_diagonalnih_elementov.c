#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d\n", &n);
    int matrika[n][n];
    /*int velikost = n*n;
    int *matrika = malloc(velikost * sizeof(int));
    */
    int *maksimumi = calloc(n, sizeof(int));
    int indeksi[n];
    int seshtevek = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matrika[i][j]);
            if(maksimumi[j] < matrika[i][j]){
                maksimumi[j] = matrika[i][j];
                indeksi[j] = i;
            }
            if(i == j) seshtevek += matrika[i][j];
            printf(" ");
        }
        printf("\n");
    }
    printf("%d\n", seshtevek);
    for(int i=0; i<n; i++){
        printf("element: %d vrstica: %d\n", maksimumi[i], (indeksi[i]+1));
    }
}