//lab_02_1447.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int nos;
    int noa;//number of alphabet
    char *alphabet;
    int s;
    int nof;
    bool *end;
    int** trns;
} DFA;

DFA initDFA(DFA);
void isAccepted(DFA,char*);
int indexOfChar(DFA,char);

int main(){
    DFA dfa = initDFA(dfa);
    char str[100];
    //dfa loaded perfectly;

    printf("Enter a string: ");
    scanf("%s",str);
    getchar();
    isAccepted(dfa,str);
    printf("\n");
    return 0;
}

DFA initDFA(DFA dfa){
    printf("\nNumber of states: ");
    scanf("%d",&dfa.nos);
    printf("\nStarting state: ");
    scanf("%d",&dfa.s);
    printf("\nNumber of final state: ");
    scanf("%d",&dfa.nof);
    printf("\n");

    //initializing the final states containing array
    dfa.end = (bool*)malloc(sizeof(bool)*dfa.nof);
    for(int i = 0; i < dfa.nos; i++)
        dfa.end[i] = false;

    printf("Final states: ");
    for(int i = 0; i < dfa.nof; i++){
        int temp;
        scanf("%d",&temp);
        dfa.end[temp] = true;
    }
    printf("\n");

    //loading the alphabets
    printf("Number of alphabets: ");
    scanf("%d",&dfa.noa);
    printf("\n");
    getchar();
    dfa.alphabet = (char*)malloc(sizeof(char)*dfa.noa);
    //getting the alphabets
    for(int i = 0; i < dfa.noa; i++){
        printf("Enter the alphabet no.%d: ",i+1);
        scanf("%c",&dfa.alphabet[i]);
        getchar();
    }
    printf("\n");


    //transition table loading.
    dfa.trns = (int**)malloc(sizeof(int*)*dfa.nos);
    for(int i = 0; i < dfa.nos; i++){
        dfa.trns[i] = (int*)malloc(sizeof(int)*dfa.noa);
        for(int j = 0; j < dfa.noa; j++){
            printf("Q%d--A%c-->Q? = ",i,dfa.alphabet[j]);
            scanf("%d",&dfa.trns[i][j]);
        }
    }
    return dfa;
}

void isAccepted(DFA dfa, char* str){
    int currentState = dfa.s;
    while(*str){
        int alphIndex = indexOfChar(dfa,*str);
        if(alphIndex == -1){
            printf("\nrejected\n");
            exit(0);
        }
        currentState = dfa.trns[currentState][alphIndex];
        str++;
    }
    printf("%s",(dfa.end[currentState]) ? "\naccepted\n" : "\nrejected\n");
}

int indexOfChar(DFA dfa, char c){
    for(int i = 0; i < dfa.noa; i++)
        if(dfa.alphabet[i] == c)
            return i;
    return -1;
}