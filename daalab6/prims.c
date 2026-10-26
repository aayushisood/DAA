#include <stdio.h>

int main() {
    int n, cost[10][10], visited[10] = {0};
    int i, j, k, min, u, v, total = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;

    for(k = 0; k < n - 1; k++) {
        min = 999;

        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", u, v, min);
        total += min;
        visited[v] = 1;
    }

    printf("Total cost = %d", total);

    return 0;
}