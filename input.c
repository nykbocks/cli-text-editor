#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int *argc,char argv[]){
	int pluh;
	char cur[250];
	int i = 0;
	while(pluh != 'f'){
		pluh = getchar();
		cur[i] = pluh;
		i++;
	}	
	printf("%s",&cur);
	return 0;
}
