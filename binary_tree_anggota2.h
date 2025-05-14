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

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Struktur untuk stack yang digunakan dalam traversal non-rekursif
struct Stack {
    int size;
    int top;
    struct Node** array;
};


struct Node* createNode(int data);
struct Stack* createStack(int size);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
void push(struct Stack* stack, struct Node* item);
void preorderTraversal(struct Node* root);
struct Node* pop(struct Stack* stack);
struct Node* peek(struct Stack* stack);
void postorderTraversal(struct Node* root);
struct Node* search(struct Node* root, int key);
#endif