#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int tab[n];
    for(int i=0; i<n; i++){
        scanf("%d", &tab[i]);

    }
    int naj = 0, s = 0, this = 0;
    for(int i=0; i<n; i++){
        this = tab[i];
        s = 1;
        for(int j=i+1; j<n; j++){
            if(this % tab[j] == 0){
                s++;
                this = tab[j];
            }
        }
        if(s > naj){
            printf("%d", i);
            naj = s;
        }
    }
    printf("%d", naj);
}