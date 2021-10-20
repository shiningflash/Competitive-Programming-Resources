/*
    it takes two stacks to perform the task,
    but it's time efficient, only in Linear time

    There are also another approach, which is
    not time efficient, but use only one stack
*/

#include <iostream>
#include <stack>
using namespace std;

/*
| 3 |  | 1 |
| 2 |  | 2 |
| 1 |  | 3 |
-----  -----
 enq    deq
*/

stack<int> enq, deq;

void enqueue() {
    int val;
    cin >> val;
    enq.push(val);
}

void dequeue() {
    if (deq.empty()) { // if deq empty, transfer all enq value to deq in reverse order
        int val;
        while (!enq.empty()) {
            int val = enq.top();
            enq.pop();
            deq.push(val);
        }
    }
    if (deq.empty()) { //  if still empty
        printf("Error: queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int val = deq.top();
    deq.pop();
    printf("dequeued %d\n", val);
}

int main() {
    string cmd;
    for (int i = 0; i < 10; i++) {
        cin >> cmd;
        if (tolower(cmd[0]) == 'e') { // cmd == "enqueue"
            enqueue();
        }
        else if (tolower(cmd[0]) == 'd') { // cmd == 'dequeue'
            dequeue();
        }
    }
    return 0;
}