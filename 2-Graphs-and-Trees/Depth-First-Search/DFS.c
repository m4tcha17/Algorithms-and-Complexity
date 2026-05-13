#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 6
typedef int SET[MAX_VERTICES];
typedef int adjMatrix[MAX_VERTICES][MAX_VERTICES]; 

// Function Prototypes
void bfs(int start, adjMatrix);
void callDFS(int start, adjMatrix);
void dfs(int start, adjMatrix, int[]);
void visualizeGraph(char* title, adjMatrix, bool isDirected);
void visualizeLayout(bool isDirected);

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

    printf("=== DFS UNDIRECTED TEST CASES ===\n");
    printf("Start 1 | Expected: 1 0 2 3 5 4 | Actual: "); callDFS(1, undirectedAdj); printf("\n");
    printf("Start 3 | Expected: 3 1 0 2 4 5 | Actual: "); callDFS(3, undirectedAdj); printf("\n");
    printf("Start 5 | Expected: 5 3 1 0 2 4 | Actual: "); callDFS(5, undirectedAdj); printf("\n\n");

    printf("=== DFS DIRECTED TEST CASES ===\n");
    printf("Start 1 | Expected: 1 3 5 0 2 4 | Actual: "); callDFS(1, directedAdj); printf("\n");
    printf("Start 3 | Expected: 3 5 0 1 2 4 | Actual: "); callDFS(3, directedAdj); printf("\n");
    printf("Start 5 | Expected: 5 0 1 3 2 4| Actual: "); callDFS(5, directedAdj); printf("\n");

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

void visualizeGraph(char* title, adjMatrix matrix, bool isDirected) {
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

void callDFS(int start, adjMatrix matrix) {
    // --- CODE ---
    SET visited = {};
    dfs(start, matrix, visited);
    for (int i = 0; i < MAX_VERTICES; i++){
        if(visited[i] == 0){
            dfs(i, matrix, visited);
        }
    }
}

void dfs(int root, adjMatrix matrix, int visited[]){
    printf("%d ", root);
    visited[root] = 1;

    for(int i = 0; i < MAX_VERTICES; i++){
        if(visited[i] == 0 && matrix[root][i] == 1){
            dfs(i, matrix, visited);
        }
    }
}