#ifndef STRUKTUR_DATA_H
#define STRUKTUR_DATA_H

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

struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};

#endif