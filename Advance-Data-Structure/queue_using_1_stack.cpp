#include <iostream>
#include <stack>
using namespace std;

stack <int> st;

void enqueue() {
    int val;
    cin >> val;
    st.push(val);
}

int dequeue() {
    if (st.size() == 1) {
        int val = st.top();
        st.pop();
        return val;
    }
    int curValue = st.top();
    st.pop();
    int rec = dequeue();
    st.push(curValue);
    return rec;
}

int main() {
    string cmd;
    for (int i = 0; i < 10; i++) {
        cin >> cmd;
        if (tolower(cmd[0]) == 'e') { // cmd == "enqueue"
            enqueue();
        }
        else if (tolower(cmd[0]) == 'd') { // cmd == 'dequeue'
            if (st.empty()) {
                printf("Error: queue is empty\n");
                exit(EXIT_FAILURE);
            }
            int val = dequeue();
            printf("dequeued: %d\n", val);
        }
    }
    return 0;
}