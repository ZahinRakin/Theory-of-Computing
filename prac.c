#include <stdio.h>
#include <stdlib.h>

void simulate(){
    if(*input == '\0'){
        for(int i = 0; i < numOfAcceStates; i++){
            if(currentState == accept[i])
                return 1;
        }
        return 0;
    }
    int nextState = -1;
    
}