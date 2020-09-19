#include <stdio.h>
int main(){
    int tab[201][201];
    for (int i=0; i<201; i++){
        for(int j=0; j<201; j++){
            tab[i][j] = 0;
        }
    }
    int *t = &tab[100][100];
    
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int h, w, s;
        scanf("%d %d %d", &h, &w, &s);
        for(int j=0; j<s; j++){
            for(int k=0; k<s; k++){
                *(t + 201*(h + j) + (w + k)) += 1;
            }
        }
    }    
    for(int k=0; k<n; k++){
        int stevec = 0;
    for(int i=0; i<201; i++){
        for(int j=0; j<201; j++){
            if(tab[i][j] == k+1){
                stevec++;
            }
        }
    }
       printf("%d\n", stevec);
    }
}