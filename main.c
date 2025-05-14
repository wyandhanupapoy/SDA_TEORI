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
#include "binary_tree_anggota1.h"
#include "struktur_data.h"
#include "adt_universal.h"

int main() {
    struct Node* root = NULL;
    
    // Masukkan beberapa nilai
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);
    
    // Cetak traversal inorder
    inorderTraversal(root);
    
    printf("Tugas Bagian 1 selesai. Bagian 2 mengimplementasikan traversal preorder, postorder dan pencarian.\n");
    
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