#ifndef __NODE_H__
#define __NODE_H__
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef char Data;

struct node{
    char data;
    struct node *next;
};

typedef struct node Node;

Node *node_creat(char d);
void node_destroy(Node *n);
void node_print(Node *n);


#endif
