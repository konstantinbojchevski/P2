#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
    int n; scanf("%d", &n);
    char* niz = malloc((n+1) * sizeof(char));
    int suma = 0, plusi = 0;
    for(int i=0; i<=n; i++){
        niz[i] = getchar();
        if(niz[i] == '+') plusi++;
    }
    int plusoj = 0;
    bool od_ova = false;
    for(int i=0; i<=n; i++){
        if(niz[i] == '+') od_ova = true;
        if(od_ova && plusoj < plusi){
            suma++;
            if(niz[i] == '+') plusoj++;
        }
    }
    printf("%d", (suma/plusi));
}