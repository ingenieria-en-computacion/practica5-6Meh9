#include "queue.h"
#include <stdlib.h>

Queue* queue_create(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL; //-1 es un indice no valido 
    q->tail = NULL;
    return q;
}

void queue_enqueue(Queue* q, Data d){
    Node *newNode = node_creat(d); //crea el nodo que quiero encolar 
    if(node_empty(q)){ // quite un asterisco de la c 
        q->head = q->tail=newNode;
        return;
    }
    q->tail->next= newNode;
    q->tail = newNode;

}

Data queue_dequeue(Queue* q){
    if(!queue_is_empty (q)){
        Node *temp = q->head;
        q->head = q->head->next;
        temp->next = NULL;
        node_destroy(temp);
    }

}

bool queue_is_empty(Queue* q){
    return q->tail == NULL;
}

Data queue_front(Queue* q){

}

void queue_empty(Queue* q){

}

void queue_delete(Queue* q){

}