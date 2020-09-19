#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(){
    char* tabela = malloc(2*sizeof(char));
    int velikostTabele = 2;
    char c = getchar();
    char g;
    bool h = true;
    int indeks = 0;
    while(1){
       // if(c >= 97 && c <= 122){
            tabela[indeks] = c;
            if(indeks+1 == velikostTabele - 1){
                velikostTabele *= 2;
                tabela = realloc(tabela, velikostTabele*sizeof(char));
            }
           
            if(tabela[indeks] == 'a' && tabela[indeks-1] == 't' && tabela[indeks-2] == 'e'){
                h = false;
                break;
            } 
     /*      printf("%c", tabela[indeks]);
       */    
            indeks++;
            g = getchar();
            c = getchar();
       //}
    }
   // printf("%c", tabela[indeks-3]);
    //tabela[indeks-2] = '\0';
    for(int i=0; i<indeks-2; i++){
        if(!isdigit(tabela[i])){
            printf("%c", tabela[i]);
        }
    }
}