#include <stdio.h>
static int poseteni[1000];
static int a, b;
int rekurzija(int n){
    if(n == 0){
        if(poseteni[n] == 0){
            poseteni[n] = 1;
        }
        return 1;
    }
    else{
        if(poseteni[n] == 0) poseteni[n] = 1;
        return rekurzija((n/a)) + rekurzija((n/b));
    }
}
int main(){
    int n;
    int stevec = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &n);
    int k = rekurzija(n);
    for(int i=0; i<1000; i++){
        if(poseteni[i] > 0){
            stevec ++;
        }
    } 
    printf("%d", stevec);
}