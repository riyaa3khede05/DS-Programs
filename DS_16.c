#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int data) {
    if (root == NULL) 
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

Node* findMin(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}


Node* findMax(Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

int main() {
    Node* root = NULL;

    // Insert sample data
    int arr[] = {20, 10, 5, 15, 30, 25, 40};
    for (int i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    Node* mn = findMin(root);
    Node* mx = findMax(root);

    printf("Minimum element in BST = %d\n", mn->data);
    printf("Maximum element in BST = %d\n", mx->data);

    return 0;
}
