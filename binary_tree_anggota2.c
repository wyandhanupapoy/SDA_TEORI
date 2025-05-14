/*
  Nama File: binary_tree_anggota2.c
  Pembuat: Dzakir Tsabit Asy Syafiq
  NIM: 241511071
  Kelas: JTK-1C
  Jurusan: Teknik Komputer dan Informatika
  Prodi: D3 Teknik Informatika

  Tujuan: Implementasi Binary Tree dengan traversal inorder secara non-rekursif.
*/
#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Fungsi untuk membuat node baru
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Struktur untuk stack yang digunakan dalam traversal non-rekursif
struct Stack {
    int size;
    int top;
    struct Node** array;
};

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

// Fungsi untuk mencetak traversal preorder (root, kiri, kanan) secara non-rekursif
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    struct Stack* stack = createStack(100);
    push(stack, root);
    
    printf("Preorder Traversal: ");
    
    while (!isEmpty(stack)) {
        // Pop node teratas
        struct Node* current = pop(stack);
        
        // Cetak data
        printf("%d ", current->data);
        
        // Push anak kanan dulu (karena stack LIFO), lalu anak kiri
        if (current->right != NULL)
            push(stack, current->right);
        if (current->left != NULL)
            push(stack, current->left);
    }
    
    printf("\n");
    
    // Bersihkan stack
    free(stack->array);
    free(stack);
}

// Fungsi untuk mencetak traversal postorder (kiri, kanan, root) secara non-rekursif
// Implementasi postorder non-rekursif lebih kompleks, menggunakan dua stack
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    struct Stack* stack1 = createStack(100);
    struct Stack* stack2 = createStack(100);
    
    push(stack1, root);
    
    // Pertama, kita membuat urutan root, kanan, kiri di stack2
    while (!isEmpty(stack1)) {
        struct Node* current = pop(stack1);
        push(stack2, current);
        
        if (current->left)
            push(stack1, current->left);
        if (current->right)
            push(stack1, current->right);
    }
    
    // Kemudian, kita mencetak stack2 untuk mendapatkan kiri, kanan, root
    printf("Postorder Traversal: ");
    while (!isEmpty(stack2)) {
        struct Node* current = pop(stack2);
        printf("%d ", current->data);
    }
    
    printf("\n");
    
    // Bersihkan stack
    free(stack1->array);
    free(stack1);
    free(stack2->array);
    free(stack2);
}

// Fungsi untuk mencari nilai dalam binary tree secara iteratif
struct Node* search(struct Node* root, int key) {
    struct Node* current = root;
    
    while (current != NULL) {
        if (key == current->data)
            return current;
        else if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }
    
    return NULL; // key tidak ditemukan
}

// Fungsi utama untuk Bagian 2
int main() {
    struct Node* root = NULL;
    
    // Buat binary tree secara manual untuk demonstrasi
    root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);
    
    // Cetak traversal preorder dan postorder
    preorderTraversal(root);
    postorderTraversal(root);
    
    // Demonstrasi pencarian
    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL)
        printf("Nilai %d ditemukan dalam tree\n", key);
    else
        printf("Nilai %d tidak ditemukan dalam tree\n", key);
    
    key = 55;
    result = search(root, key);
    if (result != NULL)
        printf("Nilai %d ditemukan dalam tree\n", key);
    else
        printf("Nilai %d tidak ditemukan dalam tree\n", key);
    
    printf("Tugas Bagian 2 selesai. Implementasi traversal preorder, postorder dan pencarian.\n");
    return 0;
}