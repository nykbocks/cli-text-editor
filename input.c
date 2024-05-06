#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

int main(int argc,char *argv[]){
	if(argc == 1){
		printf("please pass a filename");
		return 1;
	}
	FILE *filename;
	filename = fopen(argv[1],"w+");
	char input[251] = {0};
	char cur[251] = {0};
	clear();
	input[0] = getch();
	for(int i=1;i<250;i++){
		while(fgets(cur,250,filename)){
			printf("%s", cur);
		}

		input[i] = getch();
		int x = i;
		int y = 1;
		switch(input[i]){
		case('\e'):
			i = 249;
		case('\r'):
			printf("\n");
			y++;
			strcat(&input[i+=1],"\n");
			break;
		case('\b'):
			int del = 1;
			x--;
			gotoxy(x,y);
			input[i-=del] = " ";
			if(input[i-=del] == " "){
				del++;
			};
			break;
		}
		clear();
		printf("%s",&input);
	}
	fprintf(filename,"%s",input);
	fclose(filename);
	return 0;
}
