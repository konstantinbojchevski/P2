#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int steviloinKta(char* niz, int k, int* indeks){
    int i = 0;
    int crka = (int) niz[i];
    if((strlen(niz) - 1) < k){
        return -1;
    }
    else{
    int ind = 0;
      while(crka != '\0'){
         if(65 <= crka && crka <= 92){
            if(ind == k){
                *indeks = i;
                printf("%d", i);
            }
            ind++;
        }
            i++;
            crka = niz[i];
        }
    return *indeks;
    }    
}

int* indeksi(char* niz){
    int f; int ind = 0;
    int* t = malloc(strlen(niz) * sizeof(int));
    for(int i=strlen(niz); i>0; i--){
        f =niz[i];
        if(f >= 65 && f <= 92){
            t[ind] = i-1;
            ind++;
        }
    }
    t[ind] = -1;
    //*y = t;
    return t;
}

int main(){
    char* niz = "testOOs";
    int* indeks = malloc(7* sizeof(int));
    indeks = indeksi(niz);
    for(int i=0; i<strlen(indeks); i++){
        printf("%d", indeks[i]);
    }
    printf("%d", steviloinKta(niz, 2, indeks));
}