#include <stdio.h>
#include <stdlib.h>

void izpisiStevke(int* stevke, int stStevk) 
{
    for (int i = 0; i < stStevk; i++)
        printf("%d", stevke[i]);
}

int main() 
{
    int* stevilo = (int*) malloc(1001 * sizeof(int));
    int stevka, stStevk = 0, prenos = 0, trenutno = 0;
    char c = '.';
    while (c != ' '){
        stevilo[stStevk] = (int) c - '0';

        stevka = stevilo[stStevk];
        stStevk++;
        c = getchar();
    }

    // -1 kraj na nizata
    //stevilo[stStevk] = -1;
    printf("%d", stStevk);
    stStevk--;

    // posledna cifra

    int mnozitelj;
    scanf("%d", &mnozitelj);
   /* for (int i = (stStevk - 1); i >= 0; i--) 
    {
        trenutno = (stevilo[i] * mnozitelj) + prenos;
        if (trenutno > 9) 
        {
            prenos = trenutno / 10;
            trenutno = trenutno % 10;
        }
        else 
            prenos = 0;
            stevilo[i] = trenutno;
    }

    if (prenos != 0)
        printf("%d", prenos);
*/
    izpisiStevke(stevilo, stStevk);
    return 0;
}