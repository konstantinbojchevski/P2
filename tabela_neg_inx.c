#include <stdio.h>
#include <stdlib.h>
int main(){
    int *t = malloc(20 * sizeof(int));
    int *y = &t[10];
    for(int i=-10; i<10; i++){
        y[i] = i;
    }
    for(int i=-10; i<10; i++){
        printf("%d ", y[i]);
    }
}