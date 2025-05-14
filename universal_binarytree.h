#ifndef UNIVERSAL_BINARYTREE_H
#define UNIVERSAL_BINARYTREE_H

// Struktur node untuk binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// Struktur untuk stack yang digunakan dalam traversal non-rekursif
typedef struct Stack {
    int size;
    int top;
    struct Node** array;
}Stack;

#endif