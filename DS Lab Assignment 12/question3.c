//Given the inorder and preorder traversals of a binary tree, write a C/C++ program to construct the binary tree.
// Inorder: 1, 8, 19, 13, 25, 9, 5, 10, 4, 3
// Preorder: 25, 8, 1, 13, 19, 5, 9, 4, 10, 3

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    int rootValue = preorder[*preIndex];
    (*preIndex)++;
    Node* root = createNode(rootValue);

    if (inStart == inEnd)
        return root;

    int inIndex = search(inorder, inStart, inEnd, rootValue);

    root->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    int inorder[SIZE] = {1, 8, 19, 13, 25, 9, 5, 10, 4, 3};
    int preorder[SIZE] = {25, 8, 1, 13, 19, 5, 9, 4, 10, 3};
    int preIndex = 0;

    Node* root = buildTree(inorder, preorder, 0, SIZE - 1, &preIndex);

    printf("Inorder traversal of the constructed tree:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
