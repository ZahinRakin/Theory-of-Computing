//lab_03_1447.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nfa{
    int delta[10][2][10];
    int trans[10][2];
    int nos;
    int s;
    int nof;
    int end[10];
}NFA;

int main(){
    NFA nfa;
    printf("Number of states: ");
    scanf("%d",&nfa.nos);
    getchar();
    printf("Start: ");
    scanf("%d",&nfa.s);
    getchar();
    printf("Number of end state: ");
    scanf("%d",&nfa.nof);
    getchar();
    for(int i = 0; i < nfa.nof; i++){
        printf("end state %d: ",i+1);
        scanf("%d",&nfa.end[i]);
        getchar();
    }
    for(int i = 0; i < nfa.nos; i++){
        for(int j = 0; j < 2; j++){
            printf("how many trans for q%d for A%d: ",i,j);
            scanf("%d",&nfa.trans[i][j]);
            getchar();
            for(int k = 0; k < nfa.trans[i][j]; k++){
                printf("trans-%d :",k+1);
                scanf("%d",&nfa.delta[i][j][k]);
                getchar();
            }
        }
    }
    //nfa loaded
    char str[100];//1
    printf("Enter a string(0/1): ");
    scanf("%s",str);
    getchar();//2

    int states[10] = {0};
    states[nfa.s] = 1;
    int newStates[10];
    char path[1000] = "";

    for(int i = 0; i < strlen(str); i++){
        int sym = str[i] - '0';
        if(sym < 0 || sym > 1){
            printf("\n\n\033[1;31mrejected\033[0m\n\n");
            return 0;
        }
        memset(newStates,0,sizeof(newStates));
        for(int j = 0; j < nfa.nos; j++){
            if(states[j]){
                for(int k = 0; k < nfa.trans[j][sym]; k++){//here i got the culprit (nfa.trans[i][j]//shameful)
                    int next = nfa.delta[j][sym][k];
                    newStates[next] = 1;
                    char transitions[15];
                    sprintf(transitions,"-q%d-(%d)-q%d\n",j,sym,next);
                    strcat(path,transitions);
                }
            }
        }
        memcpy(states,newStates,sizeof(newStates));
    }
    int accepted = 0;
    for(int i = 0; i < nfa.nof; i++){
        if(states[nfa.end[i]]){
            accepted = 1;
            break;
        }
    }
    printf("%s",(accepted == 1) ? "\033[1;32m\n\naccepted\033[0m\n\n" : "\033[1;31m\n\nrejected\n\n\033[0m");
    printf("\n\n\033[1;36mhere is the path:\n%s\n\n\033[0m",path);
    return 0;
}