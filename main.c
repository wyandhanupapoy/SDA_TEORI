/*
  Nama File: main.c
  Pembuat: Wyandhanu Maulidan Nugraha
  NIM: 241511092
  Kelas: JTK-1C
  Jurusan: Teknik Komputer dan Informatika
  Prodi: D3 Teknik Informatika

  Tujuan: Implementasi Binary Tree dengan traversal inorder secara non-rekursif.
*/
#include "binary_tree_anggota1.h"

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
    return 0;
}