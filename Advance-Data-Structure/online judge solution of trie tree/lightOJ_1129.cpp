#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int cnt;
    node* next[10];
    node() {
        cnt = 0;
        for (int i = 0; i < 10; next[i] = NULL, i++);
    }
} * root;
 
void insert(string s) {
    node *cur = root;
    for (int i = 0; s[i]; i++) {
        int id = s[i] - '0';
        if (cur->next[id] == NULL) cur->next[id] = new node();
        cur = cur->next[id];
    }
    cur->cnt++;
}

bool search(string s) {
    node *cur = root;
    for (int i = 0; s[i]; i++) {
        int id = s[i] - '0';
        cur = cur->next[id];
    }
    if (cur->cnt > 1) return true;
    for (int i = 0; i < 10; i++)
        if(cur->next[i] != NULL) return true;
    return false;
}
 
void del(node* cur) {
    for (int i = 0; i < 10; i++)
        if (cur->next[i]) del(cur->next[i]);
    delete(cur);
}
 
int main() {
    int tst, t = 1, n, q;
    string s;
    for (scanf("%d", &tst); tst--; ) {
        root = new node();
        bool flg = true;
        scanf("%d", &n);
        vector <string> v;
        getchar();
        while (n--) {
            cin >> s;
            insert(s);
            v.push_back(s);
        }
    	for (int i = 0; i < v.size(); i++) {
            if (search(v[i])) {
                flg = false; break;
            }    
        }
        cout << "Case " << t++ << ": " << ((flg) ? "YES\n" : "NO\n");
        del(root);
    }
}
