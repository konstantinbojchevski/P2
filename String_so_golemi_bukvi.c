#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char* funkcija(char* str, int n){
    char* nov = malloc((n+1) * sizeof(char));

    if(islower((*(str)))){
        nov[0] = (char) toupper(*(str));
    }
    else{
        nov[0] = *(str);
    }
    printf("%c %c", nov[0], *(str + 0));
    int i=1;
    while(str[i] != '\0' || i < n){
        if(str[i] >= 97 && str[i] <=122 && str[i-1] == '_'){
             nov[i] = (char) toupper(str[i]);
        }
        else{
            nov[i] = (char) str[i];
        }
        i++;
    }
    return nov;
}
int main(){
    int n;
    scanf("%d", &n);
    char* b = malloc((n+1)* sizeof(char));
    for(int i=0; i<=n; i++){
        b[i] = getchar();
    }
    char* v = funkcija(b, n);
    for(int i=0; i<strlen(v)-1; i++){
        printf("%c", v[i]);
    }
}