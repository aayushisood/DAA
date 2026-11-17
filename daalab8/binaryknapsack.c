
#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, capacity, i, w;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];

    printf("Enter weight and profit of each item:\n");

    for(i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &weight[i], &profit[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int dp[n + 1][capacity + 1];

    // Initialize DP table
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= capacity; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("\nMaximum profit = %d\n", dp[n][capacity]);

    return 0;
}
