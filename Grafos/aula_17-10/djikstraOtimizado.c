#include <stdio.h>
#include <stdlib.h>
int i,j;
typedef struct vertice{
	int *adjacencia;
	int visitado;
}vertice;

void incluir_aresta(vertice *vertices,int a,int b,int qtd_vertices);
void dfs(int raiz,vertice *vertices,int qtd_vertices);
void mostrar_matriz(vertice *vertices,int qtd_vertices);
int main(){
	int qtd_vertices,qtd_aresta,a,b;
	vertice *vertices;
	
	printf("Adicione o numero de vertices e arestas no grafos\n");
	scanf("%d %d",&qtd_vertices,&qtd_aresta);
	vertices = (vertice *)calloc(qtd_vertices + 1,sizeof(vertice));
	for(i=1;i<=qtd_vertices;i++){
		vertices[i].adjacencia = (int *)calloc(qtd_vertices+1,sizeof(int));
	}
	printf("Adicione as aresta\n");
	for(i=1;i<=qtd_aresta;i++){
		scanf("%d %d",&a,&b);
		incluir_aresta(vertices,a, b,qtd_vertices);
	}
	dfs(1,vertices,qtd_vertices);
	mostrar_matriz(vertices,qtd_vertices);
	
	return 0;
}


void incluir_aresta(vertice *vertices,int a,int b,int qtd_vertices){
	vertices[a].adjacencia[b] = 1;
	vertices[b].adjacencia[a] = 1;//nao direcional(lembrar de tirar se for direcional)
}

void dfs(int raiz,vertice *vertices,int qtd_vertices){
	vertices[raiz].visitado = 1;
	for(i = 0;i<qtd_vertices;i++){
		if(vertices[raiz].adjacencia[i] == 1 && vertices[i].visitado == 0){
			dfs(i,vertices,qtd_vertices);
		}
	}
}

void mostrar_matriz(vertice *vertices,int qtd_vertices){
	int arr[qtd_vertices];
	for(i=1;i<=qtd_vertices;i++){
		printf("vertice atual: %d\n",i);
		int k = 0;
		for(j=1;j<=qtd_vertices;j++){
			if(vertices[i].adjacencia[j] == 1){
				arr[k++] =	j;
			}
		}
		int l;
		for(l=0;l<k;l++){
			printf("adjacencia: %d \n",arr[l]);
		}
	}
}