#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char S[] = "A1B";
char A[] = "0A|EPS";
char B[] = "0B|1B|EPS";
char str[] = "00101";

void leftMost();

int main(){
    printf("Here is the leftmost : ");
    leftMost();
    return 0;
}

void leftMost(){
    char ans[1000];
    int i = 0;
    int rotation = 0;
    char *p = str;
    int flag = 0;
    printf("A1B => ");
    while(*p){
        i = rotation;
        ans[i+1] = '\0';
        if(*p == '0' && !flag){
            ans[i++] = '0';
            strcat(ans,"A1B => ");
            p++;
        }
        else if(*p == '1' && !flag){
            ans[i++] = '1';
            strcat(ans,"B => ");
            flag++;//this is to determine the first encounter of 1.
            p++;
        }
        else if(flag){
            ans[i++] = *p;
            strcat(ans,"B => ");
            p++;
        }
        rotation++;
        printf("%s",ans);
    }
    printf("00101\n\n\n");
}

