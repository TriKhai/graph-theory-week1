#include "stdio.h"

//to chuc luu tru
#define Max_vertices 20
#define Max_lenght 20

//Graph
typedef struct {
	int A[Max_vertices][Max_vertices];//matran
	int n;//so dinh
}Graph;

//List
typedef struct {
	int data[Max_lenght];
	int size;
}List;

void make_null(List *list) {
	list->size = 0;
}
void push_back(List *list, int x) {
	list->data[list->size] = x;
	list->size++;
}
int element_at(List *list, int i) {
	return list->data[i-1];
}

//khoi tao do thi
void init_Graph(Graph *G, int x) {
	int i, j;
	G->n = x;
	for(i = 1; i<=G->n; i++) {
		for(j=1; j<=G->n; j++) {
			G->A[i][j] = 0;
		}
	}
}

//them cung
void add_edge(Graph *G, int x, int y) {
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}

//check lan can
int adjacent(Graph *G, int x, int y) {
	return G->A[x][y] != 0;
}

//tinh bac
int degree(Graph *G, int x) {
	int i, deg = 0;
	for(i=1; i<=G->n; i++) {
		if(G->A[i][x] == 1)
			deg++;
	}
	return deg;
}

//tim lang gieng
List neightbors(Graph *G, int x) {
	int i;
	List list;
	make_null(&list);
	for(i=1 ;i<=G->n; i++) {
		if(G->A[i][x] == 1) {
			push_back(&list, i);
		}
	}
	return list;		
}

int main() {
	Graph G;
//	DOC FILE
//	FILE* file = fopen("dothi.txt", "r");
	freopen("dothi.txt", "r", stdin);
	int n, m;//n = dinh, m = cung
//	fscanf(file, "%d%d", &n, &m);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int u, v, i, j;
	for(i=1; i<=m; i++) {
//		fscanf(file, "%d%d", &u, &v);
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
//	fclose(file);
	
	//print graph
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++) {
			printf("%d ", G.A[i][j]);
		}
		printf("\n");	
	}
	
	//print degree
	for(i=1; i<=n; i++) {
		printf("\ndeg(%d) = %d", i, degree(&G, i));
	}
	
	//print neightbors
	printf("\n\n");
	for(i=1; i<=G.n; i++) {
		List L = neightbors(&G, i);
		printf("Neightbors(%d) = [ ",i); 
		for(j=1; j<=L.size; j++) {
			printf("%d ", element_at(&L, j));
		}
		printf("]\n");
	}

	return 0;
}
