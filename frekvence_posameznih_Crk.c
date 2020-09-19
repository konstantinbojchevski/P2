#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* frekvenceCrk(char* niz) {
    // dopolnite ...
    int *frekvence = (int*)calloc(26,sizeof(int));
    
    while(*niz != '\0'){
    	if(*niz >= 65 && *niz <= 90) {
    		*(frekvence + (*niz - 65)) += 1;
    	}
    	if(*niz >= 97 && *niz <= 122) {
    		*(frekvence + (*niz - 97)) += 1;
    	}
    	
    	niz++;
    }
    return frekvence;
}

int main() {
    // koda za ro"cno testiranje (po "zelji)
    int* r = calloc(26, sizeof(int));
    char str[] = "bAnaNa";
    r = frekvenceCrk(str);
    for(int i=0; i<26; i++){
        printf("%d", r[i]);
    }
    return 0;
}