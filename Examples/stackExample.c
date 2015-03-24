/* Copyright 2015 Basheer Subei
 *
 * Example for GoogleTest Tutorial
 * @author: Basheer Subei
 *
 */

#include "stackExample.h"

// returns topmost node of stack initialized with element
Node* stack_initialize(Point p) {
    Node* top = (Node *)malloc(sizeof(Node));
    top->point = p;
    top->next = NULL;

    return top;
}

// returns 1 if stack is empty, 0 otherwise
int is_empty(Node* top) {
    return top == NULL;
}

// places new element at the top of the stack
void stack_push(Node** top, Point p) {
    if (*top != NULL) {
        Node *new_top = (Node *)malloc(sizeof(Node));
        new_top->point = p;
        new_top->next = *top;
        *top = new_top;  // let old top point to top of stack
    }
}

// removes top element
void stack_pop(Node** top) {
    if (top != NULL) {
        Node *temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

// returns top element
Point stack_peek(Node* top) {
    return top->point;
}

// deallocates all elements in stack and makes top point to NULL
void stack_reset(Node** top) {
    while (*top != NULL) {
        Node *temp = *top;
        // if last element in stack
        if ((*top)->next == NULL)
            *top = NULL;
        // not last element in stack
        else
            *top = (*top)->next;

        free(temp);
    }
}
