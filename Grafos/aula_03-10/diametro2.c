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
void resetar_visitados (vertice *vertice, int qtd_vertices);
void dfs (int raiz, vertice *vertices, int d, int *dMax, int *no);

int main() {
    int qtd_vertices;
    int i, a, b, d;
    int componente = 0;
    int dMax = 0, no = 1;

    vertice *vertices;

    scanf("%d", &qtd_vertices);

    vertices = (vertice *) calloc (sizeof(vertice), qtd_vertices + 1);

    for (i = 0; i < qtd_vertices-1; i++) {
        scanf("%d %d", &a, &b);
        incluir_vertice_lista_adj(&vertices[a], b);
        incluir_vertice_lista_adj(&vertices[b], a);
    }

    // printf("\n\nLista de adjacencia: \n");
    // for (i = 1; i <= qtd_vertices; i++)  {
    //     printf("Vertice: %d -> ", i);
    //     mostrar_lista(vertices[i].adj);
    //     printf("\n");
    // }

    dfs(1, vertices, 0, &dMax, &no);
    resetar_visitados(vertices, qtd_vertices);

    dMax = 0;

    dfs(no, vertices, 0, &dMax, &no);

    printf("\n\nDistancia maxima: %d\n", &dMax);

    return 0;
}

void dfs (int raiz, vertice *vertices, int d, int *dMax, int *no) {
    printf("%d ", raiz);
    vertices[raiz].visitado = 1;
    
    registro *aux;

    
    if (vertices[raiz].adj != NULL) {
        if (d > dMax) {
            *dMax = d;
            *no = raiz;
        }

        aux = vertices[raiz].adj -> inicio;

        while (aux != NULL) {
            if (vertices[aux -> valor].visitado == 0)
                dfs (aux -> valor, vertices, d+1, dMax, no);
        }
        aux = aux -> prox;
    }
}

void resetar_visitados (vertice *vertice, int qtd_vertices) {
    for (int i = 1; i <= qtd_vertices; i++){
        vertice[i].visitado = 0;
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