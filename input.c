#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int main(int argc,char *argv[]){
	if(argc == 1){
		printf("please pass a filename");
		return 1;
	}
	FILE *filename;
	filename = fopen(argv[1],"w+");
	system("clear");	
	char input[251] = {0};
	char cur[251] = {0};
	for(int i=0;i<250;i++){
		input[i] = getch();
		putchar(input[i]);
		if(input[i] == '\e'){
			break;
		}
		if(input[i] == '\r'){
			printf("\n");
			strcat(&input[i+=1],"\n");
		}
	}
	fprintf(filename,"%s",input);
	fclose(filename);
	return 0;
}
