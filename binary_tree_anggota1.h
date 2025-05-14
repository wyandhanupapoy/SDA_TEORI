#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Struktur untuk stack yang digunakan dalam traversal non-rekursif
struct Stack {
    int size;
    int top;
    struct Node** array;
};

// Fungsi untuk membuat stack baru
struct Node* createNode(int data);
struct Stack* createStack(int size);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
void push(struct Stack* stack, struct Node* item);
struct Node* pop(struct Stack* stack);
struct Node* peek(struct Stack* stack);
void insert(struct Node** root, int data);
void inorderTraversal(struct Node* root);