#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Primer
typedef struct node{
    int element;
    struct node *next;
} Node;

typedef struct _Vozlisce{
    int podatek;
    struct _Vozlisce *naslednje;
} Vozlisce;

Vozlisce* kreiraj(int n){
    Vozlisce *prvo, *tmp, *sledno;
    int num, i;
    prvo = malloc(sizeof(Vozlisce));
    printf("Podatek za  prvo: ");
    scanf("%d", &num);
    prvo -> podatek = num;
    prvo -> naslednje = NULL;
    tmp = prvo;
    for(int i=2; i<=n; i++){
        sledno = malloc(sizeof(Vozlisce));
        printf("Podatek za %d.:", i);
        scanf("%d", &num);

        sledno -> podatek = num;
        sledno -> naslednje = NULL;

        tmp -> naslednje = sledno;
        tmp = tmp -> naslednje;
    }
    return prvo;
}

void printaj(Vozlisce* n){
    Vozlisce* tmp;
    tmp = n;
    while(tmp != NULL){
        printf("Podatek = %d\n", tmp -> podatek);
        tmp = tmp -> naslednje;
    }
}

Vozlisce *addFirst(Vozlisce* list, int element){
    Vozlisce *novo = malloc(sizeof(Vozlisce));
    novo -> podatek = element;
    novo -> naslednje = list;
    // ne mora ova
    //return novo;
}

Vozlisce *removeFirst(Vozlisce* list){
    list = list -> naslednje;
    return list;
}

Vozlisce *addLast(Vozlisce* list, int element){
    Vozlisce *dodavam, *tmp;
    tmp = list;
    while(tmp -> naslednje != NULL){
        tmp = tmp -> naslednje;
    }
    dodavam = malloc(sizeof(Vozlisce)); 
    tmp -> naslednje = dodavam;
    dodavam -> podatek = element;
    dodavam -> naslednje = NULL;
    return list;
}

Vozlisce* removeLast(Vozlisce* list){
    Vozlisce *last, *tmp;
    last = list;
    while(last -> naslednje != NULL){
        tmp = last;
        last = last -> naslednje;
    }
    tmp -> naslednje = NULL;
    free(last);
    return list;
}

int vsotaElementov(Vozlisce* list){
    Vozlisce *tmp = list;
    int vsota = 0, i = 0;
    while(tmp != NULL){
        if(i % 2 == 0){
            vsota += tmp -> podatek;
        }
        i++;
        tmp = tmp -> naslednje;
    }
    return vsota;
}

Vozlisce* pritakni(Vozlisce* list1, Vozlisce* list2){
    Vozlisce *tmp = list1;
    while(tmp -> naslednje != NULL)
        tmp = tmp -> naslednje;
    tmp -> naslednje = list2;
    return list1;
}

bool jePrastevilo(int n){
    int sht = 1;
    for(int i=1; i<=(n/2); i++){
        if(n % i == 0){
            sht++;
        }
    }
    if(sht == 2) return 1;
    else return 0;
}

Vozlisce* primitivniVen (Vozlisce* list){
    Vozlisce *tmp = list;
    while(tmp != NULL){
        if(jePrastevilo(tmp -> podatek)){
            tmp = (tmp -> naslednje);
            tmp = tmp -> naslednje;
        }
        else tmp = tmp -> naslednje;
    }
    return tmp;
}

Vozlisce* Vecji_ven(int bro, Vozlisce* lis){
    Vozlisce* tmp = lis;
    Vozlisce* prn = tmp;
    while(tmp != NULL){
    
        if(tmp -> podatek > bro){
            tmp = (tmp -> naslednje) -> naslednje;
        }
        else tmp = tmp -> naslednje;
    }
    return prn;
}

Vozlisce* izloci(Vozlisce* zac, int index){
    Vozlisce* prv = zac;
    Vozlisce* tmp = prv;
    Vozlisce* brisi = prv;
    int br = 1;
    while(brisi != NULL){
        if(br == index) break;
        else{
            tmp = brisi;
            brisi = brisi -> naslednje;
        
            br++;
        }
    }
    if(br == index){
        tmp -> naslednje = brisi -> naslednje;
        return prv;
    }
    else{
        return prv;
    }
}

Vozlisce* vstaviUrejeno(Vozlisce* zac, int ele){
    Vozlisce* tmp = zac;
    Vozlisce* pvv = zac;
    Vozlisce* prvo = tmp;
    Vozlisce* dva = tmp;
    Vozlisce* vstavi = malloc(sizeof(Vozlisce));
    vstavi -> podatek = ele;
    while ((tmp -> podatek) < ele && tmp -> naslednje != NULL)
    {
        dva = tmp;
        tmp = tmp -> naslednje;
    }
    if(tmp == pvv){
        vstavi -> naslednje = tmp;
        return vstavi;
    }
    if(tmp -> naslednje == NULL){
        tmp -> naslednje = vstavi;
        vstavi -> naslednje =NULL;
        return prvo;
    }
    dva -> naslednje = vstavi;
    vstavi -> naslednje = tmp;
    return prvo;
}

void revers(Vozlisce* v){
    if(v == NULL)
        return;
    revers(v -> naslednje);
    printf("%d ", v -> podatek);
}

int main(){
    int n;
    scanf("%d", &n);
    Vozlisce* prvo = kreiraj(n);
    printf("\n");
    printaj(prvo);
    printf("\n");
    //Vozlisce* drugo = kreiraj(3);
    /*Vozlisce* krajna = addFirst(prvo, 5);
    printaj(krajna);
    printf("\n");
    Vozlisce* krajno = removeFirst(prvo);
    printaj(krajno);
    Vozlisce* brisi = removeLast(prvo);
    printaj(brisi);
    */
   /*Vozlisce* vrakjam = pritakni(prvo, drugo);
   printaj(vrakjam);
    printf("%d", vsotaElementov(prvo));*/
    //Vozlisce* krajni = vstaviUrejeno(prvo, 60);
    revers(prvo);
    return 0;
}