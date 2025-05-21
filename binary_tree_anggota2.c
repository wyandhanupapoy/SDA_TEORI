/*
  Nama File: binary_tree_anggota2.h 
  Pembuat: Dzakir Tsabit Asy Syafiq
  NIM: 241511071
  Kelas: JTK-1C
  Jurusan: Teknik Komputer dan Informatika
  Prodi: D3 Teknik Informatika

  Tujuan: Implementasi Binary Tree dengan traversal preorder dan postorder secara non-rekursif, 
          serta implementasi fungsi pencarian (search) pada binary tree secara iteratif.
*/
#include "binary_tree_anggota2.h"
#include "struktur_data.h"
#include "adt_universal.h"

// Struktur node untuk binary tree
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

