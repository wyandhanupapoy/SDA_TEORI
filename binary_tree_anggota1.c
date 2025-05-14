/* Bagian 1: Implementasi Binary Tree Non-Rekursif */
#include "binary_tree_anggota1.h"


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

// Fungsi untuk memasukkan node ke dalam binary tree secara iteratif
void insert(struct Node** root, int data) {
    // Buat node baru
    struct Node* newNode = createNode(data);
    
    // Jika tree kosong, jadikan node baru sebagai root
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    
    // Stack untuk traversal
    struct Stack* stack = createStack(100);
    struct Node* current = *root;
    struct Node* parent = NULL;
    
    // Cari tempat yang tepat untuk memasukkan node
    while (1) {
        // Simpan node saat ini di stack
        push(stack, current);
        
        // Jika nilai yang akan dimasukkan lebih kecil, pergi ke kiri
        if (data < current->data) {
            // Jika tidak ada node di kiri, masukkan di sini
            if (current->left == NULL) {
                current->left = newNode;
                break;
            } else {
                current = current->left;
            }
        }
        // Jika nilai yang akan dimasukkan lebih besar atau sama, pergi ke kanan
        else {
            // Jika tidak ada node di kanan, masukkan di sini
            if (current->right == NULL) {
                current->right = newNode;
                break;
            } else {
                current = current->right;
            }
        }
    }
    
    // Bersihkan stack
    free(stack->array);
    free(stack);
}

// Fungsi untuk mencetak traversal inorder (kiri, root, kanan) secara non-rekursif
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    struct Stack* stack = createStack(100);
    struct Node* current = root;
    
    printf("Inorder Traversal: ");
    
    while (current != NULL || !isEmpty(stack)) {
        // Pergi ke node paling kiri
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        
        // Ambil node teratas dari stack
        current = pop(stack);
        
        // Cetak data
        printf("%d ", current->data);
        
        // Pergi ke node kanan
        current = current->right;
    }
    
    printf("\n");
    
    // Bersihkan stack
    free(stack->array);
    free(stack);
}