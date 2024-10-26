#include <stdio.h>

#define V 8
#define E 20

int get_index(char x){
	return x - 114;
}

void inicia_arestas(int arestas[V][V]){
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			arestas[i][j] = 0;
		}
	}
}

void cria_arestas(int arestas[V][V], int v, int u){
	arestas[v][u] = 1;
}

void mostra_arestas(int arestas[V][V]){
    //implementar
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            printf("%d ", arestas[i][j]);
        }
        printf("\n");
    }
}

void mostra_adjacentes(int arestas[V][V], char v){
    //implementar
    int index = get_index(v);
    for(int i = 0; i < V; i++){
        if(arestas[index][i] == 1){
            printf("%c -> %c\n", v, i + 114); // i + 114 para converter o índice para o caractere correspondente
        }
    }
}

void mostra_distancias(int arestas[V][V], char v){
    //implementar
    int dist[] = {-1, -1, -1, -1, -1, -1, -1, -1};
    int index = get_index(v);
    dist[index] = 0;

    int Q[V];
    int head = 0;
    int tail = 0;

    Q[tail++] = index;

    while(head != tail){
        int u = Q[head++];
        for(int i = 0; i < V; i++){
            if(arestas[u][i] == 1 && dist[i] == -1){
                dist[i] = dist[u] + 1;
                Q[tail++] = i;
            }
        }
    }
    for(int i = 0; i < V; i++){
        printf("%d ", dist[i]);
    }
    printf("\n");

    
}

int main(void) {
	char lista_de_vertices[V] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};
	char lista_de_arestas[E][2] = {"vr", "rv", "rs", "sr", "sw", "ws", "wt", "tw", "wx", "xw", "tx", "xt", "tu", "ut", "xu", "ux", "xy", "yx", "uy", "yu"};
  	int arestas[V][V];
	inicia_arestas(arestas);
	printf("Matriz de adjacências\n");
	for(int i = 0; i < E; i++){
		cria_arestas(arestas, get_index(lista_de_arestas[i][0]), get_index(lista_de_arestas[i][1]));
	}
	mostra_arestas(arestas);
	printf("Lista de adjacências\n");
	for(int i = 0; i < V; i++){
		mostra_adjacentes(arestas, lista_de_vertices[i]);
	}
	printf("Matriz de distâncias\n");
	for(int i = 0; i < V; i++){
		mostra_distancias(arestas, lista_de_vertices[i]);
	}		
  return 0;
}