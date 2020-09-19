#include <stdio.h>
int x_coordinata(int* arr, int w, int n, int h){
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(*(arr + (w*i) + j) == n) return i;
        }
    }
}
int y_coordinata(int* arr, int w, int n, int h){
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(*(arr + (w*i) + j) == n) return j;
        }
    }
}
int main(){
    int h, w, gorivo;
    scanf("%d %d %d", &h, &w, &gorivo);
    int tab[h][w];
    int trenutno_i, trenutno_j;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            scanf("%d", &tab[i][j]);
            if(tab[i][j] == 0){
                trenutno_i = i;
                trenutno_j = j ;
            }
        }
    }
    int pot = 0;
    int ovdde= 1;
    int vratioi = trenutno_i;
    int vrati_j = trenutno_j;
    while(pot <= gorivo && ovdde != h*w - 1){
        vratioi = trenutno_i;
         vrati_j = trenutno_j;
        trenutno_i = x_coordinata((int*) tab, w, ovdde, h);
        trenutno_j = y_coordinata((int*) tab, w, ovdde, h);
        pot = trenutno_i + trenutno_j;
        gorivo -= pot;
        ovdde++;
    }
    if(ovdde == (w*h -1) ) printf("%d", ovdde);
    if(gorivo < pot)
    printf("%d", tab[vratioi][vrati_j]);
}