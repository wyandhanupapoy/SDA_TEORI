/*
  Nama File: binary_tree_anggota1.h
  Pembuat: Wyandhanu Maulidan Nugraha
  NIM: 241511092
  Kelas: JTK-1C
  Jurusan: Teknik Komputer dan Informatika
  Prodi: D3 Teknik Informatika

  Tujuan: Header file untuk implementasi Binary Tree dengan traversal inorder secara non-rekursif.
*/
#ifndef BINARY_TREE_ANGGOTA1_H
#define BINARY_TREE_ANGGOTA1_H

#include <stdio.h>
#include <stdlib.h>

#include "struktur_data.h"

// Fungsi Deklarasi
void insert(struct Node** root, int data);
void inorderTraversal(struct Node* root);
void levelOrderTraversal(struct Node* root);

#endif