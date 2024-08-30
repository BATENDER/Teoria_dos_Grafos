#include <stdio.h>
#include <stdlib.h>

typedef struct registro {
    int valor;
    struct registro *prox;
} registro;

typedef struct lista {
    registro *inicio;
    registro *final;
} lista;

typedef struct vertice {
    lista *adj;
    int visitado;
} vertice;

lista *aloca_lista();
registro *aloca_registro();
void mostrar_lista(lista *l);
void incluir_final(lista *l, int x);
void incluir_vertice_lista_adjacencia(vertice *v, int valor);
int dfs(int raiz, vertice *vertices, int *ant);

int main() {
    int qtd_vertices, qtd_arestas, i, a, b;
    
    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    vertice *vertices = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));
    int *ant = (int *)calloc(qtd_vertices + 1, sizeof(int));

    for (i = 0; i < qtd_arestas; i++) {   
        scanf("%d %d", &a, &b);
        incluir_vertice_lista_adjacencia(&vertices[a], b);
        incluir_vertice_lista_adjacencia(&vertices[b], a);
    }

    printf("\nLista de Adjacencia:\n");
    for (i = 1; i <= qtd_vertices; i++) {
        printf("- Vertice %d -> ", i);
        mostrar_lista(vertices[i].adj);
        printf("\n");
    }

    printf("\n");

    printf("DFS: ");
    for (i = 1; i <= qtd_vertices; i++) {
        if (vertices[i].visitado == 0) {
            if (dfs(i, vertices, ant)) {
                free(vertices);
                free(ant);

                printf("\nCiclo detectado!\n");
                return 1;
            }
            else {
                printf("\nNenhum ciclo detectado!\n");
            }
        }
    }

    free(vertices);
    free(ant);
    
    return 0;
}

int dfs(int raiz, vertice *vertices, int *ant) {
    printf("%d ", raiz);
    vertices[raiz].visitado = 1;
    ant[raiz] = 1;

    registro *aux;
    if (vertices[raiz].adj != NULL) {
        aux = vertices[raiz].adj->inicio;

        while (aux != NULL) {
            if (vertices[aux->valor].visitado == 0) {
                ant[aux->valor] = raiz; 
                if (dfs(aux->valor, vertices, ant)) {
                    return 1; 
                }
            } else if (ant[aux->valor] == raiz) { 
                             return 1; 
            }
            aux = aux->prox;
        }
    }
    return 0; 
}

void incluir_vertice_lista_adjacencia(vertice *v, int valor) {
    if (v->adj == NULL) {
        v->adj = aloca_lista();
    }

    incluir_final(v->adj, valor);
}

lista *aloca_lista() {
    lista *novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro() {
    registro *novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void incluir_final(lista *l, int x) {
    if (l == NULL) {
        printf("\nLista Nula");
        return;
    }

    registro *novo = aloca_registro();
    novo->valor = x;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
        l->final = novo;
    } else {
        l->final->prox = novo;
        l->final = novo;
    }
}

void mostrar_lista(lista *l) {
    if (l == NULL || l->inicio == NULL) {
        return;
    }

    registro *aux = l->inicio;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}