#include <stdio.h>
#include <stdlib.h>
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int rekurzija(int visina, int **tabela, int i, int j, int vsota);

int main()
{
    int n;
    scanf("%d", &n);

    int** tabela = calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        tabela[i] = calloc(n, sizeof(int));
        for (int j = 0; j <= i; j++)
            scanf("%d", &tabela[i][j]);
    }

    int max = 0;
    int levo = rekurzija(n - 1, tabela, 1, 0, tabela[0][0]);
    int desno = rekurzija(n - 1, tabela, 1, 1, tabela[0][0]);
    
    if (levo > desno)
        max = levo;
    else
        max = desno;
    
    printf("%d\n", max);

    return 0;
}

int rekurzija(int visina, int** tabela, int i, int j, int vsota)
{
    if (visina == 1)
        return vsota + tabela[i][j];
    else
    {
        int levo = rekurzija(visina - 1, tabela, i + 1, j, vsota + tabela[i][j]);
        int desno = rekurzija(visina - 1, tabela, i + 1, j + 1, vsota + tabela[i][j]);
        
        return MAX(levo, desno);
    }
}