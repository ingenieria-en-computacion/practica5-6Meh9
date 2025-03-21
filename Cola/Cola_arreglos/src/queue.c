#include "queue.h"
#include <stdlib.h>

/**
 * Crea una nueva cola vacía y la devuelve.
 * 
 * @param len cantidad de datos que se pueden guardar en el arreglo para la cola
 * @return Una nueva cola vacía. Si la creación falla, el estado de la cola es inválido.
 * @details Esta función inicializa una cola vacía. 
 */
Queue queue_create(){
    Queue q;
    q.len=0;
    q.head =-1;
    q.tail=1;
    return q;
}

/**
 * Inserta un elemento al final de la cola.
 * 
 * @param q Referencia a la cola donde se insertará el elemento.
 * @param d Dato que se insertará en la cola.
 * @details Esta función añade el dato `d` al final de la cola.
 */
void queue_enqueue(Queue* q, Data d){
    if(es_vacia(*q)){
        q->head = q->tail=0;
        q->datos[q->head]=d;
        return;
    }else{
    if(q->tail<TAM-1){
        q->tail++;
        q->datos[q->tail]=d;
        q->len++;
        return;
    }
    printf("La cola està llena \n");//agrega elemento al final de la cola   
    }
}

/**
 * Elimina y devuelve el elemento al frente de la cola.
 * 
 * @param q Referencia a la cola de la cual se eliminará el elemento.
 * @return El dato que estaba al frente de la cola. Si la cola está vacía o el puntero
 *         `q` es NULL, devuelve un valor que indica error (por ejemplo, un valor predeterminado).
 * @details Esta función elimina el elemento al frente de la cola y lo devuelve.
 *          Si la cola está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data queue_dequeue(Queue* q){
    if(es_vacia (*q)){
        for(int i=1; i<=q->tail; i++)
            q->datos[i-1] = q->datos[i]; //recorre el arreglo
            return; 
    }
    for(int i=1; i<=q->tail; i++){
    q->datos[i-1] = q->datos[i]; //recorre el arreglo
    return q->datos;
    printf("La cola esta vacia \n");
    }
}

/**
 * Verifica si la cola está vacía.
 * 
 * @param q Referencia a la cola que se desea verificar.
 * @return `true` si la cola está vacía, `false` si no lo está. 
 * @details Esta función comprueba si la cola no contiene elementos. Es útil para evitar operaciones
 *          como `queue_dequeue` en una cola vacía.
 */
bool queue_is_empty(Queue* q){
    if(!q) return NULL;
    return q->tail == -1;

}

/**
 * Obtiene el elemento al frente de la cola sin eliminarlo.
 * 
 * @param q Referencia a la cola de la cual se desea obtener el elemento.
 * @return El dato que está al frente de la cola. Si la cola está vacía , devuelve un valor que indica error (por ejemplo, un valor predeterminado).
 * @details Esta función devuelve el elemento al frente de la cola sin modificarla.
 *          Si la cola está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data queue_front(Queue* q){
    if (!queue_is_empty(q)){
    return -1;}
    else {
        if(q->tail<TAM-1)
            q->datos[q->tail];
            return;
    }
    return q->datos;
}

/**
 * Vacía la cola, eliminando todos sus elementos.
 * 
 * @param q Referemcoa a la cola que se desea vaciar.
 * @details Esta función hace que los índices head y tail tomen el valor de -1
 */
void queue_empty(Queue* q){
    if(es_vacia (*q)){
        printf("la cola esta vacia");
        return; 
    }else {
    for(int i=1; i<=q->tail; i++){
    q->datos[i-1] = q->datos[i]; //recorre el arreglo
    q->len--;
    return q->datos;
    printf("La cola esta vacia \n");
    }
}
}

void queue_print(Queue q){
    
    if(q.datos==NULL)
    printf("La cola està vacìa");
    
    for (int i=0; i < q.tail; i++)
    printf("\n Los datos de la cola son: %d \t \n", q.datos[i]);
    
}

