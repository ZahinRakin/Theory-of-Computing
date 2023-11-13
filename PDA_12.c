//PDA o^n 1^n
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    char value;
    struct node * next;
} Stack;

Stack* head = NULL;
int count = 0;

void push(char);
char pop();

int main(){
    Stack* head = malloc(sizeof(Stack));
    char input[100];
    printf("Input : ");
    scanf("%s",input);
    getchar();

    int i;
    int flag = 0;

    for(i = 0; i < strlen(input); i++){
        if(input[i] == '0' && !flag){
            push(0);
        }else{
            flag = 1;
            pop();
        }
    }

    if(i == strlen(input) && count == 0){
        printf("PDA\n\n");
    }else{
        printf("Not PDA\n\n");
    }

    return 0;
}

void push(char data) {
    count++;
    Stack* temp;
    if (head == NULL){
        head =(struct node *)malloc(1*sizeof(struct node));
        head->next = NULL;
        head->value = data;
    }else{
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->next = head;
        temp->value = data;
        head = temp;
    }
}

char pop() {
    count--;
    Stack* head1 = head;
    if (head1 == NULL){
        printf("Not PDA\n\n");
        exit(0);
    }else
        head1 = head1->next;
    int popped = head->value;
    free(head);
    head = head1;
    return popped;
}