#include <stdio.h>
#include <stdlib.h>

int poisci(int stPred, int *prostornine, int *cene, int volNah, int ix){
	
	if(ix == stPred) return 0;
	
	int cenaBrez = poisci(stPred, prostornine, cene, volNah, ix + 1); 
	int cenaZ = 0;
	printf("%d ", cenaBrez);
	if(volNah >= prostornine[ix]){
		cenaZ = cene[ix] + poisci(stPred, prostornine, cene, volNah - prostornine[ix], ix + 1);
        printf("%d\n", cenaZ);
    }
	
	int najCena = (cenaBrez > cenaZ) ? cenaBrez : cenaZ;
	
	return najCena;
}

int main(){
	
	int volNah;
	int stPred;
	
	int *prostornine;
	int *cene;
	
	
	scanf("%d", &volNah);
	scanf("%d", &stPred);
	
	prostornine = calloc(sizeof(int), stPred);
	cene = calloc(sizeof(int), stPred);
	
	
	for(int i = 0; i < stPred; i++){
		scanf("%d", &prostornine[i]);
	}
	
	for(int i = 0; i < stPred; i++){
		scanf("%d", &cene[i]);
	}

	int najCena = poisci(stPred, prostornine, cene, volNah, 0);
	
	printf("%d\n", najCena);
	
	free(prostornine);
	free(cene);

	return 0;
}
