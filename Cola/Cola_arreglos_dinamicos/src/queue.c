#include "queue.h"
#include <stdlib.h>

/**
 * Crea una nueva cola vacía y la devuelve.
 * 
 * @param len cantidad de datos que se pueden guardar en el arreglo para la cola
 * @return Una nueva cola vacía. Si la creación falla, el estado de la cola es inválido.
 * @details Esta función inicializa una cola vacía. Asigna memoria dinàmica con malloc al arreglo data usando len
 */
Queue queue_create(int len){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL; //-1 es un indice no valido 
    q->tail = NULL;
    q->len=len;
    return *q;
}

/**
 * Inserta un elemento al final de la cola.
 * 
 * @param q Referencia a la cola donde se insertará el elemento.
 * @param d Dato que se insertará en la cola.
 * @details Esta función añade el dato `d` al final de la cola.
 */
void queue_enqueue(Queue* q, Data d){
    if (q != NULL && q->data != NULL && (q->tail - q->head + q->len + 1) % q->len < q->len - 1) {
        q->tail = (q->tail + 1) % q->len;
        q->data[q->tail] = d;
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
    if (q == NULL || q->data == NULL || queue_is_empty(q)) {
        return -1; // Valor de error
    }
    
    Data dato = q->data[q->head];
    q->head = (q->head + 1) % q->len;
    
    return dato;

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
    return q->tail == NULL;
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
    if (q == NULL || q->data == NULL || queue_is_empty(q)) {
        return -1; // Valor de error
    }
    
    return q->data[q->head];
}

/**
 * Vacía la cola, eliminando todos sus elementos.
 * 
 * @param q Referemcoa a la cola que se desea vaciar.
 * @details Esta función hace que los índices head y tail tomen el valor de -1
 */
void queue_empty(Queue* q){
    if (q != NULL) {
        q->head = 0;
        q->tail = -1;
    }
}

/**
 * Elimina la cola y libera la memoria asociada a ella.
 * 
 * @param q Referencia a la cola que se desea eliminar.
 * @details Esta función libera la memoria asignada dinámicamente para datos
 *          utilizando `free`. Es responsabilidad del llamante asegurarse de que la cola ya no se utiliza después
 *          de ser eliminada.
 */
void queue_delete(Queue* q){
    if (q != NULL && q->data != NULL) {
        free(q->data);
        q->data = NULL;
        q->head = 0;
        q->tail = -1;
    }
}