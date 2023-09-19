#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STATES 8
#define MAX_SYMBOLL 2

int dfa_trans[MAX_STATES][MAX_SYMBOLL] = {
    {1,0},
    {0,2},
    {3,1},
    {3,0},
    {3,5},
    {6,4},
    {5,6},
    {6,3}
};

bool areDistinguishable(int state1, int state2, int stari, int m[MAX_STATES][MAX_STATES]) {

    return false;
}

int main() {
    int start_state = 0;
    int final_state = 3;//multiple final -> take an array.
    bool mat[MAX_STATES][MAX_STATES];
    for(int i = 0; i < MAX_STATES; i++){
        for(int j = 0; j < MAX_STATES; j++){
            mat[i][j] = false;
        }
    }

    for(int iteration = 0; iteration <= 2; iteration++){
        for(int i = 1; i < MAX_STATES; i++){
            for(int j = 0; j < i; j++){
                if(i == final_state || j == final_state){
                    mat[i][j] = true;
                }

                if(!mat[i][j]){
                    for(int k = 0; k < MAX_SYMBOLL; k++){
                        if((mat[dfa_trans[i][k]][dfa_trans[j][k]]) || (mat[dfa_trans[j][k]][dfa_trans[i][k]])){
                            mat[i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
    }
   
   
    for(int i = 0; i < MAX_STATES; i++){
        for(int j = 0; j < i; j++){
            if(mat[i][j]){
                printf("t ");
            }
            else printf("f ");
        }
        printf("\n");
    }


    return 0;
}
