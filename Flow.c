#include <stdio.h>
#include <stdlib.h>
void flow(FILE *input, FILE *output){
    int c = fgetc(input);
    while(c != EOF){
        fputc(c, output);
        printf("%c", c);
        c = fgetc(input);
    }
}
int main(){
    FILE* in = fopen("ova.txt", "r");
    FILE* out = fopen("aut.txt", "w");
    flow(in, out);
    return 0;
}