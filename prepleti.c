
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

Vozlisce* prepleti(Vozlisce** seznami, int n) {
    Vozlisce *m = calloc(1,sizeof(Vozlisce));
    Vozlisce *p = m;
    Vozlisce *k;
    int b = 0;
    while (b != n) {
        b = 0;
        for (int i = 0; i < n; i++) {
            if (seznami[i] != NULL) {
           //printf("%d\n",seznami[i]->podatek);
            m->podatek = seznami[i]->podatek;
            m->naslednje = calloc(1,sizeof(Vozlisce));
            k = m;
            m = m->naslednje;
            seznami[i] = seznami[i]->naslednje;
            
            }else {
            b++;
            }   
        }
        
    }
    k->naslednje = NULL;
    return p;
}

int main() {
    return 0;
}
