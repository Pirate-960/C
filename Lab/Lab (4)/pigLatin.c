#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
 void convertPigLatin (char english[]) {
 	char *tokenPtr;
 	char word[40];
 	tokenPtr=strtok(english, " ");
 	int tlen;
 
	while (tokenPtr != NULL)
	{
		sscanf(tokenPtr, "%s", word); 
		
		tlen=strlen(word);

		printLatinWords(word,tlen),
		
		tokenPtr=strtok(NULL, " ");
	}
 }
 
 void printLatinWords (char word[], int len) {
 	char pLatin[40];
 	
 	strncpy(pLatin, &word[1], len-1);
 	
 	pLatin[len-1] = word[0];
 	
 	pLatin[len] = 'a';
 	
 	pLatin[len+1] = 'y';
 	
 	pLatin[len+2] = '\0';
 	
 	printf("%s ",pLatin);
 }
 
main( )
{
    char english[80];
    printf("\nPig Latin Translator in C\n\n");
 
    gets(english);
    
    convertPigLatin(english);
}
