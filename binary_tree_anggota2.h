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

#ifndef BINARY_TREE_ANGGOTA2_H
#define BINARY_TREE_ANGGOTA2_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "struktur_data.h"

// Fungsi Deklarasi
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
struct Node* search(struct Node* root, int key);

#endif