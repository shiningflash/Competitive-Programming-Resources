/*
    @author      : Amirul Islam
    @topic       : Binary Search Tree
    @description : Insert O( log N ), Seach O( log N ), Delete O( log N ), Print O( N )
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* Insert(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(Node* root, int data) {
    // Empty BST
    if (root == NULL) return false;

    // YES! FOUND ...
    if (data == root->data) return true;

    if (data < root->data) {
        return Search(root->left, data);
    }
    else {
        return Search(root->right, data);
    }
}

Node* FindMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* Delete(Node* root, int data) {
    // Empty 
    if (root == NULL) return root;
    
    else if (data < root->data) {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data) {
        root->right = Delete(root->right, data);
    }

    // FOUND
    else {
        if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else {
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void Preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

// PRINT IN SORTED ORDER
void Inorder(Node* root) {
    if (root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Postorder(Node* root) {
    if (root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

void PrintBST(Node* root) {
    cout << "\nPre Order: ";
    Preorder(root);
    cout << "\nIn Order: ";
    Inorder(root);
    cout << "\nPost Order: ";
    Postorder(root);
    cout << "\n";
}

void printSearchResult(Node* root, int n) {
    cout << n << (Search(root, n) ? " FOUND!\n" : " NOT FOUND!\n");
}

int main() {
    Node* root = NULL;

    /*
	                    35
			   / \
			  10  55
			 / \ 
			5  15
    */

    // insert data
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 35);
    root = Insert(root, 55);
    root = Insert(root, 5);
    
    printSearchResult(root, 10);
    printSearchResult(root, 25);

    // print data in different order
    PrintBST(root);

    // delete data
    int n = 35;
    root = Delete(root, n);
    cout << "\n" << n << " DELETED!\n";

    PrintBST(root);

    return 0;
}

/*
10 FOUND!
25 NOT FOUND!

Pre Order: 15 10 5 35 55 
In Order: 5 10 15 35 55 
Post Order: 5 10 55 35 15 

35 DELETED!

Pre Order: 15 10 5 55 
In Order: 5 10 15 55 
Post Order: 5 10 55 15
*/