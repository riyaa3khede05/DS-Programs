#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node* next; } Node;

Node* create(int arr[], int n){
    Node *head=NULL, *tail=NULL;
    for(int i=0;i<n;i++){
        Node* t=malloc(sizeof(Node)); t->data=arr[i]; t->next=NULL;
        if(!head) head=tail=t; else { tail->next=t; tail=t; }
    }
    return head;
}
void printList(Node* h){ while(h){ printf("%d ", h->data); h=h->next; } printf("\n"); }
Node* insertAtHead(Node* head,int x){ Node* n=malloc(sizeof(Node)); n->data=x; n->next=head; return n; }
Node* insertAtPos(Node* head,int pos,int x){ if(pos==0) return insertAtHead(head,x);
    Node* cur=head; for(int i=0;i<pos-1 && cur;i++) cur=cur->next;
    if(!cur) return head;
    Node* n=malloc(sizeof(Node)); n->data=x; n->next=cur->next; cur->next=n; return head;
}
Node* deleteByValue(Node* head,int x){
    if(!head) return head;
    if(head->data==x){ Node* t=head; head=head->next; free(t); return head; }
    Node* cur=head;
    while(cur->next && cur->next->data!=x) cur=cur->next;
    if(cur->next){ Node* t=cur->next; cur->next=t->next; free(t); }
    return head;
}
Node* reverse(Node* head){
    Node *prev=NULL, *cur=head, *next;
    while(cur){ next=cur->next; cur->next=prev; prev=cur; cur=next; }
    return prev;
}
Node* mergeSorted(Node* a, Node* b){
    if(!a) return b; if(!b) return a;
    if(a->data < b->data) { a->next = mergeSorted(a->next,b); return a; }
    else { b->next = mergeSorted(a,b->next); return b; }
}
Node* findMiddle(Node* head){
    Node *slow=head, *fast=head;
    while(fast && fast->next){ slow=slow->next; fast=fast->next->next; }
    return slow;
}
int sumList(Node* head){ int s=0; while(head){ s+=head->data; head=head->next; } return s; }
int detectLoop(Node* head){
    Node *slow=head, *fast=head;
    while(fast && fast->next){ slow=slow->next; fast=fast->next->next; if(slow==fast) return 1; }
    return 0;
}
Node* sortedMerge(Node* a, Node* b){
    if(!a) return b; if(!b) return a;
    if(a->data <= b->data){ a->next = sortedMerge(a->next,b); return a; }
    else { b->next = sortedMerge(a,b->next); return b; }
}
void frontBackSplit(Node* source, Node** frontRef, Node** backRef){
    Node *fast, *slow; slow = source; fast = source->next;
    while(fast){ fast = fast->next; if(fast){ slow = slow->next; fast = fast->next; } }
    *frontRef = source; *backRef = slow->next; slow->next = NULL;
}
void mergeSort(Node** headRef){
    Node* head = *headRef; if(!head || !head->next) return;
    Node *a, *b;
    frontBackSplit(head, &a, &b);
    mergeSort(&a); mergeSort(&b);
    *headRef = sortedMerge(a,b);
}
void printOddEven(Node* head){
    printf("Odd: ");
    for(Node* t=head; t; t=t->next) if(t->data%2) printf("%d ", t->data);
    printf("\nEven: ");
    for(Node* t=head; t; t=t->next) if(t->data%2==0) printf("%d ", t->data);
    printf("\n");
}


int main(){
    int a[]={3,1,5,2,4}; Node* h = create(a,5);
    printList(h);
    h = insertAtPos(h,2,99); printList(h);
    h = deleteByValue(h,1); printList(h);
    printf("Sum=%d\n", sumList(h));
    Node* mid = findMiddle(h); printf("Middle=%d\n", mid->data);
    mergeSort(&h); printList(h);
    Node* r = reverse(h); printList(r);
    printOddEven(r);
    return 0;
}
