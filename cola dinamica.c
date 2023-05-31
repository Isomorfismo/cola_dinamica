#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int dato;
    struct nodo *sig;
}nodo;

typedef struct Queue{
    nodo *head;
    nodo *tail;
}queue;


void crear(queue *qu);
int estaVacia(queue qu);
void enqueue(queue *qu, int dato);
int dequeue(queue *qu);
void mostrar(queue *qu);
void vaciar(queue *qu);

int main(){
    queue qu;
    crear(&qu);
    int dato, opcion;
    do{
        printf("1. Insertar\n");
        printf("2. Extraer\n");
        printf("3. Mostrar\n");
        printf("4. Vaciar\n");
        printf("5. Salir\n");
        printf("opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("Dato: ");
                scanf("%d", &dato);
                enqueue(&qu, dato);
                break;
            case 2:
                dato = dequeue(&qu);
                printf("Dato extraido: %d\n", dato);
                break;
            case 3:
                mostrar(&qu);
                break;
            case 4:
                vaciar(&qu);
                break;
            case 5:
                printf("Adios\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    }while(opcion!=5);
    return 0;
}

void crear(queue *qu){
    qu->head = NULL;
    qu->tail = NULL;
}
int estaVacia(queue qu){
    return qu.tail == NULL && qu.head == NULL ? 1 : 0;
}
void enqueue(queue *qu, int dato){
    nodo *sig;
    sig = (nodo*)malloc(sizeof(nodo));
    if(estaVacia(*qu)){
        qu->head = sig;
        qu->head->dato = dato;
        qu->head->sig = NULL;
        qu->tail = sig;
    }else{
        qu->tail->sig = sig;
        qu->tail = sig;
        qu->tail->sig = NULL;
        qu->tail->dato = dato;
    }
}
int dequeue(queue *qu){
    int copiaDato;
    if(estaVacia(*qu)){
        printf("Pila vacia\n");
        return -1;
    }else{
        nodo *aux;
        if(qu->tail == qu->head) qu->tail = NULL;
        copiaDato = qu->head->dato;
        aux = qu->head;
        qu->head = aux->sig;
        free(aux);
        return copiaDato;
    }
}
void mostrar(queue *qu){
    if(estaVacia(*qu)){
        printf("Pila vacia\n");
        return;
    }
    nodo *aux = qu->head;
    while(aux != NULL){
        printf("%d\n", aux->dato);
        aux = aux->sig;
    }
}
void vaciar(queue *qu){
    while(!estaVacia(*qu)){
        dequeue(qu);
    }
}