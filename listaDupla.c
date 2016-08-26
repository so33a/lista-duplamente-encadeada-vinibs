#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"




link novoNo (int item, link prev, link next) {
  link aux = malloc(sizeof(struct node));
  if (aux == NULL) {
    printf ("Erro ao alocar um novo no\n");
    exit(-1);
  }
  aux->item = item;
  aux->prev = prev;
  aux->next = next;
  return aux;
}


ListaDupla inicializa() {
  ListaDupla aux;
  aux = malloc(sizeof *aux);
  aux->head = NULL;
  aux->z = novoNo(0, NULL, NULL);
  return aux;
}

void insereDepois (ListaDupla l, link x, link t) {
  if (x == NULL) {
    l->head = t;
    t->next = l->z;
    t->prev = l->z;
    l->z->prev = t;
    l->z->next = t; 
  } else {
    t->next = x->next;
    t->prev = x;
    x->next = t;
    t->next->prev = t;
  }
}

link removeNo (link x) {
  x->prev->next = x->next;
  x->next->prev = x->prev;
  return x;
}
void imprimeReverso(ListaDupla l) {
  link t = l->z->prev;
  while ( t != l->z ) {
    printf ("%d ", t->item);
    t = t->prev;
  }
  printf("\n");
}


void imprime(ListaDupla l) {
  link t = l->head;
  while ( t != l->z ) {
    printf ("%d ", t->item);
    t = t->next;
  }
  printf("\n");
}

link buscar(ListaDupla l, int item) {
  link t = l->head;
  while ( t != l->z ) {
    if(t->item == item)
      return t;
    t = t->next;
  }
  return NULL;
}
/* 
void insereAntes (ListaDupla l, link x, link t);
*/

void destroiLista(ListaDupla l) {
  link t = l->head;
  while (t != l->z) {
    l->head = t->next;
    l->z->next = t->next;
    l->head->prev = l->z;
    free(t); 
    t = l->head;
  } 
  free(t);
  free(l);
}

/**********************************************/
link encontraMenor(ListaDupla l) {
  link t = l->head;
  link lmenor;
  int menor = 999999;

  while (t != l->z) {
    if(t->item < menor) {
      menor = t->item;
      lmenor = t;
    }
    t = t->next;
  }
  return lmenor;
}

void ordenaLista(ListaDupla l){
  link t = l->head;
  ListaDupla l2;

  while(t != l-z){
    link menor = encontraMenor(l);

    // Remove o menor valor da lista original
    link aux = menor->prev->next;
    menor->prev->next = menor->next->prev;
    menor->next->prev = aux;

    // Adiciona o menor valor como último elemento da lista extra
    if(l2->head == 0){
      l2->head = menor;
      l2->z = menor;      
      menor->prev = l2;
    } else{
      link x = l2->z;
      t = menor;

      x->next = t;
      t->prev = x;
      l2->z = t;
    }
  }

  // Redefine a lista original com os valores da lista extra
  l->head = l2->head;
  l->z = l2->z;
}
