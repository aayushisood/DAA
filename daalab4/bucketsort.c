#include <stdio.h>

int main()
{
    int a[20], bucket[10][20];
    int n, i, j, k;
    int count[10] = {0};

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    /* Put elements into buckets */
    for(i = 0; i < n; i++)
    {
        int b = a[i] / 10;
        bucket[b][count[b]] = a[i];
        count[b]++;
    }

    /* Sort each bucket */
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < count[i] - 1; j++)
        {
            for(k = j + 1; k < count[i]; k++)
            {
                if(bucket[i][j] > bucket[i][k])
                {
                    int temp = bucket[i][j];
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }
            }
        }
    }

    /* Combine buckets */
    k = 0;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < count[i]; j++)
        {
            a[k] = bucket[i][j];
            k++;
        }
    }

    printf("Sorted array:\n");

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}