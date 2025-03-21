#include "node.h"

Node *node_creat(char d){
    Node *nodeNew = (Node*)malloc(sizeof(Node));
    nodeNew->data = d;
    nodeNew->next = NULL;
    return nodeNew;
}

void node_destroy(Node *n){
    if(n->next == NULL){
        free(n);
        n=NULL;
    }
}

void node_print(Node *n){
    printf("Dato:%c\tSiguiente:%p\n", n->data, n->next);
}
