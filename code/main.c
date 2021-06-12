#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    int data;
    struct nodo *next;
    struct nodo *prev;
} NODO;


NODO *CrearNodo(int dato);
int InsertarInicio(NODO **head, int dato);
int InsertarDesp(NODO **head, int dat, int a);
int InsertarFinal(NODO **head, int dato);
void ImprimirLista(NODO *head);
void EliminarNodoSig(NODO **head, int dat);
void EliminarNodoAnt(NODO **head, int dat);
void EliminarInicio(NODO **head);
void EliminarFinal(NODO **head);
void EliminarLista(NODO **head);

int main()
{
    NODO *head = NULL;

    InsertarInicio(&head, 1);
    InsertarInicio(&head, 2);
    InsertarInicio(&head, 9);
    InsertarFinal(&head,6);
    InsertarFinal(&head,5);
    InsertarFinal(&head,4);
    ImprimirLista(head);
    printf("\n");
    InsertarDesp(&head,5,3);
    //EliminarNodoAnt(&head,5);
    //EliminarNodoSig(&head,5);
    //EliminarLista(&head);
    ImprimirLista(head);
    printf("\n");

    return 0;
}

NODO *CrearNodo(int dato)
{
    NODO* nuevo = NULL;

    nuevo = (NODO*)malloc(sizeof(NODO));
    if( nuevo != NULL)
    {
        nuevo->dato = dato;
        nuevo->next = NULL;
        nuevo->prev = NULL;
    }
    return nuevo;
}

void ImprimirLista(NODO *head)
{
    NODO *nAux = head;
    
    while(nAux != NULL)
    {
        printf("%d ", nAux->dato);
        nAux = nAux->next;
    }
    
}

int InsertarInicio(NODO **head, int dato)
{
    NODO *nuevo = NULL;

    nuevo = CrearNodo(dato);
    if (nuevo != NULL)
    {
        nuevo->next = *head;
        nuevo->prev = NULL;
        if( *head != NULL)
            (*head)->prev = nuevo;
        *head = nuevo;
        return 1;
    }
    return 0;
}

void EliminarLista(NODO **head){
    NODO *current ;
    
    while (*head != NULL)
    {
        current = *head;
        *head = (*head)->next;
        free(current);
    }
    printf("La lista esta vacia");
    
}

void EliminarInicio(NODO **head){
    NODO *current ;
    current = *head;
    *head = (*head)->next;
    free(current);
}

int InsertarFinal(NODO **head, int dato)
{
    NODO *nuevo = NULL, *nAux = *head;

    nuevo = CrearNodo(dato);
    if (nuevo != NULL)
    {
        while(nAux->next != NULL){ nAux = nAux->next;}
        nuevo->prev = nAux;
        nAux->next = nuevo;
        return 1;
    }
    return 0;
}

void EliminarFinal(NODO **head){
    if (head != NULL)
    {
        NODO *current ;
        current = *head;
        if (current->next != NULL)
        {
            while((current->next)!= NULL)
            {
                current = current->next;
            }
            free(current->next);
            current->next =NULL;
        }else{
            head =NULL;
        }
        
    }
}
    
    
void EliminarNodoSig(NODO **head, int dat)
{
    NODO *current = *head, *aux;
 
    if (head!=NULL ) 
    {
      
      if (current->dato==dat)
      {
          aux=current->next;
          current->next = (current->next)->next;
          free(aux);

      }else
        {
            while((current->next)->dato!=dat){
                current = current->next;
            }
            aux=current->next;
            current->next = (current->next)->next;
            free(aux);
        }   
    }
    
     
}

int InsertarDesp(NODO **head, int dat, int a)
{
    NODO *current = *head, *new = NULL;
 
    if (head!=NULL ) 
    {
        new = CrearNodo(a);
        while(current->dato != dat)
        {
            current= current->next;
        }
        new->prev= current;
        current->next=new;
        
    }
    return 0;
  
}

void EliminarNodoAnt(NODO **head, int dat)
{
    NODO *current = *head, *aux;
 
    if (head!=NULL ) 
    {    
      if (current->dato==dat)
      {
          printf("No hay nodo anterior\n");

      }else
        {
            while(current->next!= NULL && (current->next)->dato!=dat){
                current = current->next;
            }
            free(current);
            current->next= (current->prev)->prev;
            
        }   
    }
    
     
}
