#include <stdio.h>
#include <stdlib.h>

// #define MOD 1000000007

typedef struct vertice
{
    struct lista *adj;
    int visitado;
} vertice;

typedef struct lista
{
    struct registro *inicio;
    struct registro *final;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_vertice_lista_adjacencia(vertice *v, int valor);
int dfs(int raiz, vertice *vertices);
int processar_caso_teste(int qtd_funcionario, int qtd_arestas);

int main()
{
    int t, qtd_funcionario, qtd_arestas, i;

    scanf("%d", &t);

    for (i = 0; i < t; i++)
    {
        scanf("%d %d", &qtd_funcionario, &qtd_arestas);
        processar_caso_teste(qtd_funcionario, qtd_arestas);
    }

    return 0;
}

int processar_caso_teste(int qtd_funcionario, int qtd_arestas)
{
    int i, a, b, num_componentes = 0, maneiras = 1;
    vertice *vertices;

    vertices = (vertice *)calloc(qtd_funcionario + 1, sizeof(vertice));

    for (i = 0; i < qtd_arestas; i++)
    {
        scanf("%d %d", &a, &b);
        incluir_vertice_lista_adjacencia(&vertices[a], b);
        incluir_vertice_lista_adjacencia(&vertices[b], a);
    }

    for (i = 1; i <= qtd_funcionario; i++)
    {
        if (!vertices[i].visitado)
        {
            num_componentes++;
            int tamanho_componente = dfs(i, vertices);
            maneiras = (maneiras * tamanho_componente);
        }
    }

    printf("\nSaida: %d %d\n\n", num_componentes, maneiras);

    free(vertices);
    return 0;
}

int dfs(int raiz, vertice *vertices)
{
    int tamanho = 1;
    vertices[raiz].visitado = 1;

    registro *aux;
    if (vertices[raiz].adj != NULL)
    {
        aux = vertices[raiz].adj->inicio;

        while (aux != NULL)
        {
            if (!vertices[aux->valor].visitado)
            {
                tamanho += dfs(aux->valor, vertices);
            }
            aux = aux->prox;
        }
    }
    return tamanho;
}

void incluir_vertice_lista_adjacencia(vertice *v, int valor)
{
    if (v->adj == NULL)
    {
        v->adj = aloca_lista();
    }

    registro *novo = aloca_registro();
    novo->valor = valor;

    if (v->adj->inicio == NULL)
    {
        v->adj->inicio = novo;
        v->adj->final = novo;
    }
    else
    {
        v->adj->final->prox = novo;
        v->adj->final = novo;
    }
}

lista *aloca_lista()
{
    lista *novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro()
{
    registro *novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}