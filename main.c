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

// Fungsi untuk menampilkan menu
void displayMenu() {
    printf("\n=== BINARY TREE OPERATIONS ===\n");
    printf("1. Insert Node\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Level Order Traversal\n");
    printf("6. Search Node\n");
    printf("7. Create Sample Tree\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    struct Node* result;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Insert Node
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&root, value);
                printf("Node with value %d inserted successfully!\n", value);
                break;
                
            case 2: // Inorder Traversal
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    inorderTraversal(root);
                }
                break;
                
            case 3: // Preorder Traversal
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    preorderTraversal(root);
                }
                break;
                
            case 4: // Postorder Traversal
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    postorderTraversal(root);
                }
                break;
                
            case 5: // Level Order Traversal
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    levelOrderTraversal(root);
                }
                break;
                
            case 6: // Search Node
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Enter value to search: ");
                    scanf("%d", &value);
                    result = search(root, value);
                    if (result != NULL) {
                        printf("Value %d found in the tree!\n", value);
                    } else {
                        printf("Value %d not found in the tree!\n", value);
                    }
                }
                break;
                
            case 7: // Create Sample Tree
                // Clear existing tree first (simplified approach)
                root = NULL;
                
                // Create a sample binary tree
                root = createNode(50);
                root->left = createNode(30);
                root->right = createNode(70);
                root->left->left = createNode(20);
                root->left->right = createNode(40);
                root->right->left = createNode(60);
                root->right->right = createNode(80);
                
                printf("Sample tree created successfully!\n");
                printf("The tree has the following structure:\n");
                printf("        50        \n");
                printf("       /  \\      \n");
                printf("     30    70     \n");
                printf("    / \\   / \\   \n");
                printf("   20 40 60  80   \n");
                break;
                
            case 8: // Exit
                printf("Thank you for using Binary Tree Operations!\n");
                // Free memory (in a real implementation, you'd want to properly free all nodes)
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        while (getchar() != '\n'); // Clear input buffer
        getchar(); // Wait for Enter
        clearScreen();
    }
    
    return 0;
}