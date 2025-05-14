#include "adt_universal.h"
#include "struktur_data.h"

#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk membuat node baru
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk membuat stack baru
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node**)malloc(stack->size * sizeof(struct Node*));
    return stack;
}

// Fungsi untuk memeriksa apakah stack kosong
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Fungsi untuk memeriksa apakah stack penuh
int isFull(struct Stack* stack) {
    return stack->top == stack->size - 1;
}

// Fungsi untuk menambahkan item ke stack (push)
void push(struct Stack* stack, struct Node* item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Fungsi untuk mengambil item dari stack (pop)
struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

// Fungsi untuk melihat item teratas dari stack tanpa menghapusnya
struct Node* peek(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}