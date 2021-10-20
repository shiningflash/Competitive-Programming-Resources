#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

template<class Type>
class mystack {

private:
    Type *arr;
    int top;
    int capacity;
    
public:
    mystack(int size) {
        arr = new Type[size];
        capacity = size;
        top = -1;
    }
    
    void push(Type item) {
        if (isFull()) {
            printf("Error: stack overflow.");
            return;
        }
        arr[++top] = item;
    }
    
    void pop() {
        if (isEmpty()) {
            printf("Error: stack is empty.");
            return;
        }
        top--;
    }
    
    Type peek() {
        if (isEmpty()) {
            printf("Error: stack is empty.");
            exit(EXIT_FAILURE);
        }
        return arr[top];
    }
    
    int size() {
        return top + 1;
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    bool isFull() {
        return top == capacity - 1;
    }
    
    void print_stack(mystack st) {
        while (!st.isEmpty()) {
            cout << st.peek() << " ";
            st.pop();
        }
        printf("\n");
    }
};

int main() {
    mystack<string> st(10);
    
    st.push("brac");
    st.push("aiub");
    st.push("du");
    st.print_stack(st);
    st.pop();
    st.pop();
    st.print_stack(st);
}
