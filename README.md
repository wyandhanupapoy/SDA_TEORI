# Implementasi Binary Tree Non-Rekursif dalam Bahasa C

Repositori ini berisi implementasi binary tree non-rekursif dalam bahasa C untuk tugas mahasiswa teknik informatika D3 semester 2. Program ini dirancang untuk dapat dibagi menjadi dua bagian yang bisa dikerjakan secara terpisah oleh dua mahasiswa.

## Struktur Proyek

Proyek ini terbagi menjadi dua bagian utama:

### Bagian 1: Implementasi Dasar Binary Tree

- `binary_tree_anggota1.h` - Header file yang berisi deklarasi struktur data dan fungsi-fungsi dasar
- `binary_tree_anggota1.c` - Implementasi dari struktur data dan fungsi-fungsi dasar
- `main.c` - Program utama untuk menjalankan dan menguji implementasi dasar

Fitur yang diimplementasikan:
- Struktur data Node dan Stack
- Fungsi untuk operasi stack (push, pop, peek)
- Implementasi insert untuk memasukkan node secara iteratif
- Implementasi traversal inorder secara non-rekursif

### Bagian 2: Implementasi Lanjutan Binary Tree

- `binary_tree_anggota2.h` - Header file yang berisi deklarasi struktur data dan fungsi-fungsi lanjutan
- `binary_tree_anggota2.c` - Implementasi dari struktur data dan fungsi-fungsi lanjutan
- `main2.c` - Program utama untuk menjalankan dan menguji implementasi lanjutan

Fitur yang diimplementasikan:
- Struktur data dan fungsi dasar (struktur sama dengan bagian 1)
- Implementasi traversal preorder secara non-rekursif
- Implementasi traversal postorder secara non-rekursif (menggunakan dua stack)
- Implementasi fungsi search untuk mencari nilai dalam binary tree

## Tujuan Pembelajaran

Melalui pengerjaan tugas ini, mahasiswa diharapkan dapat mempelajari:

1. Implementasi struktur data binary tree
2. Operasi-operasi pada binary tree (insert, search)
3. Algoritma traversal (inorder, preorder, postorder) secara non-rekursif
4. Penggunaan stack dalam implementasi algoritma iteratif

## Cara Kompilasi dan Menjalankan Program

### Bagian 1

```bash
gcc binary_tree_anggota1.c main.c -o binary_tree_bagian1
./binary_tree_bagian1
```

### Bagian 2

```bash
gcc binary_tree_anggota2.c main2.c -o binary_tree_bagian2
./binary_tree_bagian2
```

## Gambaran Implementasi

### Struktur Data Utama

```c
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
```

### Contoh Output Program

**Bagian 1 (Traversal Inorder):**
```
Inorder Traversal: 20 30 40 50 60 70 80
```

**Bagian 2 (Traversal Preorder dan Postorder):**
```
Preorder Traversal: 50 30 20 40 70 60 80
Postorder Traversal: 20 40 30 60 80 70 50
```

## Pengembangan Lebih Lanjut

Mahasiswa dapat mengembangkan proyek ini dengan menambahkan fitur-fitur seperti:
- Implementasi delete node
- Fungsi untuk menghitung tinggi tree
- Visualisasi tree dalam bentuk grafis
- Balancing binary tree (AVL atau Red-Black Tree)

## Kontributor

- Bagian 1: Wyandhanu Maulidan Nugraha (241511092)
- Bagian 2: Dzakir Tsabit Asy Syafiq (241511071)

## Lisensi

Program ini dibuat untuk tujuan pendidikan di lingkungan akademik.