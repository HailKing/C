/*
Para conseguir acessar o tamanho da lista com complexidade O(1) basta colocar um atributo na struct list que vai ficar sendo atualizado de acordo com o aumento e o decremento da lista de acordo com o uso da lista e das funções.
*/

#include <stdlib.h>

struct node{
  int data;
  struct node *next;
};
typedef struct node node ;

typedef struct{
  node *begin;
  int size;
}list;

list *createList(){
  list *l, *aux = (list*)malloc(sizeof(list));
  if(aux == NULL) return NULL;
  l = aux;
  l -> begin = NULL;
  l -> size = 0;
  return l;
}

void printList(list *l){
  node *aux = l -> begin;
  while(aux != NULL){
    printf("%d -> ", aux -> data);
    aux = aux -> next;
  }
  printf("NULL\n");
}

void add(list *l, int v){
  node *n = (node*)malloc(sizeof(node));
  n -> data = v;
  n -> next = NULL;
  if (l -> begin == NULL){
    l -> begin = n;
    l -> size++;
  }
  else{
    node *aux = l -> begin;
    while(aux -> next != NULL){
      aux = aux -> next;
    }
    aux -> next = n;
    l -> size++;
  }
}

int isEmpty(list *l){
  return (l -> begin == NULL);
}

int size(list *l){
  return l -> size;
}

void removeBack(list *l){
  if(l -> begin != NULL){
    node *aux1 = NULL;
    node *aux2 = l -> begin;
    if(aux2 -> next == NULL){
      l -> begin = NULL;
      l -> size--;
    }
    else{
      while(aux2 -> next != NULL){
        aux1 = aux2;
        aux2 = aux2 -> next;
      }
      aux1 -> next = NULL;
      l -> size--;
      free(aux2);
    }
  }
}

int insertPosition(list *l, int v, int pos){
  if(pos < 0 || pos >= size(l)) return -1;
  node *aux1 = l -> begin;
  node *aux2 = NULL;
  node *n = (node*)malloc(sizeof(node));
  n -> data = v;
  if(size(l) > 0 && pos == 0){
    n -> next = aux1;
    l -> begin = n;
    l -> size++;
    return 0;
  }
  else{
    int cont_pos = 0;
    while(aux1 -> next != NULL){
      cont_pos++;
      aux2 = aux1;
      aux1 = aux1 -> next;
      if(cont_pos == pos){
        n -> next = aux1;
        aux2 -> next = n;
        l -> size++;
        return 0;
      }
    }
  }
  return -1;
}

int removePosition(list *l, int pos){
  if(pos < 0 || pos >= size(l)) return -1;
  node *aux1 = l -> begin;
  node *aux2 = NULL;
  if(pos == 0){
    l -> begin = aux1 -> next;
    l -> size--;
    free(aux1);
    return 0;
  }
  else{
    int cont_pos = 0;
    while(aux1 != NULL){
      cont_pos++;
      aux2 = aux1;
      aux1 = aux1 -> next;
      if(cont_pos == pos){
        aux2 -> next = aux1 -> next;
        free(aux1);
        l -> size--;
        return 0;
      }
    }
  }
  return -1;
}

int removeElement(list *l, int v){
  if(l -> begin != NULL){
    int cont_pos = 0;
    node *aux1 = l -> begin;
    node *aux2 = NULL;
    if(aux1 -> data == v){
      l -> begin = l -> begin -> next;
      l -> size--;
      return cont_pos;
    }
    else{
      while(aux1 -> next != NULL){
        cont_pos++;
        aux2 = aux1;
        aux1 = aux1 -> next;
        if(aux1 -> data == v){
          aux2 -> next = aux1 -> next;
          free(aux1);
          l -> size--;
          return cont_pos;
        }
      }
    }
  }
  return -1;
}

int get(list *l ,int pos, int *vret){
  if(pos >= 0 && pos < size(l)){
    if(l -> begin == NULL) return -1;
    int cont_pos = 0;
    node *aux = l -> begin;
    while(aux != NULL){
      if(pos == cont_pos){ 
        *vret = aux -> data;
        return 0;
      }
      aux = aux -> next;
      cont_pos++;
    }
  }
  return -1;
}

