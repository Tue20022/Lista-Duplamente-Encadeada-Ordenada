#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale>
using namespace std;
struct lista 
{
	int info;
	struct lista* prox;
	struct lista* ant;
};
typedef struct lista Lista;

Lista* inicializa();
bool vazia(Lista* l);
int Tamanho_lista (Lista* l);
Lista* insere_ordenado(Lista* l, int i);
Lista* swap(Lista* b, Lista* c);
Lista* BubbleSort(Lista* l);
Lista* remove_inicio(Lista* l);
Lista* remove_fim(Lista* l);
void imprime(Lista* l);
void imprime_reverso(Lista* l);
Lista* remove_valor(Lista* l, int v);
Lista* busca (Lista* l, int v);
void busca_dado (Lista* l, int v);
