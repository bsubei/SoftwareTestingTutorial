#ifndef CS211_PROJ2_
#define CS211_PROJ2_

#include <stdio.h>
#include <stdlib.h>


// point struct for x y coordinates
typedef struct Point {
    int x;
    int y;
} Point;

// linked list node used for stack
typedef struct Node Node;
struct Node {
    Point point;
    Node *next;
};

/* function prototypes */
Node* stack_initialize(Point p);
int is_empty(Node* top);
void stack_push(Node** top, Point p);
void stack_pop(Node** top);
Point stack_peek(Node* top);
void stack_reset(Node** top);

#endif  // CS211_PROJ2_
