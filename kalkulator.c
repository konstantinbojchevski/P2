
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



bool svoboden(char* niz, int index, int levo, int desno) {
    
    bool freeD = true;
    int bilanca = 0;
    for (int i = index + 1; i <= desno; i++) {
        if (niz[i] == '(') {
            bilanca++;
        }else if (niz[i] == ')') {
            bilanca--;
        }
    }
    if (bilanca != 0) {
        freeD = false;
    }
    bilanca = 0;
    bool freeL = true;
    for (int i = index - 1; i >= levo; i--) {
        if (niz[i] == '(') {
            bilanca++;
        }else if (niz[i] == ')') {
            bilanca--;
        }
    }
    if (bilanca != 0) {
        freeL = false;
    }
    
    return freeL || freeD;
}

bool oklepaji(char* niz, int levo, int desno) {

    for (int i = desno; i >= levo; i--) { // gledam sloboden opertator
        if (niz[i] != '(' && niz[i] != ')') { // broj ili operator
            bool konec = svoboden(niz,i,levo,desno);
            if (konec) {
                return true; // ako e, ne odstranuvam zagradi
            }
        }
    }

    // odstranuvam nadoresni zagradi -> prva i posledna
    niz[desno] = '\0';
    niz++;
}


int operator (char* niz, int levo, int desno) {
        
    int index = 0;
    int check = 0;
    for (int i = desno; i >= levo; i--) {
            
        if (niz[i] == '+' || niz[i] == '-' || niz[i] == '*' || niz[i] == '/') { // e operator
            if (niz[i] == '+' || niz[i] == '-') { // + ili -
                if (svoboden(niz,i,levo,desno)) {
                    index = i;
                    break;
                }
                }else {
                    if (svoboden(niz,i,levo,desno) && check == 0) { // * ili /
                        index = i;
                        check = 1;
                    }
                }
        }
    }
    return index;
}


long kalkulator (char* niz, int levo, int desno) {

    while (!oklepaji(niz,levo,desno)) { // otpokje zagradi
        levo++;
        desno--;
    }

    if (levo == desno) {
        return niz[levo] - '0';
    }else {

        int index = operator(niz,levo,desno);
        char svobodniOperator = niz[index];

        //printf("%c\n", svobodniOperator);

        if (svobodniOperator == '+') {
            return kalkulator(niz,levo,index - 1) + kalkulator(niz,index + 1, desno);
        }
        else if (svobodniOperator == '-') {
            return kalkulator(niz,levo,index - 1) - kalkulator(niz,index + 1, desno);
        }
        else if (svobodniOperator == '*') {
            return kalkulator(niz,levo,index - 1) * kalkulator(niz,index + 1, desno);
        }
        else if (svobodniOperator == '/') {
            return kalkulator(niz,levo,index - 1) / kalkulator(niz,index + 1, desno);
        }
    }

}

int main() {
    // dopolnite ...

    char* niz = malloc(sizeof(char) * 1000);
    scanf("%s", niz);
    //printf("%s ", niz);
    //oklepaji(niz);
    //printf("%s", niz);
    int dolzina = strlen(niz);
    long rezultat = kalkulator(niz,0,dolzina - 1);

    printf("%ld", rezultat);s

    return 0;
}
