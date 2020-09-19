#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jePalindrom(char* word, int first, int last)
{
	if(first == last){
		return 1;
	}

	if(word[first] != word[last]){
		return 0;
	}

	if(first < last + 1){
		return jePalindrom(word, first + 1, last - 1);
	}

	return 1;
}

int main()
{
	char* word = malloc(100 * sizeof(char));

	int c;
	int i = 0;
	while((c = getchar()) != '\n'){
		word[i] = c;
		i++;
	}
	word[i] = '\0';
	printf("%s\n", word);

	int len = strlen(word);
	if(jePalindrom(word, 0, len - 1)){
		printf("Je palindrom\n");
	} else {
		printf("Ni palindrom\n");
	}

	return 0;
}