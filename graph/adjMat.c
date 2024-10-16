#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
typedef struct Graph {
    int numVertices;  // Number of vertices
    int** adjMatrix;  // Adjacency matrix to represent edges
} Graph;

Graph* createGraph(int vertices){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices=vertices;
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));

    for(int i= 0; i<vertices; i++){
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for(int j=0; j<vertices; j++){
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}
void addEdge(Graph* graph, int src, int dest){
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}
void printGraph(Graph* graph){
    for(int i=0; i<graph->numVertices; i++){
        for(int j=0; j<graph->numVertices; j++){
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int vertices = 6;
    Graph* graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);


    for (int i = 0; i < vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

}
