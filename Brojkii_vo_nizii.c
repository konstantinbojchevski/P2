#include <stdio.h>
#define MAX 201
int main(){
    int tab[MAX];
    for(int i=0; i<MAX; i++){
        tab[i] = 0;
    }
    int *p = &tab[100];
    int n, m;
    scanf("%d", &n);
    int tab1[n];
    for(int i=0; i<n; i++){
        scanf("%d", &tab1[n]);
        *(p + tab1[n]) += 1;
    }
    scanf("%d", &m);
    int tab2[m];
    for(int i=0; i<m; i++){
        scanf("%d", &tab2[m]);
        *(p + tab2[m]) += 1;
    }
    for(int i=0; i<MAX; i++){
        if(tab[i] > 0){
            printf("%d\n", -(100-i));
        }
    }
}