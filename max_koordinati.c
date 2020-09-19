#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int tabela[300][300];
int stetje[1001];
int main(){

    int n; scanf("%d", &n);
    int** tab = malloc (n* sizeof(int*)); int maxy=-101; int miny = 101; int maxx = -101; int minx=101; int maxDolu =-1;
    for(int i=0; i<n; i++){
        tab[i] = malloc (3*sizeof(int));
        scanf("%d%d%d", &tab[i][0], &tab[i][1], &tab[i][2]);
        if(tab[i][0]>maxy) maxy = tab[i][0]; if(tab[i][0]<miny) miny = tab[i][0];
        if(tab[i][1]>maxx) maxx = tab[i][1]; if(tab[i][1]<minx) minx = tab[i][1];
        if(tab[i][2]>maxDol) maxDolu = tab[i][2];
    }
    
    if(miny<0 || minx<0){
        if(miny < 0){ int diff = -1*miny;
            for(int i=0; i<n; i++){tab[i][0] = tab[i][0]+diff;}
        }if(minx<0){int diff = -1*minx;
            for(int i=0; i<n; i++){tab[i][1] = tab[i][1]+diff;}
        }
    }else if(maxy>0 || maxx>0){
        if(maxy > 0){
            int diff = -1*maxy;
            for(int i=0; i<n; i++){tab[i][0] = tab[i][0]+diff;}
        }if(maxx>0){
            int diff = -1*maxx;
            for(int i=0; i<n; i++){tab[i][1] = tab[i][1]+diff;}
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=tab[i][0]; j<tab[i][2]+tab[i][0]; j++){
            for(int k=tab[i][1]; k<tab[i][2]+tab[i][1]; k++){
                tabela[j][k] +=1;                
            }
        }
    }   
    
    for(int i=0; i<200; i++){
        for(int j=0; j<200; j++){
            stetje[tabela[i][j]]+=1;
        }
    }
    for(int i=1; i<=n; i++)
        printf("%d\n", stetje[i]);
    
    for(int i=0; i<n; i++)
        free(tab[i]);
    free(tab);
    
    return 0;
}