#include <bits/stdc++.h>
using namespace std;

struct node {
	bool mark;
	node* next[27];
	node() {
		mark = 0;
		for (int i = 0; i < 26; next[i] = NULL, i++);
	}
} *root;

void insert(char* s, int len) {
	node* cur = root;
	for (int i = 0; i < len; i++) {
		int id = s[i] - 'a';
		if (cur->next[id] == NULL) cur->next[id] = new node();
		cur = cur->next[id];
	}
	cur->mark = 1;
}

void dfs(char *s, int len, node* cur) {
	if (cur->mark) printf("%s\n", s);
	for (int i = 0; i < 26; i++) {
		if (cur->next[i] != NULL) {
			s[len + 1] = (i + 'a');
			s[len + 2] = '\0';
			dfs(s, len+1, cur->next[i]);
		}
	}
}

bool search(char* s, int len) {
	node* cur = root;
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		int id = s[i] - 'a';
		if (cur->next[id] == NULL) return false;
		cur = cur->next[id];
	}
	bool found = false;
	for (int i = 0; i < 26; i++) {
		if (cur->next[i] != NULL) {
			s[len] = (i + 'a');
			s[len + 1] = '\0';
			dfs(s, len, cur->next[i]);
			found = true;
		}
	}
	return found;
}

int main() {
	int n, q;
	char s[30];
	root = new node();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%s", s), insert(s, strlen(s));
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%s", s);
		printf("Case #%d:\n", i);
		if (!search(s, strlen(s))) printf("No match.\n");
	}
	return 0;
}

/*
INPUT:

5 :: _____given word
set
lol
setter
setting
settings
2 :: _____query by prefix
set
happy

OUTPUT:

Case #1: __ word with prefix 'set'
setter
setting
settings
Case #2: __ word with prefix 'happy'
No match.
*/
