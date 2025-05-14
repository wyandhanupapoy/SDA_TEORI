#ifndef ADT_UNIVERSAL_H
#define ADT_UNIVERSAL_H

struct Node* createNode(int data);
struct Stack* createStack(int size);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
void push(struct Stack* stack, struct Node* item);
struct Node* pop(struct Stack* stack);
struct Node* peek(struct Stack* stack);

#endif