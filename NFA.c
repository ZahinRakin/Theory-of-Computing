#include <stdio.h>

#define MAX_STATES 100
#define MAX_SYMBOL 10

int nfa[MAX_STATES][MAX_SYMBOL][MAX_STATES];


int acceptStates[] = {2};


int simulateNFARecursive(int currentState, char *input) {
    if (*input == '\0') {
        for (int i = 0; i < sizeof(acceptStates) / sizeof(acceptStates[0]); i++) {
            if (currentState == acceptStates[i]) {
                return 1;
            }
        }
        return 0;
    }

    char currentInputSymbol = *input;
    int inputIndex = currentInputSymbol - 'a';

    if (inputIndex >= 0 && inputIndex < 2) {
        int nextState = nfa[currentState][inputIndex][0];
        if (nextState != -1) {
            return simulateNFARecursive(nextState, input + 1);
        }
    }

    return 0;
}

int main() {
    char input[] = "aab";
    if (simulateNFARecursive(0, input)) {
        printf("Input accepted by NFA\n");
    } else {
        printf("Input not accepted by NFA\n");
    }

    return 0;
}
