#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[30];
    struct node* left;
    struct node* right;
};

typedef struct node Node;

Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, const char* data) {
    if (root == NULL) {
        return createNode(data);
    } else if (strcmp(data, root->data) <= 0) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorderTraversal(Node* root, FILE* file) {
    if (root != NULL) {
        inorderTraversal(root->left, file);
        fprintf(file, "%s ", root->data);
        inorderTraversal(root->right, file);
    }
}

void preorderTraversal(Node* root, FILE* file) {
    if (root != NULL) {
        fprintf(file, "%s ", root->data);
        preorderTraversal(root->left, file);
        preorderTraversal(root->right, file);
    }
}

void postorderTraversal(Node* root, FILE* file) {
    if (root != NULL) {
        postorderTraversal(root->left, file);
        postorderTraversal(root->right, file);
        fprintf(file, "%s ", root->data);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open the input file.\n");
        return 1;
    }

    Node* root = NULL;
    char data[30];
    while (fscanf(inputFile, "%s", data) != EOF) {
        root = insert(root, data);
    }

    fclose(inputFile);

    FILE* inorderFile = fopen("Inorder.txt", "w");
    if (inorderFile == NULL) {
        printf("Error: Unable to open the Inorder.txt file.\n");
        return 1;
    }
    inorderTraversal(root, inorderFile);
    fclose(inorderFile);

    FILE* preorderFile = fopen("Preorder.txt", "w");
    if (preorderFile == NULL) {
        printf("Error: Unable to open the Preorder.txt file.\n");
        return 1;
    }
    preorderTraversal(root, preorderFile);
    fclose(preorderFile);

    FILE* postorderFile = fopen("Postorder.txt", "w");
    if (postorderFile == NULL) {
        printf("Error: Unable to open the Postorder.txt file.\n");
        return 1;
    }
    postorderTraversal(root, postorderFile);
    fclose(postorderFile);

    return 0;
}
