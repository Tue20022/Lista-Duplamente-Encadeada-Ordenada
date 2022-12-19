#include "proj_dp_ordenada.h"

Lista* inicializa()
{
	return NULL; 
}

bool vazia(Lista* l)
{
	return l==NULL;
}

int Tamanho_lista (Lista* l)
{ 
	Lista* p=l;
	int cont=0;
	while(p!=NULL){
		cont++;
		p=p->prox;
	}
	return cont; 
}

Lista* insere_ordenado(Lista* l, int i)
{
	Lista* novo= (Lista*) malloc(sizeof(Lista));
	novo->info=i;
	novo->prox = l;
	novo->ant = NULL;
	
	if (l!=NULL)
	{
		l->ant = novo;
	}
	novo = BubbleSort(novo);
	return novo;
}

Lista* swap(Lista* b, Lista* c)
{ 
	int tmp = b->info;
	b->info = c->info;
	c->info = tmp;
	return b;	
}

Lista* BubbleSort(Lista* l)
{
	int qtd=Tamanho_lista(l); 
	Lista* a; Lista* b; Lista* c;
	
	if (qtd>1){ 
		for(int i=0; i<qtd; i++){ //
			
			a=l; 
			b=l; 
			c=l->prox; 
			int flag=0; 
			
			while(c!=NULL){ 
				if(b->info > c->info){
					b = swap(b,c);			
				}
				if (flag==0){ 
					l = b; 
					flag=1;	
				}				
				else a->prox = b; 
			
				a=b;
				b=b->prox;
				c=b->prox;	
			}
		}	
	}
	return l; 
}

Lista* remove_inicio(Lista* l)
{
	Lista* p = l;
	
	if(vazia(l))
	{
		cout<<"Lista Vazia"<<endl;
		return l;
	}
	
	if(p->prox==NULL)
	{
		free(p);
		return NULL;
	}
	
	l = p->prox;
	l->ant = NULL;
	free(p);
	return l;
}

Lista* remove_fim(Lista* l)
{
	Lista* p = l;
	
	if(vazia(l))
	{
		cout<<"Lista vazia"<<endl;
		return l;
	}
	
	if(p->prox==NULL)
	{
		free(p);
		return l;
	}
	
	for(; p->prox!=NULL; p=p->prox);
	p->ant->prox = NULL;
	free(p);
	return l;
}

void imprime(Lista* l)
{
	if (!vazia(l)){
		cout << "Info: ";
		for(Lista* p=l; p!=NULL; p=p->prox){
			cout << p->info << " - ";
		}
		cout << endl;
	} else cout << "Lista vazia!" << endl;	
}

void imprime_reverso(Lista* l)
{
	Lista* p = l; 
	if(!vazia(l))
	{
		cout<<"Info: ";
		for(; p->prox!=NULL; p=p->prox);
		for(; p!=NULL; p=p->ant)
			cout<<p->info<<" - ";
		cout<<endl;
	}else cout<< "Lista vazia!"<<endl;
}

Lista* busca (Lista* l, int v)
{
    if (!vazia(l)){
         for (Lista* p=l; p!=NULL; p=p->prox)
             if (p->info == v)
                 return p;
    }
    return NULL;
}

Lista* remove_valor(Lista* l, int v)
{

    Lista* p = busca(l,v);

    if (p == NULL)
        return l; 

    if (l == p) 
        l = p->prox;
    else 
        p->ant->prox = p->prox;

    if (p->prox != NULL)
        p->prox->ant = p->ant;
    free(p);

    return l;
}

void busca_dado (Lista* l, int v)
{
    if (busca(l, v) != NULL) 
        cout << "Elemento " << v << " encontrado!\n";
    else 
        cout << "Elemento " << v << " nao encontrado!\n";
}
