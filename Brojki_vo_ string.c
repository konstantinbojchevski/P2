#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() 
{
    int vsotaSamostojnih = 0, trenutnaVsota = 0;
    char trenutni;
    bool presledek = true;

    while ((trenutni = getchar()) != '\n') 
    {
        if (presledek && trenutni <= '9' && trenutni >= '0') 
        {
            trenutni = trenutni - '0';
            trenutnaVsota = trenutnaVsota * 10 + trenutni;
            trenutni = getchar();
            while (trenutni <= '9' && trenutni >= '0') 
            {
                trenutni = trenutni - '0';
                trenutnaVsota = trenutnaVsota * 10 + trenutni;
                trenutni = getchar();
            }
            if (trenutni == ' ') 
            {
                vsotaSamostojnih += trenutnaVsota;
                trenutnaVsota = 0;
                presledek = true;
            }
            else if (trenutni == '\n')  
            {
                vsotaSamostojnih += trenutnaVsota;
                trenutnaVsota = 0;
                break;
            }
            else 
            {
                trenutnaVsota = 0;
                presledek = false;
            }  
        }
        else if (trenutni == ' ') 
            presledek = true;
        else 
            presledek = false;
    }
    printf("%d\n", vsotaSamostojnih);
    return 0;
}