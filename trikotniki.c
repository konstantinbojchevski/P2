#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool Tri(int n){
    int stevec = 0;
    bool ima = false;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            for(int k=j+1; k<=n; k++){
                if((i+j+k) == n && pow(i, 2) + pow(j, 2) == pow(k, 2)){
                    stevec++;
                }
                if(stevec > 1){
                    ima = true;
                }
                if(ima) break;
            }
            if(ima) break;
        }
        if(ima) break;
    }
    if(ima) return 0;
    else
        return 1;
}
int main(){
    int n;
    scanf("%d", &n);
    int tab[n];
    for(int i=0; i<n; i++){
        scanf("%d", &tab[i]);
    }
    for(int i=0; i<n; i++){
        if(Tri(tab[i]))
            printf("%d", tab[i]);
    }
}