
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct _Oseba {
    
    char* ip;
    int stOtrok;
    struct _Oseba** otroci;

} Oseba;


Oseba* tabela[1000];
int globina[1000];
int counter = 0;
int maxGlobina = 0;

void rekurzija (Oseba* oseba, int nivo) { 
    
	if (maxGlobina < nivo) { // najgolema
		maxGlobina = nivo;
	}
	
	tabela[counter] = oseba;
	globina[counter] = nivo;
	counter++;
	
	for (int i = 0; i < oseba->stOtrok; i++) { // deca
		rekurzija(oseba->otroci[i], nivo + 1);
	}

}




int main() {

    Oseba* sin3 = malloc(sizeof(Oseba));
    sin3->ip = "Andraž Gorišek";
    sin3->stOtrok = 0;
    sin3->otroci = NULL;
    
    Oseba* sin4 = malloc(sizeof(Oseba));
    sin4->ip = "Andrej Gorišek";
    sin4->stOtrok = 0;
    sin4->otroci = NULL;

    Oseba* hci = malloc(sizeof(Oseba));
    //strcpy(hci->ip,"Ana Gorišek");
    hci->ip = "Ana Gorišek";
    hci->stOtrok = 2;
    Oseba** tabAna = malloc(sizeof(Oseba*) * 2);
    tabAna[0] = sin3;
    tabAna[1] = sin4;
    hci->otroci = tabAna;

    Oseba* sin1 = malloc(sizeof(Oseba));
    sin1->ip = "Matej Gorišek";
    sin1->stOtrok = 0;
    sin1->otroci = NULL;

    Oseba* sin2 = malloc(sizeof(Oseba));
    sin2->ip = "Tilen Gorišek";
    sin2->stOtrok = 0;
    sin2->otroci = NULL;


    Oseba* oce = malloc(sizeof(Oseba));
    oce->ip = "Jože Gorišek";
    oce->stOtrok = 3;
    Oseba** tab = malloc(sizeof(Oseba*) * 3);
    //Oseba* tab[3];
    tab[0] = hci;
    tab[1] = sin1;
    tab[2] = sin2;
    oce->otroci = tab;


    rekurzija(oce,0);
    printf("glob: %d", maxGlobina);
    printf(" count: %d\n", counter);
    
    for (int i = 0; i <= maxGlobina; i++) { // za site
        for (int j = 0; j < counter; j ++) {
            
            if (globina[j] == i) {
                Oseba* trenutna = tabela[j];
                printf("globina: %d ", i);
                printf("%s\n", trenutna->ip);
            }
        }
    }

    return 0;
}