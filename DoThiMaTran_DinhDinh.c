#include "stdio.h"
//CTDL
#define Max_Vertices 20
typedef struct {
	int A[Max_Vertices][Max_Vertices];//ma tran
	int n;//vertices
}Graph;

//khoi tao graph
void init_Graph (Graph *G, int v) {
	G->n = v;
	int i, j;
	for(i = 1; i<G->n; i++) {
		for(j = 1; j<G->n; j++) {
			G->A[i][j] = 0;
		}
	}
}

//them edge
void add_edge(Graph *G, int x, int y) {
	G->A[x][y]=1;
}

//kiem tra xem 2 dinh co phai la neighbour kh
int adjacent(Graph *G, int x, int y) {
	return G->A[x][y] != 0;
}

//dem so cung
int degree(Graph *G, int dinh) {
	int i;
	int deg = 0;
	for(i=1; i<=G->n; i++) {
		if(G->A[i][dinh] == 1) {
			deg++;
		}
	}
	return deg;
}

//


int main() {
	Graph G;
	//init graph
	init_Graph(&G, 7);
//	G.A[2][3] = 1;
//	add edge
	add_edge(&G, 2, 3);
	add_edge(&G, 1, 6);
//	print graph
	for(i = 1; i<G.n; i++) {
		for(j = 1; j<G.n; j++) {
			printf("%d ", G.A[i][j]);
		}
		printf("\n");
	}
		
	return 0;
}
