#include <stdio.h>

int main()
{
    int n, e, i, j, temp;
    int u[20], v[20], w[20];
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");

    for(i = 0; i < e; i++)
    {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    /* Arrange weights in descending order */
    for(i = 0; i < e - 1; i++)
    {
        for(j = i + 1; j < e; j++)
        {
            if(w[i] < w[j])
            {
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                temp = u[i];
                u[i] = u[j];
                u[j] = temp;

                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    printf("\nEdges arranged in descending order:\n");

    for(i = 0; i < e; i++)
    {
        printf("%d -- %d  %d\n", u[i], v[i], w[i]);
    }

    printf("\nKruskal's MST:\n");

    /* Select from smallest weight */
    for(i = e - 1; i >= 0; i--)
    {
        printf("%d -- %d  %d\n", u[i], v[i], w[i]);
    }

    return 0;
}