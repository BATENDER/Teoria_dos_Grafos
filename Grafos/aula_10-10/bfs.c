// BFS algorithm in C

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct fila {
  int items[SIZE];
  int inicio;
  int fim;
};

struct fila* criarFila();
void enfileirar(struct fila* q, int);
int desinfileirar(struct fila* q);
// void mostrar(struct fila* q);
int estaVazio(struct fila* q);
void mostrarFila(struct fila* q);

struct No {
  int vertex;
  struct no* prox;
};

struct No* criarNo(int);

struct Grafo {
  int numVertices;
  struct no** adj;
  int* visitado;
};

// BFS algorithm
void bfs(struct Grafo* grafo, int iniciarVertex) {
  struct fila* q = criarFila();

  grafo -> visitado[iniciarVertex] = 1;
  enfileirar(q, iniciarVertex);

  while (!estaVazio(q)) {
    mostrarFila(q);
    int atualVertex = desinfileirar(q);
    printf("Visitado %d\n", atualVertex);

    struct No* temp = grafo -> adj[atualVertex];

    while (temp) {
      int adjVertex = temp -> vertex;

      if (grafo -> visitado[adjVertex] == 0) {
        grafo -> visitado[adjVertex] = 1;
        enfileirar(q, adjVertex);
      }
      temp = temp -> prox;
    }
  }
}

// Creating a node
struct No* criarNo(int v) {
  struct No* novoNo = malloc(sizeof(struct No));
  novoNo -> vertex = v;
  novoNo -> prox = NULL;
  return novoNo;
}

// Creating a grafo
struct Grafo* criarGrafo(int vertices) {
  struct Grafo* grafo = malloc(sizeof(struct Grafo));
  grafo -> numVertices = vertices;

  grafo -> adj = malloc(vertices * sizeof(struct no*));
  grafo -> visitado = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    grafo -> adj[i] = NULL;
    grafo -> visitado[i] = 0;
  }

  return grafo;
}

// Add edge
void adicionarPonta(struct Grafo* grafo, int src, int dest) {
  // Add edge from src to dest
  struct No* novoNo = criarNo(dest);
  novoNo -> prox = grafo -> adj[src];
  grafo -> adj[src] = novoNo;

  // Add edge from dest to src
  novoNo = criarNo(src);
  novoNo -> prox = grafo->adj[dest];
  grafo->adj[dest] = novoNo;
}

// criar a fila
struct fila* criarFila() {
  struct fila* q = malloc(sizeof(struct fila));
  q -> inicio = -1;
  q -> fim = -1;
  return q;
}

// Check if the fila is empty
int estaVazio(struct fila* q) {
  if (q -> fim == -1)
    return 1;
  else
    return 0;
}

// Adding elements into fila
void enfileirar(struct fila* q, int valor) {
  if (q -> fim == SIZE - 1)
    printf("\nA fila está CHEIA!!");
  else {
    if (q -> inicio == -1)
      q -> inicio = 0;
    q -> fim++;
    q -> items[q->fim] = valor;
  }
}

// Removing elements from fila
int desinfileirar(struct fila* q) {
  int item;
  if (estaVazio(q)) {
    printf("fila está VAZIO");
    item = -1;
  } else {
    item = q -> items[q -> inicio];
    q -> inicio++;
    if (q -> inicio > q -> fim) {
      printf("Resentando a fila ");
      q -> inicio = q -> fim = -1;
    }
  }
  return item;
}

// Print the fila
void mostrarFila(struct fila* q) {
  int i = q->inicio;

  if (estaVazio(q)) {
    printf("Fila esta VAZIO");
  } else {
    printf("\nFila contem \n");
    for (i = q -> inicio; i < q -> fim + 1; i++) {
      printf("%d ", q -> items[i]);
    }
  }
}

int main() {
  struct grafo* grafo = criarGrafo(6);
  adicionarPonta(grafo, 0, 1);
  adicionarPonta(grafo, 0, 2);
  adicionarPonta(grafo, 1, 2);
  adicionarPonta(grafo, 1, 4);
  adicionarPonta(grafo, 1, 3);
  adicionarPonta(grafo, 2, 4);
  adicionarPonta(grafo, 3, 4);

  bfs(grafo, 0);

  return 0;
}