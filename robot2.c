#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int matrika[8][8];

unsigned long long int power (int eksponent) 
{
    unsigned long long int rez = 1;
    for (int i = 0; i < eksponent; i++) 
        rez *= 2;
    return rez;
}


void izpisiMatrika() 
{
    for (int y = 7; y >= 0; y--) 
    {
        for (int x = 7; x >= 0; x--) 
        {
            printf("%2d", matrika[x][y]);
        }
        printf("\n");
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    unsigned long long int desetisko = 0;
    
    int x = 0;
    int y = 0;
    matrika[x][y] = 1;
    int ukaz;

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &ukaz);
        switch(ukaz) 
        {
            case 0:
                if (x + 1 < 8) 
                {
                    x++;
                    matrika[x][y] = 1;
                }
                break;
            case 1:
                if (y + 1 < 8) 
                {
                    y++;
                    matrika[x][y] = 1;
                }
                break;
            case 2:
                if (x - 1 >= 0) 
                {
                    x--;
                    matrika[x][y] = 1;
                }
                break;
            case 3:
                if (y - 1 >= 0) 
                {
                    y--;
                    matrika[x][y] = 1;
                }
            break;
        }
    }

    int eksponent;
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            if (matrika[i][j] == 1) 
            {
                eksponent = j * 8 + i;
                desetisko = desetisko + power(eksponent);
            }
        }
    }

    printf("%llu\n", desetisko);
    return 0;
}