//Kungu ian SCT221-0734/2022
// stephen charles  SCT221-0277/2022

#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the index of a specific element in an array
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Function to construct Binary Search Tree using in-order and post-order traversal outputs
Node* bst_construct(int inOrder[], int postOrder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }
    
    // Create a new node
    Node* newNode = createNode(postOrder[(*postIndex)]);
    (*postIndex)--;
    
    if (inStart == inEnd) {
        return newNode;
    }
    
    // Find index of newNode data in inOrder array
    int inIndex = findIndex(inOrder, inStart, inEnd, newNode->data);
    
    // Construct the right and left subtrees recursively
    newNode->right = bst_construct(inOrder, postOrder, inIndex + 1, inEnd, postIndex);
    newNode->left = bst_construct(inOrder, postOrder, inStart, inIndex - 1, postIndex);
    
    return newNode;
}

// Function to traverse Binary Search Tree in Breadth First Search (DFS) traversal
void bfsTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->data);
        
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

int main() {
    int postOrder[] = {5, 15, 10, 25, 45, 30, 20};
    int inOrder[] = {5, 10, 15, 20, 25, 30, 45};
    int postIndex = 6;
    
    Node* root = bst_construct(inOrder, postOrder, 0, 6, &postIndex);
    
    printf("BFS Traversal of the constructed BST: ");
    bfsTraversal(root);
    
    return 0;
}
