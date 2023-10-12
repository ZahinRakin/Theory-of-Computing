#include <stdio.h>
#include <string.h>

void printBinaryValue(int, int);
int power(int,int);

int main(){
    printf("\n\033[1;31m2.a)\033[0m\n\n");//2.a
    int number;
    printf("Give me a number. I will give you all the possible o1 strings whose length is the number you privided: ");
    scanf("%d",&number);
    int stringNumber = power(2,number);

    for(int i = 0; i < stringNumber; i++){
        printf("\033[1;34mString %d: \033[0m",i);
        printBinaryValue(i,number);
    }
    

    printf("\n\033[1;31m2.b)\033[0m\n\n");//2.b

    printf("\033[1;37mEnter a String:\033[0m ");
    char str[100];
    scanf("%s",str);
    int i,j,flag = 1;
    for(i = 0, j = strlen(str)-1; i < j; i++,j--){
        if(str[i] != str[j]){
            flag = 0;
            printf("\n\033[1;31mnot palindrome\n\n\033[0m");
            break;
        }
    }
    if(flag){
        printf("\n\033[1;32mpalindrome\n\n\033[0m");
    }
    return 0;
}

void printBinaryValue(int value, int number){
    int arr[number];
    for(int i = number-1; i >= 0; i--){
        arr[i] = value%2;
        value /= 2;
    }
    for(int i = 0; i < number; i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}

int power(int base, int pow){
    int ans = 1;
    for(int i = 0; i < pow; i++){
        ans *= base;
    }
    return ans;
}