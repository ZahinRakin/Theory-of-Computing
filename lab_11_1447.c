#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char input[100];
    char output[1000] = "S => ";
    printf("Enter a input : ");
    scanf("%s",input);
    getchar();

    char temp[100];

    for(int i = 0; i < strlen(input); i++){
        temp[i] = input[i];
        temp[i+1] = '\0';
        if(input[i] == 'a' && i == strlen(input) - 1){
            sprintf(output,"%s %saS => ",output,temp);
        }else if(input[i] == 'a' && input[i + 1] == 'a'){
            sprintf(output, "%s %saS => ", output,temp);
        }else if(input[i] == 'a' && input[i+1] == 'b'){
            sprintf(output, "%s %saSbS => ",output,temp);
        }
    }
    printf("Output : %s%s\n\n",output,input);
    return 0;
}