/*
  Nama File: main.c
  Pembuat: 
    1. Wyandhanu Maulidan Nugraha (NIM: 241511092)
    2. Dzakir Tsabit Asy Syafiq (NIM: 241511071)
  Kelas: JTK-1C
  Jurusan: Teknik Komputer dan Informatika
  Prodi: D3 Teknik Informatika

  Tujuan: Program utama untuk mendemonstrasikan implementasi Binary Tree
          dengan semua fungsi traversal dan pencarian.
*/

// Include file header untuk kedua implementasi binary tree
#include "binary_tree_anggota1.h"
#include "binary_tree_anggota2.h"
#include "universal_binarytree.h"

int main() {
    struct Node* root = NULL;
    
    // Insert data ke dalam binary tree menggunakan fungsi dari anggota1
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);
    
    printf("Binary Tree sudah dibuat dengan nilai: 50, 30, 70, 20, 40, 60, 80\n\n");
    
    // Cetak traversal dari binary tree
    printf("=== Traversal Binary Tree ===\n");
    inorderTraversal(root);   // Implementasi dari anggota1
    preorderTraversal(root);  // Implementasi dari anggota2
    postorderTraversal(root); // Implementasi dari anggota2
    printf("\n");
    
    // Demonstrasi pencarian dari anggota2
    printf("=== Hasil Pencarian Nilai ===\n");
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
    
    printf("\nTugas selesai. Implementasi Binary Tree dengan:\n");
    printf("1. Traversal inorder (Wyandhanu Maulidan Nugraha)\n");
    printf("2. Traversal preorder dan postorder (Dzakir Tsabit Asy Syafiq)\n");
    printf("3. Fungsi pencarian (Dzakir Tsabit Asy Syafiq)\n");
    
    return 0;
}