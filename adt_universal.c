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

// Fungsi untuk membuat queue baru
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // Ini adalah trik untuk membuat rear menjadi 0 pada enqueue pertama
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}

// Fungsi untuk memeriksa apakah queue penuh
int isQueueFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Fungsi untuk memeriksa apakah queue kosong
int isQueueEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Fungsi untuk menambahkan item ke queue
void enqueue(struct Queue* queue, struct Node* item) {
    if (isQueueFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Fungsi untuk mengambil item dari queue
struct Node* dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue))
        return NULL;
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
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