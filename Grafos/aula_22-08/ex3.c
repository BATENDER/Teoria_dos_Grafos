#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vertice {
    struct lista *adj;
    int visitado;
    int genero;
} vertice;

typedef struct lista {
    struct registro *inicio;
    struct registro *final;
} lista;

typedef struct registro {
    int valor;
    struct registro *prox;
} registro;

lista *aloca_lista();
registro *aloca_registro();

void mostrar_lista(lista *l);
void incluir_final(lista *l, int x);
void incluir_vertice_lista_adjacencia(vertice *v, int valor);
void dfs(int raiz , vertice * vertices);

int check_genero(vertice *vevrtices, int qtd_vertices);

int main() {

    int qtd_cenarios, qtd_vertices, qtd_arestas, i, a, b, componentes = 0;
    
    scanf("%d", &qtd_cenarios);

    for (i = 1; i <= qtd_cenarios; i++) {
        scanf("%d %d", &qtd_vertices, &qtd_arestas);

        vertice *vertices = (vertice *)calloc(sizeof(vertice), qtd_vertices + 1);

        for (int j = 0; j < qtd_arestas; j++) {
            scanf("%d %d", &a, &b);

            incluir_vertice_lista_adjacencia(&vertices[a], b);
            incluir_vertice_lista_adjacencia(&vertices[b], a);
        }

        int sus = check_genero(vertices, qtd_vertices);

        printf("\n\nCenario #%d : \n", i);
        if (sus % 2 == 0)
            printf("Inseto suspeito detectado!\n");
        else
            printf("Nenhum inseto suspeito detectado!\n");
    }

    return 0;
}

void dfs(int raiz , vertice * vertices) {
    printf("%d ",raiz);
    vertices[raiz].visitado = 1;

    registro * aux;
    if (vertices[raiz].adj != NULL) {
        aux = vertices[raiz].adj->inicio;

        while(aux != NULL) {
            if (vertices[aux->valor].visitado == 0) {
                dfs(aux->valor,vertices);
            }
            aux = aux->prox;
        }
    }
}

int check_genero(vertice *vertices, int qtd_vertices) {
    for (int i = 1; i <= qtd_vertices; i++) {
        if (vertices[i].visitado == 0) {
            vertices[i].genero = 0;
            dfs(i, vertices);
        }
    }
}

void incluir_vertice_lista_adjacencia(vertice *v, int valor) {
    if (v->adj == NULL) {
        v->adj = aloca_lista();
    }

    registro *novo = aloca_registro();
    novo->valor = valor;

    if (v->adj->inicio == NULL) {
        v->adj->inicio = novo;
        v->adj->final = novo;
    }
    else {
        v->adj->final->prox = novo;
        v->adj->final = novo;
    }
}

lista *aloca_lista() {
    lista *novo = (lista *)calloc(sizeof(lista), 1);
    return novo;
}

registro *aloca_registro() {
    registro *novo = (registro *)calloc(sizeof(registro), 1);
    return novo;
}

void incluir_final(lista *l, int x) {
    if (l == NULL) {
        printf("\n Lista Nula");
        return;
    }

    registro *novo;

    novo = aloca_registro();
    novo->valor = x;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
        l->final = novo;
    }
    else {
        l->final->prox = novo;
        l->final = novo;
    }
}

void mostrar_lista(lista *l) {

    registro *aux;
    if (l == NULL) {
        return ;
    }

    if (l->inicio == NULL) {
        return ;
    }

    aux = l->inicio;

    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}