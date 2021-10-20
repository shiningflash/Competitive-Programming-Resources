#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void InsertBegin(Node** head, int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (*head != NULL) temp->next = *head;
    *head = temp;
}

void Insert(Node** head, int data, int pos) {
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;

    // pos at the beginning
    if (pos == 1) {
        temp1->next = *head;
        *head = temp1;
        return;
    }

    // n'th position
    Node* temp2 = *head;
    for (int i = 1; i < pos-1; i++) temp2 = temp2->next;

    temp1->next = temp2->next;
    temp2->next = temp1;
}

Node* Reverse(Node* head) {
    Node *current, *prev, *next;
    current = head;
    prev = next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

Node* ReverseRecursive(Node* head) {
    if (head->next == NULL) {
        return head;
    }
    Node* temp = ReverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

void Delete(Node** head, int pos) {
    Node* temp1 = *head;

    // delete first node
    if (pos == 1) {
        *head = temp1->next;
        free(temp1); // de-allocate the memory
        return;
    }

    // n'th position
    for (int i = 1; i < pos-1; i++) temp1 = temp1->next;

    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void print(Node* temp) {
    while (temp == NULL) return;
    cout << temp->data << " ";
    print(temp->next);
}

void print_recursive(Node* temp) {
    while (temp == NULL) return;
    print_recursive(temp->next);
    cout << temp->data << " ";
}

void printList(Node* head) {
    cout << "\n=> ";
    print(head);
    cout << "\n";
    cout << "<= ";
    print_recursive(head);
    cout << "\n\n";
}

Node* middleNode(Node* head) {
    if (head == NULL) {
        return head;
    }
    
    Node* a = head;
    Node* b = head->next;

    while (b != NULL && b->next != NULL) {
        a = a->next;
        b = b->next->next;
    }

    return a;
}

Node* Merge(Node* a, Node* b) {
    Node* temp = new Node();
    Node* resultList = temp;

    while (a != NULL && b != NULL) {
        if (a->data > b->data) {
            temp->next = a;
            a = a->next;
        }
        else {
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;
    }

    temp->next = (a == NULL) ? b : a;
    return resultList->next;
}

Node* MergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* middle = middleNode(head);
    Node* secondHalf = middle->next;
    middle->next = NULL; // end of first half

    return Merge(MergeSort(head), MergeSort(secondHalf));
}

int main() {
    Node* head = NULL;
    
    InsertBegin(&head, 1);
    InsertBegin(&head, 5);
    InsertBegin(&head, 10);
    InsertBegin(&head, 3);
    InsertBegin(&head, 21);
    printList(head);

    Insert(&head, 12, 1);
    Insert(&head, 13, 2);
    printList(head);

    Delete(&head, 2);
    Delete(&head, 1);
    printList(head);

    cout << "Sort:\n";
    Node* sorted = MergeSort(head);
    printList(sorted);

    cout << "Reverse:\n";
    Node* rec = ReverseRecursive(head);
    printList(rec);


}

/*

=> 2 3 4 5 6 
<= 6 5 4 3 2 


=> 12 13 2 3 4 5 6 
<= 6 5 4 3 2 13 12 


=> 2 3 4 5 6 
<= 6 5 4 3 2 


=> 6 5 4 3 2 
<= 2 3 4 5 6 

*/