#include <stdio.h>
#include <stdlib.h>

#define tam_hash 11

typedef struct Cell {
    int valor;
    struct Cell *proximo;
} Cell;

typedef struct List {
    Cell *primeiro;
    int qtd;
} List;

typedef struct Hash{
    List* tabela[tam_hash];
}Hash;

Cell* creat_cell(int valor){
    Cell* c = malloc(sizeof(Cell)); //aloca um espa�o de memoria do tipo celula
	c->proximo = NULL;
	c->valor = valor;
	return c;
}

List* start_list() {
    List* l = malloc(sizeof(List));
    l->qtd = 0;
    l->primeiro = NULL;
    return l;
}

Hash* start_hash() {
    // implementar
    Hash* h = malloc(sizeof(Hash));
    for (int i = 0; i < tam_hash; i++) {
        h->tabela[i] = start_list();
    }
    return h;
}

void inserir_hash(Hash* h, int valor) {
    // implementar
    Cell* new = creat_cell(valor);
    int pos = valor % tam_hash;
    if(h->tabela[pos]->qtd == 0){
        h->tabela[pos]->primeiro = new;
    }
    else{
        Cell* atual = h->tabela[pos]->primeiro;
        Cell* anterior = NULL;
        if (anterior == NULL) {
			new->proximo = h->tabela[pos]->primeiro;
			h->tabela[pos]->primeiro = new;
		}
		else {
			anterior->proximo = new;
			new->proximo = atual;
		}
    }
    h->tabela[pos]->qtd++;
    
}

void show_list(List* l) {
    Cell* atual = l->primeiro;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void imprimir(Hash* hash) {
    // implementar
    printf("---------------------\n");
    for (int i = 0; i < tam_hash; i++) {
        printf("%d -> ", i);
        show_list(hash->tabela[i]);
    }
    printf("---------------------\n");
}

int fibonacci(n) {
    int LEN = n + 1;
    int *tabela = malloc(LEN * sizeof(int));
    for(int i = 0; i <= n; i++) {
        tabela[i] = 0;
    }

    tabela[0] = 0;
    tabela[1] = 1;

    for(int i = 2; i <= n; i++) {
        tabela[i] = tabela[i-1] + tabela[i-2];
    }

    return tabela[n];
}



int main(void) {
    int n = 45;

    Hash* hash = start_hash();

    printf("Fibonacci de %d: %d\n", n, fibonacci(n));

    for(int i = 0; i <= n; i++) {
        inserir_hash(hash, fibonacci(i));
    }
    imprimir(hash);

    return 0;
}