#include <bits/stdc++.h>
using namespace std;

typedef pair <pair < int, int>, int> elephant;
vector <elephant> vec;
int mm[10000], gg[10000], maxlen = 0, idx = 0, cnt = 0;

void memomization() {
    for (int i = cnt-1; i >= 0; i--) {
        mm[i] = 1;
        gg[i] = -1;
        for (int j = i+1; j < cnt; j++) {
            if (vec[i].first.second > vec[j].first.second) {
                if (mm[j] + 1 > mm[i]) {
                    mm[i] = mm[j] + 1;
                    gg[i] = j;
                }
            }
        }
        if (maxlen < mm[i]) {
            maxlen = mm[i];
            idx = i;
        }
    }
    printf("%d\n", maxlen);
    while (idx != -1) {
        printf("%d\n", vec[idx].second);
        idx = gg[idx];
    }
}

int main() {
//    freopen("in", "r", stdin);
    elephant tmp;
    while (scanf("%d %d", &tmp.first.first, &tmp.first.second) != EOF) {
        tmp.second = ++cnt;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    memomization();
//    for (int i = 0; i < 9; i++) {
//        cout << vec[i].first.first << " " << vec[i].first.second << endl;
//    }
}
