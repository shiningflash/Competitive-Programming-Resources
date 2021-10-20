#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* addNodeToEmpty(Node* last, int data) {
    if (last != NULL) return last; // not empty list

    Node* temp = new Node();
    temp->data = data;
    last = temp;
    temp->next = last;

    return last;
}

Node* addNodeBegin(Node* last, int data) {
    if (last == NULL) return addNodeToEmpty(last, data); // empty list

    Node* temp = new Node();
    temp->data = data;
    temp->next = last->next;
    last->next = temp;

    return last;
}

Node* addNodeEnd(Node* last, int data) {
    if (last == NULL) return addNodeToEmpty(last, data); // empty list

    Node* temp = new Node();
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}

void traverse(Node* last) {
    if (last == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    
    Node* temp = last->next;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);
    
    cout << endl;
}

int main() {
    Node* root;
    root = addNodeToEmpty(root, 6);
    root = addNodeBegin(root, 4);
    root = addNodeBegin(root, 2);
    root = addNodeEnd(root, 8);
    traverse(root);
}