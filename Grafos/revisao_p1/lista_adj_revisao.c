#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    struct lista *adj;
    int visitado;
} vertice;

typedef struct lista {
    struct registro *inicio;
    struct registro *final;
} lista;

typedef struct registro {
    int valor;
    struct regitstro *prox;
} registro;

lista *aloca_lista ();
registro *aloca_registro ();

void mostrar_lista (lista *lista);
void incluir_final (lista *lista, int num);
void incluir_vertice_lista_adj (vertice *vertice, int valor);
void dfs (int raiz, vertice *vertices);

int main() {
    int qtd_vertices;
    int qtd_arestas;
    int i, a, b;
    int componente = 0;

    vertice *vertices;

    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    vertices = (vertice *) calloc (sizeof(vertice), qtd_vertices + 1);

    for (i = 0; i < qtd_arestas; i++) {
        scanf("%d %d", &a, &b);
        incluir_vertice_lista_adj(&vertices[a], b);
        incluir_vertice_lista_adj(&vertices[b], a);
    }

    printf("\nLista de adjacencia: \n");
    for (i = 1; i <= qtd_vertices; i++)  {
        printf("Vertice: %d -> ", i);
        mostrar_lista(vertices[i].adj);
        printf("\n");
    }

    for (i = 1; i <= qtd_vertices; i++) {
        if (vertices[i].visitado == 0) {
            dfs(i, vertices);
            componente += 1;
        }
    }

    printf("\n\n");
    printf("Componentes : %d \n", componente);

    printf("DFS : ");
    dfs(1, vertices);

    // if ((qtd_arestas == qtd_vertices - 1) && (componente == 1))
    //     printf("\nSim!\n");
    // else
    //     printf("\nNao!\n");
}

void dfs (int raiz, vertice *vertices) {
    printf("%d ", raiz);
    vertices[raiz].visitado = 1;
    
    registro *aux;

    if (vertices[raiz].adj != NULL) {
        aux = vertices[raiz].adj -> inicio;

        while (aux != NULL) {
            if (vertices[aux -> valor].visitado == 0)
                dfs (aux -> valor, vertices);

            aux = aux -> prox;
        }
    }
}

void incluir_vertice_lista_adj (vertice *vertice, int valor) {
    if (vertice -> adj == NULL)
        vertice -> adj = aloca_lista();

    registro *novo = aloca_registro();
    novo -> valor = valor;

    if (vertice -> adj -> inicio == NULL) {
        vertice -> adj -> inicio = novo;
        vertice -> adj -> final = novo;
    } else {
        vertice -> adj -> final -> prox = novo;
        vertice -> adj -> final = novo;
    }
}

lista *aloca_lista () {
    lista *novo = (lista *) calloc (sizeof(lista), 1);
    return novo;
}

registro *aloca_registro () {
    registro *novo = (registro *) calloc (sizeof(registro), 1);
    return novo;
}

void incluir_final (lista *lista, int num) {
    if (lista == NULL) {
        printf("\nLista nula");
        return;
    }

    registro *novo;

    novo = aloca_registro();
    novo -> valor = num;
    novo -> prox = NULL;

    if (lista -> inicio == NULL) {
        lista -> inicio = novo;
        lista -> final = novo;
    } else {
        lista -> final -> prox = novo;
        lista -> final = novo;
    }
}

void mostrar_lista (lista *lista) {
    registro *aux;

    if (lista == NULL) 
        return;
    if (lista -> inicio == NULL)
        return;
    
    aux = lista -> inicio;

    while (aux != NULL) {
        printf("%d ", aux -> valor);
        aux = aux -> prox;
    }
}