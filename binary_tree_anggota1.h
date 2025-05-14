/*
  Nama File: binary_tree_anggota1.h
  Pembuat: Wyandhanu Maulidan Nugraha
  NIM: 241511092
  Kelas: JTK-1C
  Jurusan: Teknik Komputer dan Informatika
  Prodi: D3 Teknik Informatika

  Tujuan: Header file untuk implementasi Binary Tree dengan traversal inorder secara non-rekursif.
*/
#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk binary tree
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

// Fungsi Deklarasi
struct Node* createNode(int data);
struct Stack* createStack(int size);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
void push(struct Stack* stack, struct Node* item);
struct Node* pop(struct Stack* stack);
struct Node* peek(struct Stack* stack);
void insert(struct Node** root, int data);
void inorderTraversal(struct Node* root);