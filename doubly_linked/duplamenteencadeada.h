#include <stdlib.h>

struct node{
  int data;
  struct node *next;
  struct node *bef;
};
typedef struct node node;

typedef struct{
  node *begin;
  node *end;
} list;

list *create_liked_list(){
  list *l, *a = (list*)malloc(sizeof(list));
  if(a == NULL) return NULL;
  l = a;
  l -> begin = NULL;
  l -> end = NULL;
  return l;
}

void print_linked_list(list *l){
  node *aux = l -> begin;
  while(aux != NULL){
    printf("%d -> ", aux -> data);
    aux = aux -> next;
  }
  printf("NULL\n");
}

void add_beginning(list *l, int v){
  node *n = (node*)malloc(sizeof(node));
  n -> data = v;
  n -> bef = NULL;
  if(l -> begin == NULL){
    n -> next = l -> begin;
    l -> begin = n;
    l -> end = n;
  }
  else{
    n -> next = l -> begin;
    n -> next -> bef = n;
    l -> begin = n; 
  }
}

void add_ending(list *l, int v){
  if(l -> begin == NULL) add_beginning(l, v);
  else{
    node *n = (node*)malloc(sizeof(node));
    n -> data = v;
    n -> next = NULL;
    n -> bef = l -> end;
    l -> end -> next = n;
    l -> end = n;
  }
}

int search_value(list *l, int v){
  if(l -> begin == NULL) return -1;
  int cont_pos = 0;
  node *aux = l -> begin;
  while(aux != NULL){
    if(aux -> data == v) return cont_pos;
    cont_pos++;
    aux = aux -> next;
  }
  return -1;
}

int remove_value(list *l, int v){
  if(l -> begin != NULL){
    node *aux = l -> begin;
    int removed;
    if(aux -> next == NULL){
      if(aux -> data == v){
        removed = aux -> data;
        l -> begin = NULL;
        l -> end = NULL;
        free(aux);
        return removed;
      }
    }
    else{
      if(aux -> data == v){
        removed = aux -> data;
        aux -> next -> bef = NULL;
        l -> begin = aux -> next;
        free(aux);
        return removed;
      }
      else{
        while(aux -> next != NULL){
          aux = aux -> next;
          if(aux -> data == v && aux != l -> end){
            removed = aux -> data;
            if(aux -> next != NULL) aux -> next -> bef = NULL;
            aux -> bef -> next = aux -> next;
            free(aux);
            return removed;
          }
          else{
            if(aux -> data == v && aux == l -> end){
              removed = aux -> data;
              aux -> bef -> next = NULL;
              l -> end = aux -> bef;
              free(aux);
              return removed;
            }
          }
        }
      }
    }
  }
  return -1;
}

void becomeCircular(list *l){
  if(l -> begin != NULL){
    if(l -> begin -> next == NULL){
      l -> begin -> next = l -> begin -> bef = l -> begin;
    }
    else{
      l -> begin -> bef = l -> end;
      l -> end -> next = l -> begin;
    }
  }
}

void printCircular(list *l){
  if(l -> begin != NULL){
    printf("-> ");
    if(l -> begin -> next == l -> begin){
      printf("%d -> ", l -> begin -> data);
    }
    else{
      printf("%d -> ", l -> begin -> data);
      node *aux1 = l -> begin;
      node *aux2 = l -> begin -> next;
      while(aux2 != aux1){
        printf("%d -> ", aux2 -> data);
        aux2 = aux2 -> next;
      }
    }
  }
  else{
    printf("NULL");
  }
  printf("\n");
}

void insertCircular(list *l, int v){
  node *n = (node*)malloc(sizeof(node));
  n -> data = v;
  n -> next = n;
  n -> bef = n;
  if(l -> begin != NULL){
    n -> next = l -> end -> next;
    l -> end -> next = n;
    n -> bef = l -> end;
    l -> end = n;
  }
}

node *find(list *l, int v){
  if(l -> begin == NULL) return NULL;
  else{
    node *aux = l -> begin;
    if(aux -> data == v) return aux;
    else{
      while(aux -> next != l -> begin){
        aux = aux -> next;
        if(aux -> data == v) return aux;
      }
    }
  }
  return NULL;
}

void removeElementCircular(list *l, int v){
  node *aux = find(l, v);
  if (aux != NULL){
    if(l -> begin == l -> end){
      l -> begin = l -> end = NULL;
    }
    else{
      if(aux == l -> begin){
        l -> begin = aux -> next;
        aux -> next -> bef = l -> end;
        l -> end -> next = l -> begin;
      }
      else{
        if(aux == l -> end){
          aux -> bef -> next = aux -> next;
          l -> end = aux -> bef;
          l -> begin -> bef = l -> end;
        }
        else{
          aux -> bef -> next = aux -> next;
          aux -> next -> bef = aux -> bef;
        }
      }
    }
    free(aux);
  }
}
