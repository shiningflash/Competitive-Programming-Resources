#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

typedef struct {
    int top;
    int arr[SIZE];
} Stack;

void push(Stack *st, int item) {
    if (st->top == SIZE) {
        printf("Error: Stack is full\n");
        return;
    }
    st->arr[st->top] = item;
    st->top = st->top + 1;
}

int pop(Stack *st) {
    if (st->top == 0) {
        printf("Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    st->top = st->top - 1;
    return st->arr[st->top];
}

int main() {
    Stack mystack;
    mystack.top = 0;
    push(&mystack, 1);
    push(&mystack, 2);
    push(&mystack, 3);
    printf("%d\n", pop(&mystack));
    printf("%d\n", pop(&mystack));
    printf("%d\n", pop(&mystack));
    printf("%d\n", pop(&mystack));
    return 0;
}
