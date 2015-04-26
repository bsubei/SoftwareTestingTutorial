#ifndef CS211_PROJ2_
#define CS211_PROJ2_

#include <stdio.h>
#include <stdlib.h>

// linked list node used for stack
typedef struct Node Node;
struct Node {
    int number;
    Node *next;
};

/* function prototypes */
Node* stack_initialize(int n);
int is_empty(Node* top);
void stack_push(Node** top, int n);
void stack_pop(Node** top);
int stack_peek(Node* top);
void stack_reset(Node** top);

#endif  // CS211_PROJ2_
