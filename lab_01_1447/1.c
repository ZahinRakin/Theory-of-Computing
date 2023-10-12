#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generateString(char*,int);
int randomInt(int, int);

int length[5];

int main(){
    srand(time(NULL));
    printf("\n\033[1;31m1.a)\033[0m\n\n");
    printf("\033[1;36mGenerating Five strings from alphabet(0,1):\033[0m\n\n");
    for(int i = 0; i < 5; i++){
        printf("\033[1;32mString %d: \033[0m",i+1);
        length[i] = randomInt(3,20);
        char *str = generateString(str,length[i]);
        printf("%s\n",str);
    }
    printf("\n\033[1;31m1.b)\n\n\033[0m");
    for(int i = 0; i < 5; i++){
        printf("\033[1;32mLength of String %d: \033[0m%d\n",i+1,length[i]);
    }
    printf("\n");

    printf("\033[1;31m1.c)\033[0m\n\n");
    printf("\033[1;36mGive a string I will check if it is from alphabet(0,1): \033[0m");

    char string[100];
    scanf("%s",string);
    int flag = 0;
    for(int i = 0; i < strlen(string); i++){
        if(string[i] < '0' || string[i] > '1'){
            printf("\n\033[1;31mrejected\n\n\033[0m");
            flag = 1;
            break;
        }
    }
    if(!flag){
        printf("\n\033[1;32maccepted\n\n\033[0m");
    }

    printf("\033[1;31m1.d)\033[0m\n\n");
    char str1[100] = "010101011111";
    char str2[100] = "01110";
    printf("\033[1;34mHere we will concatenate these two strings\n\033[1;35mString 1:\033[0m%s\n\033[1;35mString 2:\033[0m%s\n\n\033[1;32mHere is the concatenated string: \033[0m%s\n\n",str1,str2,strcat(str1,str2));
}

char* generateString(char* str,int len){
    str = (char*)malloc(sizeof(char) * len);
    for(int i = 0; i < len; i++){
        str[i] = (char)(randomInt(0,2)+'0');
    }
    return str;
}

int randomInt(int min, int max){
    return rand()%(max-min) + min;
}