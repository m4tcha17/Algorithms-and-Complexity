#include <stdio.h>
#include <limits.h>

#define MAX 5
#define INF 9999

typedef int Set[MAX];
typedef int adjMatrix[MAX][MAX];

adjMatrix graph = {
    { 0,   3,   INF, 7,   INF },
    { 8,   0,   2,   INF, INF },
    { 5,   INF, 0,   1,   INF },
    { INF, 4,   INF, 0,   INF },
    { 2,   INF, INF, 3,   0   },
};

void visualize(adjMatrix g) {
    printf("Adjacency Matrix:\n\n     ");
    for (int i = 0; i < MAX; i++) printf("[%2d] ", i);
    printf("\n");
    for (int i = 0; i < MAX; i++) {
        printf("[%2d] ", i);
        for (int j = 0; j < MAX; j++) {
            if (g[i][j] == INF) printf(" INF ");
            else                printf("%4d ", g[i][j]);
        }
        printf("\n");
    }
    printf("\nEdge List:\n");
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            if (i != j && g[i][j] != INF)
                printf("  %d -> %d : %d\n", i, j, g[i][j]);
    printf("\n");
}

void dijkstra(adjMatrix g, int src) {
    Set S = {};
    int D[MAX];
    S[src] = 1;

    // Initialize D, initially contianed the direct edge weights from the source, will be updated to shortest path after algorithm
    for(int i = 0; i < MAX; i++) D[i] = g[src][i];

    // Loop MAX - 1 so that all vertices except the source vertex are passed through once
    for(int x = 1; x < MAX; x++){
        int w = -1;
        // Chooses a vertex that is not visited that has the smallest distance/weight
        for(int j = 0; j < MAX; j++){
            // Initial assignment of w, first unvisited vertex found
            if(S[j] == 0){
                if(w == -1){
                    w = j;
                }
                else{
                    // Changed w if a smaller value is found
                    if(D[j] < D[w]) w = j; 
                }
            }
        }
        // Mark w as visited
        S[w] = 1;
        for(int v = 0; v < MAX; v++){
            // Isolate only unvisited vertices
            if(S[v] == 0){
                // get the distance of the alternate path
                int altPath = D[w] + g[w][v];
                // Compare if current path is shorter than the sum of the current path and path after to the vertex, or the alternate path
                D[v] = D[v] < altPath ? D[v] : altPath;
            }
        }
    }

    for(int i = 0; i < MAX; i++) {
        if (D[i] == INF) printf(" INF ");
        else printf("%4d ", D[i]);
    }
}

void printExpected() {
    int exp[MAX][MAX] = {
        {  0,  3,  5,  6, INF },
        {  7,  0,  2,  3, INF },
        {  5,  5,  0,  1, INF },
        { 11,  4,  6,  0, INF },
        {  2,  5,  7,  3,   0 },
    };
    printf("Expected Distances:\n\n     ");
    for (int j = 0; j < MAX; j++) printf("[%2d] ", j);
    printf("\n");
    for (int i = 0; i < MAX; i++) {
        printf("[%2d] ", i);
        for (int j = 0; j < MAX; j++) {
            if (exp[i][j] == INF) printf(" INF ");
            else                  printf("%4d ", exp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printMyOutput() {
    printf("My Output:\n\n     ");
    for (int j = 0; j < MAX; j++) printf("[%2d] ", j);
    printf("\n");
    for (int src = 0; src < MAX; src++) {
        printf("[%2d] ", src);
        dijkstra(graph, src);
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    visualize(graph);
    printExpected();
    printMyOutput();
    return 0;
}