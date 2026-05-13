#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 6
typedef int SET[MAX_VERTICES];
typedef int adjMatrix[MAX_VERTICES][MAX_VERTICES];
typedef struct {
    int queue[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Function Prototypes
void callBfs(int start, adjMatrix);
void bfs(int root, adjMatrix matrix, int[]);
void visualizeGraph(char* title, adjMatrix, bool isDirected);
void visualizeLayout(bool isDirected);

// Queue Function Prototypes
void initQueue(Queue*);
bool isEmpty(Queue);
void enqueue(Queue*, int);
int dequeue(Queue*);

int main() {
    adjMatrix undirectedAdj = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };
    visualizeLayout(false);

    adjMatrix directedAdj = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };
    visualizeLayout(true);

    visualizeGraph("UNDIRECTED STRUCTURE", undirectedAdj, false);
    visualizeGraph("DIRECTED STRUCTURE", directedAdj, true);

    printf("=== BFS UNDIRECTED TEST CASES ===\n");
    printf("Start 0 | Expected: 0 1 2 3 4 5 | Actual: "); callBfs(0, undirectedAdj); printf("\n");
    printf("Start 2 | Expected: 2 0 3 4 1 5 | Actual: "); callBfs(2, undirectedAdj); printf("\n");
    printf("Start 4 | Expected: 4 2 5 0 3 1 | Actual: "); callBfs(4, undirectedAdj); printf("\n\n");

    printf("=== BFS DIRECTED TEST CASES ===\n");
    printf("Start 0 | Expected: 0 1 2 3 4 5 | Actual: "); callBfs(0, directedAdj); printf("\n");
    printf("Start 2 | Expected: 2 4 5 0 1 3 | Actual: "); callBfs(2, directedAdj); printf("\n");
    printf("Start 4 | Expected: 4 5 0 1 2 3 | Actual: "); callBfs(4, directedAdj); printf("\n");

    return 0;
}

void visualizeLayout(bool isDirected) {
    printf("Graph Map:\n");
    if (isDirected) {
        // Two parallel paths merging at 5
        printf("  (0) ---▶ (1) ---▶ (3) \n");
        printf("   |                 |  \n");
        printf("   ▼                 ▼  \n");
        printf("  (2) ---▶ (4) ---▶ (5) \n");
    } 
    else {
        printf("  (0) ----- (1)\n");
        printf("   |         | \n");
        printf("  (2) ----- (3)\n"); 
        printf("   |         | \n");
        printf("  (4) ----- (5)\n"); 
    }
    printf("\n");
}

void visualizeGraph(char* title, int matrix[MAX_VERTICES][MAX_VERTICES], bool isDirected) {
    printf("=== %s ===\n", title);
    
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("Vertex %d: ", i);
        bool hasEdges = false;
        
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (matrix[i][j] == 1) {
                if (isDirected) {
                    printf("[%d -> %d] ", i, j);
                } else {
                    if (i < j) printf("[%d -- %d] ", i, j);
                }
                hasEdges = true;
            }
        }
        
        if (!hasEdges) printf("(No outgoing edges)");
        printf("\n");
    }
    printf("============================\n\n");
}

void initQueue(Queue* Q){
    Q->front = 1;
    Q->rear = 0;
}

bool isEmpty(Queue Q){
    return (Q.rear + 1) % MAX_VERTICES == Q.front ? true : false;
}

void enqueue(Queue *Q, int elem){
    if(Q->rear + 2 % MAX_VERTICES != Q->front){
        Q->rear = (Q->rear + 1) % MAX_VERTICES;
        Q->queue[Q->rear] = elem;
    }
}

int dequeue(Queue *Q){
    int ret = -1;
    if(!isEmpty(*Q)){
        ret = Q->queue[Q->front];
        Q->front = (Q->front + 1) % MAX_VERTICES;
    }
    return ret;
}

void callBfs(int start, adjMatrix matrix) {
    // --- CODE ---
    SET visited = {};
    bfs(start, matrix, visited);

    for(int i = 0; i < MAX_VERTICES; i++){
        if(visited[i] == 0){
            bfs(i, matrix, visited);
        }
    }
}

void bfs(int root, adjMatrix matrix, int visited[]){
    visited[root] = 1;
    Queue Q;
    initQueue(&Q);
    enqueue(&Q, root);

    while(!isEmpty(Q)){
        int vertex = dequeue(&Q);
        printf("%d ", vertex);

        for(int i = 0; i < MAX_VERTICES; i++){
            if(visited[i] == 0 && matrix[vertex][i] == 1){
                visited[i] = 1;
                enqueue(&Q, i);
            }
        }
    }
}