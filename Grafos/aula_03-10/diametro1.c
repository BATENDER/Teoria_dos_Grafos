#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NOS 10000 

typedef struct {
    int *dados;  
    int tamanho; 
} Lista;         

void inicializaLista(Lista *lista) { 
    lista->dados = (int *)malloc(MAX_NOS * sizeof(int));
    lista->tamanho = 0;
}

void adicionaNaLista(Lista *lista, int valor) {  
    lista->dados[lista->tamanho++] = valor;
}

typedef struct {
    Lista *adjacentes;  
    bool *visitado;    
} Grafo;               

void inicializaGrafo(Grafo *grafo, int n) {  
    grafo->adjacentes = (Lista *)malloc((n + 1) * sizeof(Lista));
    grafo->visitado = (bool *)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++) {
        inicializaLista(&grafo->adjacentes[i]);
        grafo->visitado[i] = false;
    }
}

void dfs(int no, Grafo *grafo, int dist, int *dist_max, int *no_mais_distante) {
    grafo->visitado[no] = true;
    if (dist > *dist_max) {
        *dist_max = dist;               
        *no_mais_distante = no;         
    }
    for (int i = 0; i < grafo->adjacentes[no].tamanho; i++) {
        int vizinho = grafo->adjacentes[no].dados[i];  
        if (!grafo->visitado[vizinho]) {
            dfs(vizinho, grafo, dist + 1, dist_max, no_mais_distante);
        }
    }
}

int encontraMaiorCaminho(int n, int arestas[][2]) { 
    Grafo grafo;
    inicializaGrafo(&grafo, n);

    for (int i = 0; i < n - 1; i++) {
        int u = arestas[i][0];
        int v = arestas[i][1];
        adicionaNaLista(&grafo.adjacentes[u], v);
        adicionaNaLista(&grafo.adjacentes[v], u);
    }

    int dist_max = 0, no_mais_distante = 0;
    dfs(1, &grafo, 0, &dist_max, &no_mais_distante);

    for (int i = 0; i <= n; i++) {
        grafo.visitado[i] = false;
    }

    dist_max = 0;
    dfs(no_mais_distante, &grafo, 0, &dist_max, &no_mais_distante);

    free(grafo.adjacentes);
    free(grafo.visitado);

    return dist_max;
}

int main() {
    int n;
    scanf("%d", &n);
    int arestas[MAX_NOS][2];  
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &arestas[i][0], &arestas[i][1]);
    }

    printf("\nMaior distancia: %d\n", encontraMaiorCaminho(n, arestas));
    return 0;
}