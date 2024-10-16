#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int vertex;
    struct Node* next;
} Node;

typedef struct GraphList{
    int vertices;
    struct Node** adjList;
} GraphList;

GraphList* createGraphList(int vertices){
    GraphList *graph = (GraphList*)malloc(sizeof(GraphList));
    graph->vertices = vertices;
    graph->adjList = (Node**)malloc(sizeof(Node*) * vertices);
    for(int i=0; i<vertices; i++){
        graph->adjList[i] = NULL;
    }
    return graph;
}
void printGraphList(GraphList* graph){
    for(int i=0; i<graph->vertices; i++){
        Node* temp = graph->adjList[i];
        printf("Vertex %d : ", i);
        while(temp){
            printf("%d -> ", temp->vertex);
            temp= temp->next;
        }
        printf("\n");
    }
}
void addEdgeList(GraphList* graph, int src, int dest){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Driver code
int main() {
    int vertices = 5;  // Example with 5 vertices
    struct GraphList* graph = createGraphList(vertices);

    addEdgeList(graph, 0, 1);
    addEdgeList(graph, 0, 4);
    addEdgeList(graph, 1, 2);
    addEdgeList(graph, 1, 3);
    addEdgeList(graph, 1, 4);
    addEdgeList(graph, 2, 3);
    addEdgeList(graph, 3, 4);

    printGraphList(graph);

    // Free memory (optional but recommended)
    for (int i = 0; i < vertices; i++) {
        struct Node* temp = graph->adjList[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjList);
    free(graph);

    return 0;
}
