#include <stdio.h>
#define V 6  // number of vertices

int main() {
    // Adjacency matrix initialization
    int graph[V][V] = {
        {0, 6, 3, 0, 0, 0},
        {6, 0, 2, 7, 0, 0},
        {3, 2, 0, 3, 4, 0},
        {0, 7, 3, 0, 2, 3},
        {0, 0, 4, 2, 0, 5},
        {0, 0, 0, 3, 5, 0}
    };

    // Print the matrix (just to verify)
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}