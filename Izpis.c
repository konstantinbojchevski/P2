#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void rekurzija(int i, int n){
    if(i > n)
        return;
    else
    {
        printf("%d ", i);
        rekurzija(i+1, n);
    }
}

int rekurzija1(int n){
    if(n <= 1)
        return n;
    return n + rekurzija1(n-1);
}
static int tolko = 0;
int rekurzija2(int n){
    if(n == 0){
        return tolko;
    }
    else{
        if(n%10 == 5) tolko++;
        rekurzija2(n/10);
    }
}

void rekurzija3(int i, int tab[], int n){
    if(i >= n)
        return;
    printf("%d ", tab[i]);
    rekurzija3(i+1, tab, n);
}
static int max = -9999, i = 0;
int rekurzija4(int tab[], int n){
    if(i < n){
        if(max < tab[i])
         max = tab[i];
         i++;
         rekurzija4(tab, n);
    }
    return max;
}

int rekurzija5(int n){
    if(n == 1)
        return 1;
    return n * rekurzija5(n-1);
}

int rekurzija6(int tab[], int n){
    if(n <=0)
        return 0;
    if(n % 2 == 0){
        return rekurzija6(tab, n-1) - tab[n-1];
    }
    else
    {
        return rekurzija6(tab, n-1) + tab[n-1];
    }
}

int rekurzija7(int n){
    if(n % 7 == 0 ) return 44;
    if(n < 0 && n % 7 != 0){
        return rekurzija7(87) - rekurzija7(5* n);
    }
    else{
        return 13 * rekurzija7(n-1);
    }
}
static int vsota = 0;
bool jePrastevilo(int n){
    int a= 1;
    for(int i=1; i<n; i++){
        if(n % i == 0) a++;
    }
    if(a == 2){
        return 1;
    }
    else
        return 0;
}
int rekurzija8(int n){
    if(n <= 0)
        return 0;
    
    if( jePrastevilo(n))
    vsota += n;
    rekurzija8(n-1);
    return vsota;
}

bool rekurzija9(char niz[], int n, int i){
    if(i == n)
        return true;
    if(niz[i] != niz[n])
    return false;
    if(i < n+1 ){
        return rekurzija9(niz, n-1, i+1);
    }
    return true;
}
bool jePalindrom(char str[]){

    int n = strlen(str);
    if(n == 0)
        return true;
    return rekurzija9(str, n-1, 0);
}

int main(){
    int n;
    scanf("%d", &n);
    int t[n];
    int i=0;
    char stt[] = "lsaasl";
    /*for(int i=0; i<n; i++){
        scanf("%d", &t[i]);
   */// }
    //rekurzija3(0, t, n);
    if(jePalindrom(stt)) printf("y");
    else printf("jh");
    //printf("%d",  rekurzija8(n));
}