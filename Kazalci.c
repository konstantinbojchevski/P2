#include <stdio.h>
#include <string.h>
int jePalindrom(char* zbor){
    int len = strlen(zbor);
    int j = len - 1;
    for(int i=0; i<len/2; i++){
        if(zbor[i] != zbor[j]){
            return 0;
        }
        j--;
    }
    return 1;
}
void swap (int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}
int main(){
    int a = 111;
    int *b = &a;
    int **c = &b;
    int ***d = &c;
    printf("%d\n", ***d);
    printf("%d\n%d\n%d\n", sizeof(double), sizeof(char), sizeof(float));
    int j = 3, i = 5;
    int *p = &j, *q = &i;
    swap(p, q);
    printf("a=%d b=%d\n", j, i);
    char zbor[8] = "repaper";
    char zbor2[20] = "andrej";
    strcat(zbor2, zbor);
    printf("%s\n", zbor2);
    printf("%d\n", jePalindrom(zbor));
}