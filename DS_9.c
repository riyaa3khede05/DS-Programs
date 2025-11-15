#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node *next; } Node;
Node* top = NULL;

void push(int x){
    Node* n = malloc(sizeof(Node)); n->data = x; n->next = top; top = n;
}
int pop(){
    if(!top){ printf("Underflow\n"); return -1; }
    int v = top->data; Node* t = top; top = top->next; free(t); return v;
}
int main(){
    push(10); push(20); printf("%d popped\n", pop()); return 0;
}
