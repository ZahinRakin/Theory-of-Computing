#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char name[80];
	char line[1000];
	int index = 1;
	int flag = 0;
	
	printf("File name: ");
	scanf("%s",name);
	getchar();
	
	FILE *filePointer;
	if((filePointer = fopen(name,"r"))==NULL){
		printf("Error while opening the file.\n");
		exit(1);
	}/*this is where it begins
	this is where it ends. line number 20*/

	while(fgets(line, sizeof(line), filePointer)){
		char* sc = strstr(line,"//");
		char* mcs = strstr(line,"/*");
		char* mce = strstr(line,"*/");
		if(flag){
			printf("%d: %s",index,line);//line number 26
			if(mce){
				flag = 0;
			}
		}/*
		else{
			if(mcs){
				flag = 1;
				printf("%d: %s",index,mcs);
				if(mce){
					flag = 0;
				}
			}
			else if(sc){
				printf("%d: %s",index,sc);
			}
		}
		index++;
	}
	return 0;
}
