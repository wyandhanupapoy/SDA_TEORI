/*
  Nama File: main.c
  Pembuat: Kelompok JTK-1C
  Anggota:
  - Wyandhanu Maulidan Nugraha (241511092)
  - Dzakir Tsabit Asy Syafiq (241511071)
  - [Your Name]

  Kelas: JTK-1C
  Jurusan: Teknik Komputer dan Informatika
  Prodi: D3 Teknik Informatika

  Tujuan: Program utama untuk implementasi Binary Tree dengan berbagai jenis traversal
          dan operasi secara non-rekursif.
*/

#include <stdio.h>
#include <stdlib.h>

#include "binary_tree_anggota1.h"
#include "binary_tree_anggota2.h"
#include "struktur_data.h"
#include "adt_universal.h"

// Fungsi untuk membersihkan layar konsol
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Fungsi untuk menampilkan garis pemisah
void printSeparator() {
    printf("\n");
    for(int i = 0; i < 50; i++) {
        printf("=");
    }
    printf("\n");
}

// Fungsi untuk menampilkan header demo
void printHeader(const char* title) {
    printSeparator();
    printf("  %s\n", title);
    printSeparator();
}

// Fungsi untuk menampilkan visual dari binary tree (simplified)
void printBinaryTree(struct Node* root, int level) {
    if (root == NULL) return;
    
    printBinaryTree(root->right, level + 1);
    
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%d\n", root->data);
    
    printBinaryTree(root->left, level + 1);
}

int main() {
    printf("PROGRAM DEMONSTRASI BINARY TREE\n");
    printf("Teknik Informatika - JTK-1C\n\n");
    
    // 1. Membuat binary tree kosong
    printHeader("1. Membuat Binary Tree Kosong");
    struct Node* root = NULL;
    printf("Binary tree kosong berhasil dibuat!\n");
    
    // 2. Membuat sample tree dengan insertion iterative
    printHeader("2. Membuat Binary Tree dengan Insertion");
    printf("Memasukkan nilai: 50, 30, 70, 20, 40, 60, 80\n");
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);
    printf("Binary tree berhasil dibuat!\n");
    
    // 3. Menampilkan struktur binary tree
    printHeader("3. Struktur Binary Tree");
    printf("Visualisasi tree:\n\n");
    printBinaryTree(root, 0);
    printf("\nModel struktur tree:\n");
    printf("        50        \n");
    printf("       /  \\      \n");
    printf("     30    70     \n");
    printf("    / \\   / \\   \n");
    printf("   20 40 60  80   \n");
    
    // 4. Traversal Inorder
    printHeader("4. Traversal Inorder (Kiri-Root-Kanan)");
    printf("Expected result: 20 30 40 50 60 70 80\n");
    inorderTraversal(root);
    
    // 5. Traversal Preorder
    printHeader("5. Traversal Preorder (Root-Kiri-Kanan)");
    printf("Expected result: 50 30 20 40 70 60 80\n");
    preorderTraversal(root);
    
    // 6. Traversal Postorder
    printHeader("6. Traversal Postorder (Kiri-Kanan-Root)");
    printf("Expected result: 20 40 30 60 80 70 50\n");
    postorderTraversal(root);
    
    // 7. Traversal Level Order
    printHeader("7. Traversal Level Order (Breadth-First)");
    printf("Expected result: 50 30 70 20 40 60 80\n");
    levelOrderTraversal(root);
    
    // 8. Pencarian Node
    printHeader("8. Pencarian Node");
    int searchValues[] = {40, 55};
    for (int i = 0; i < 2; i++) {
        int value = searchValues[i];
        printf("Mencari nilai %d: ", value);
        struct Node* result = search(root, value);
        if (result != NULL) {
            printf("DITEMUKAN!\n");
        } else {
            printf("TIDAK DITEMUKAN!\n");
        }
    }
    
    // 9. Menambahkan node baru
    printHeader("9. Menambahkan Node Baru");
    int newValues[] = {25, 35, 90};
    printf("Menambahkan node baru dengan nilai: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", newValues[i]);
        insert(&root, newValues[i]);
    }
    printf("\n\nStruktur tree setelah penambahan:\n");
    printBinaryTree(root, 0);
    
    // 10. Menampilkan semua traversal kembali setelah penambahan
    printHeader("10. Traversal Setelah Penambahan Node");
    printf("Inorder: ");
    inorderTraversal(root);
    printf("Preorder: ");
    preorderTraversal(root);
    printf("Postorder: ");
    postorderTraversal(root);
    printf("Level Order: ");
    levelOrderTraversal(root);
    
    // 11. Eksperimen dengan multi-level tree
    printHeader("11. Eksperimen dengan Multi-level Tree");
    // Reset tree
    root = NULL;
    int values[] = {100, 50, 150, 25, 75, 125, 175, 12, 37, 62, 87, 112, 137, 162, 187};
    int n = sizeof(values) / sizeof(values[0]);
    
    printf("Membangun multi-level tree dengan %d node...\n", n);
    for (int i = 0; i < n; i++) {
        insert(&root, values[i]);
    }
    
    printf("\nStruktur multi-level tree:\n");
    printBinaryTree(root, 0);
    
    printf("\nLevel Order Traversal untuk multi-level tree:\n");
    levelOrderTraversal(root);
    
    // 12. Demonstrasi ADT Universal
    printHeader("12. Demonstrasi ADT Universal");
    printf("Membuat queue kapasitas 10...\n");
    struct Queue* queue = createQueue(10);
    printf("Queue berhasil dibuat dengan kapasitas %d\n", queue->capacity);
    printf("Apakah queue kosong? %s\n", isQueueEmpty(queue) ? "Ya" : "Tidak");
    
    printf("\nMembuat stack kapasitas 10...\n");
    struct Stack* stack = createStack(10);
    printf("Stack berhasil dibuat dengan kapasitas %d\n", stack->size);
    printf("Apakah stack kosong? %s\n", isEmpty(stack) ? "Ya" : "Tidak");
    
    // 13. Ringkasan
    printHeader("13. Ringkasan Demo");
    printf("Demonstrasi telah menunjukkan:\n");
    printf("1. Pembuatan binary tree\n");
    printf("2. Insertion node secara iteratif\n");
    printf("3. Traversal inorder (non-rekursif)\n");
    printf("4. Traversal preorder (non-rekursif)\n");
    printf("5. Traversal postorder (non-rekursif)\n");
    printf("6. Traversal level order (breadth-first)\n");
    printf("7. Pencarian node secara iteratif\n");
    printf("8. Implementasi ADT Stack dan Queue\n");
    printf("\nSemua operasi diimplementasikan tanpa rekursi.\n");
    
    printSeparator();
    printf("Terima kasih telah menggunakan Program Binary Tree!\n");
    printSeparator();
    
    // Free memory (simplified approach)
    // Note: In a real implementation, you'd want to properly free all nodes
    
    return 0;
}