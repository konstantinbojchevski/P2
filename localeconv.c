#include <stdio.h>
#include <locale.h>
int main(){
    printf("%s\n", localeconv() -> decimal_point);
}