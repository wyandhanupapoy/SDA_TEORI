/*
  Nama File: binary_tree_anggota1.c
  Pembuat: Wyandhanu Maulidan Nugraha
  NIM: 241511092
  Kelas: JTK-1C
  Jurusan: Teknik Komputer dan Informatika
  Prodi: D3 Teknik Informatika

  Tujuan: Implementasi Binary Tree dengan traversal inorder secara non-rekursif.
*/
#include "binary_tree_anggota1.h"



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