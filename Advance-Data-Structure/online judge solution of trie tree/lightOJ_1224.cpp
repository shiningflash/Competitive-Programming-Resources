#include <bits/stdc++.h>
using namespace std;

map <char, int> mp;

struct node {
    int cnt;
    bool mark;
    node *next[4];
    node() {
        cnt = 0;
        mark = false;
        for (int i = 0; i < 4; next[i] = NULL, i++);
    }
} * root;

void insert(string s) {
    node *cur = root;
    for (int i = 0; s[i]; i++) {
        int id = mp[s[i]];
        if (cur->next[id] == NULL) cur->next[id] = new node();
        cur = cur->next[id];
        cur->cnt++;
    }
}

int search(string s) {
    node *cur = root;
    int mx = -1;
    for (int i = 0; s[i]; i++) {
        int id = mp[s[i]];
        cur = cur->next[id];
        int height = i+1;
        int tmp = cur->cnt * height;
        if (tmp > mx) mx = tmp;
    }
    return mx;
}

void del(node* cur) {
    for (int i = 0; i < 4; i++)
        if (cur->next[i]) del(cur->next[i]);
    delete(cur);
}

int main() {
    mp['A'] = 0;
    mp['C'] = 1;
    mp['G'] = 2;
    mp['T'] = 3;

    int tst, t = 1, n, q;
    string s;
    for (scanf("%d", &tst); tst--;) {
        scanf("%d", &n);
        root = new node();
        vector <string> v;
        while (n--) {
            cin >> s;
            insert(s);
            v.push_back(s);
        }
        int mx = -1;
        for (int i = 0; i < v.size(); i++) {
            int tmp = search(v[i]);
            if (tmp > mx) mx = tmp;
        }
        printf("Case %d: %d\n", t++, mx);
        del(root);
    }
}
