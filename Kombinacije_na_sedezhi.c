#include <stdio.h>
int funkcija(int n, int k){

    if(k> n/2) return 0;
    if(k == 0) return 1;
    return 1 + funkcija(n, k-1);
}
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", funkcija(n, k));
}