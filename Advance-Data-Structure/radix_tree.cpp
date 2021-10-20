// Radix tree

#include <bits/stdc++.h>
using namespace std;

struct node {
	bool isWord;
	node* next[26+1];

	node() {
		isWord = false;
		for (int i = 0; i < 26; next[i] = NULL, i++);
	}
} * root;

void insert(char* str, int len) {
    node* cur = root;
    for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (cur->next[id] == NULL) cur->next[id] = new node();
		cur = cur->next[id];
    }
    cur->isWord = true;
}

bool search(char* str, int len) {
	node* cur = root;
	for (int i = 0; i < len; i++) {
			int id = str[i] - 'a';
			if (cur->next[id] == NULL) return false;
			cur = cur->next[id];
	}
	return cur->isWord;
}

void del(node* cur) {
	for (int i = 0; i < 26; i++)
			if (cur->next[i]) del(cur->next[i]);
	delete(cur);
}

int main() {
	int n, q;
	root = new node();
	puts("Enter number of words:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char s[50];
		scanf("%s", s);
		insert(s, strlen(s));
	}
	puts("Enter number of query:");
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		char s[50];
		scanf("%s", s);
		if (search(s, strlen(s))) puts("FOUND!");
		else puts("NOT FOUND!");
	}
	return 0;
}
