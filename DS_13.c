#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node *prev, *next; } Node;
Node* create(int arr[], int n){
    Node *head=NULL, *tail=NULL;
    for(int i=0;i<n;i++){
        Node* t = malloc(sizeof(Node)); t->data=arr[i]; t->next=t->prev=NULL;
        if(!head) head=tail=t; else { tail->next=t; t->prev=tail; tail=t; }
    }
    return head;
}
void printForward(Node* head){ while(head){ printf("%d ", head->data); head=head->next; } printf("\n"); }
void printBackward(Node* tail){ while(tail){ printf("%d ", tail->data); tail=tail->prev; } printf("\n"); }
Node* insertFront(Node* head,int x){ Node* n=malloc(sizeof(Node)); n->data=x; n->prev=NULL; n->next=head; if(head) head->prev=n; return n; }
Node* deleteNode(Node* head, int x){
    Node* cur=head;
    while(cur && cur->data!=x) cur=cur->next;
    if(!cur) return head;
    if(cur->prev) cur->prev->next = cur->next; else head = cur->next;
    if(cur->next) cur->next->prev = cur->prev;
    free(cur); return head;
}
int main(){
    int a[]={1,2,3}; Node* h = create(a,3); printForward(h);
    h = insertFront(h,0); printForward(h);
    h = deleteNode(h,2); printForward(h);
    return 0;
}
