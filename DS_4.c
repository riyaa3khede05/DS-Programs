#include <stdio.h>
#define MAX 100

int arr[MAX];
int f1=-1, r1=-1;      // queue1: left side
int f2=MAX, r2=MAX;    // queue2: right side

void enqueue1(int x){
    if(r1 + 1 == r2){ printf("Overflow\n"); return; }
    if(f1==-1) f1=0;
    arr[++r1] = x;
}
void enqueue2(int x){
    if(r1 +1 == r2){ printf("Overflow\n"); return; }
    if(f2==MAX) f2=MAX-1;
    arr[--r2] = x;
}
void dequeue1(){
    if(f1==-1 || f1>r1){ printf("Q1 Underflow\n"); return; }
    printf("Dequeued from Q1: %d\n", arr[f1++]);
    if(f1>r1) f1=r1=-1;
}
void dequeue2(){
    if(f2==MAX || f2<r2){ printf("Q2 Underflow\n"); return; }
    printf("Dequeued from Q2: %d\n", arr[r2++]);
    if(r2==f2) f2=r2=MAX;
}
int main(){
    enqueue1(1); enqueue1(2); enqueue2(10); enqueue2(20);
    dequeue1(); dequeue2();
    return 0;
}
