
#include <stdio.h>

#define INF 99999

struct Edge
{
    int src, dest, weight;
};

int main()
{
    int V, E, i, j, source;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edge[E];
    int dist[V];

    printf("Enter source, destination and weight of edges:\n");

    for(i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edge[i].src,
              &edge[i].dest,
              &edge[i].weight);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize distances
    for(i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Relax all edges V-1 times
    for(i = 1; i <= V - 1; i++)
    {
        for(j = 0; j < E; j++)
        {
            int u = edge[j].src;
            int v = edge[j].dest;
            int w = edge[j].weight;

            if(dist[u] != INF &&
               dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for(j = 0; j < E; j++)
    {
        int u = edge[j].src;
        int v = edge[j].dest;
        int w = edge[j].weight;

        if(dist[u] != INF &&
           dist[u] + w < dist[v])
        {
            printf("\nGraph contains negative weight cycle.\n");
            return 0;
        }
    }

    // Print shortest distances
    printf("\nVertex\tDistance from Source\n");

    for(i = 0; i < V; i++)
    {
        if(dist[i] == INF)
            printf("%d\tUnreachable\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}
