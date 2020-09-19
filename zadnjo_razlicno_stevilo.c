#include <stdio.h>
int main(){
    int prejsno, trenutno;
    scanf("%d", &prejsno);
    char c = getchar();
    while(c != '\n'){
        scanf("%d", &trenutno);
        if((prejsno < 0 && trenutno > 0) || (prejsno > 0 && trenutno < 0)){
            printf("%d\n", prejsno);
        }
        prejsno = trenutno;
        c = getchar();
    }
    printf("%d", prejsno);
    return 0;
}