/*                 _
 *  _|_ o._ o._  __|_| _. _|_
 * _>| ||| ||| |(_|| |(_|_>| |
 *               _|
 * @author Amirul islam Al Mamun
 * An Easy LCS LightOJ - 1110 >> DP
 */

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e3;

int path[mx][mx], cost[mx][mx];

int lcs(string s1, string s2) {
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            // common word
            if (s1[i-1] == s2[j-1]) {
                cost[i][j] = cost[i-1][j-1] + 1;
                path[i][j] = 1;
            }
            // UP greater
            else if (cost[i-1][j] >= cost[i][j-1]) {
                cost[i][j] = cost[i-1][j];
                path[i][j] = 2;
            }
            // LEFT greater
            else {
                cost[i][j] = cost[i][j-1];
                path[i][j] = 3;
            }
        }
    }
    return cost[s1.length()][s2.length()];
}

string get_lcs_string(string s1, string s2, int lcs_len) {
    // no common substring
    if (lcs_len == 0) {
        return ":(";
    }

    int i = s1.length();
    int j = s2.length();
    int k = lcs_len;

    stack <char> st;
    
    while (k > 0) {
        if (path[i][j] == 1) {
            st.push(s1[i-1]);
            i--;
            j--;
            k--;
        }
        else if (path[i][j] == 2) {
            i--;
        }
        else {
            j--;
        }
    }

    string lcs_str = "";
    while (!st.empty()) {
        lcs_str.push_back((char) st.top());
        st.pop();
    }

    return lcs_str;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int lcs_len = lcs(s1, s2);
    cout << get_lcs_string(s1, s2, lcs_len) << endl;
    return 0;
}
