//Write a C/C++ program that ask the user to enter 10 integer values. Use these values to construct a binary tree with 10 nodes. After constructing the tree,perform and display the inorder, preorder, and postorder traversals.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);
    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    int values[10];
    Node* root = NULL;

    printf("Enter 10 integer values:\n");
    for (int i = 0; i < 10; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &values[i]);
        root = insertNode(root, values[i]);
    }

    printf("\nInorder Traversal: ");
    inorderTraversal(root);

    printf("\nPreorder Traversal: ");
    preorderTraversal(root);

    printf("\nPostorder Traversal: ");
    postorderTraversal(root);

    printf("\n");

    return 0;
}
