#include <bits/stdc++.h>
using namespace std;

deque <int> dq;
deque <int> d;

inline void show(deque <int> g) {
    deque <int> :: iterator it;
    for (it = g.begin(); it != g.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main() {
    dq.push_back(10); show(dq);
    dq.push_front(0); show(dq);
    dq.push_back(20); show(dq);
    dq.push_front(5); show(dq);

    cout << dq.size() << endl;
    cout << dq.max_size() << endl;
    cout << dq.at(2) << endl;
    cout << dq.front() << endl;
    cout << dq.back() << endl;

    dq.pop_front(); show(dq);
    dq.pop_back(); show(dq);

    cout << endl;

    d = {1, 2, 3, 4, 5}; show(d);
    deque <int> :: iterator it = d.begin();
    ++it;
    d.insert(it, 10); show(d);
    ++it; ++it;
    d.insert(it, 50); show(d);
}
