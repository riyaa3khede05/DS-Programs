#include <stdio.h>
#define MAX 50

int arr[MAX];
int top1 = -1;         // Stack 1 starts from left
int top2 = MAX;        // Stack 2 starts from right

void push1(int x) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow\n");
    } else {
        arr[++top1] = x;
        printf("%d pushed in Stack 1\n", x);
    }
}

void push2(int x) {
    if (top2 - 1 == top1) {
        printf("Stack Overflow\n");
    } else {
        arr[--top2] = x;
        printf("%d pushed in Stack 2\n", x);
    }
}

void pop1() {
    if (top1 == -1) {
        printf("Stack 1 Underflow\n");
    } else {
        printf("%d popped from Stack 1\n", arr[top1--]);
    }
}

void pop2() {
    if (top2 == MAX) {
        printf("Stack 2 Underflow\n");
    } else {
        printf("%d popped from Stack 2\n", arr[top2++]);
    }
}

int main() {
    push1(10);
    push1(20);

    push2(100);
    push2(200);

    pop1();
    pop2();

    return 0;
}
