using System;

public class BinarySearchTree {

    public class Node {
        public int data;
        public Node left, right;

        public Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    public Node Insert(Node root, int data) {
        if (root == null) root = new Node(data);
        else if (data <= root.data) root.left = Insert(root.left, data);
        else root.right = Insert(root.right, data);
        return root;
    }

    public bool Search(Node root, int data) {
        if (root == null) return false;
        if (data == root.data) return true;
        if (data < root.data) return Search(root.left, data);
        else return Search(root.right, data);
    }

    public Node FindMin(Node root) {
        while (root.left != null) root = root.left;
        return root;
    }

    public Node Delete(Node root, int data) {
        if (root == null) return root;
        else if (data < root.data) Delete(root.left, data);
        else if (data > root.data) Delete(root.right, data);

        else {
            if (root.left == null && root.right == null) {
                root = null; // leaf node, code need to fix
            }
            else if (root.right == null) root = root.left;
            else if (root.left == null) root = root.right;
            else {
                Node temp = FindMin(root.right);
                root.data = temp.data;
                root.right = Delete(root.right, temp.data);
            }
        }
        return root;
    }

    public void Preorder(Node root) {
        if (root == null) return;
        Console.WriteLine(root.data);
        Preorder(root.left);
        Preorder(root.right);
    }

    public void Inorder(Node root) {
        if (root == null) return;
        Inorder(root.left);
        Console.WriteLine(root.data);
        Inorder(root.right);
    }

    public void Postorder(Node root) {
        if (root == null) return;
        Postorder(root.left);
        Postorder(root.right);
        Console.WriteLine(root.data);
    }

    public void manageBinarySearch() {
        Node root = null;
        root = Insert(root, 15);
        root = Insert(root, 10);
        root = Insert(root, 35);
        root = Insert(root, 55);
        root = Insert(root, 5);

        // Console.WriteLine(Search(root, 30));

        // Postorder(root);

        root = Delete(root, 15);

        Postorder(root);
    }
}