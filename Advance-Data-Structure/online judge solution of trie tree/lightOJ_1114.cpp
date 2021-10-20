#include <bits/stdc++.h>
using namespace std;

const int mx = 100005;
int zz = 0;

struct node {
    int cnt;
    int next[54];
    node() {
        cnt = 0;
        memset(next, -1, sizeof(next));
    }
} tree[mx];

void insert(string s) {
    int cur = 0, id;
    for (int i = 0; s[i]; i++) {
        id = ((s[i] >= 'a') ? s[i]-'a'+1 : s[i]-'A'+27);
        if (tree[cur].next[id] == -1) tree[cur].next[id] = ++zz;
        cur = tree[cur].next[id];
    }
    tree[cur].cnt++;
}

int search(string s) {
    int cur = 0, id;
    for (int i = 0; s[i]; i++) {
        id = ((s[i] >= 'a') ? s[i]-'a'+1 : s[i]-'A'+27);
        if (tree[cur].next[id] == -1) return 0;
        cur = tree[cur].next[id];
    }
    return tree[cur].cnt;
}

void CLEAR() {
    for (int i = 0; i <= zz; i++) {
        tree[i].cnt = 0;
        for (int j = 0; j < 54; j++)
            tree[i].next[j] = -1;
    }
    zz = 0;
}

int main() {
//    freopen("in", "r", stdin);
    int tst, t = 1, n, q;
    string s;
    for (scanf("%d", &tst); tst--;) {
        scanf("%d", &n);
        while (n--) {
            cin >> s;
            if (s.size() > 3) sort(s.begin()+1, s.end()-1);
            insert(s);
        }
        scanf("%d", &q);
        printf("Case %d:\n", t++);
        getchar();
        while (q--) {
            int ans = 1;
            getline(cin, s);
            stringstream ss(s);
            while (ss >> s) {
                if (s.length() > 3) sort(s.begin()+1, s.end()-1);
                ans *= search(s);
            }
            printf("%d\n", ans);
        }
        CLEAR();
    }
    return 0;
}
