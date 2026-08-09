// matric multiplication
#include <stdio.h>
int main()
{
    int r1, c1, r2, c2, i, j, k;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if(c1 != r2)
    {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    int arr1[r1][c1];
    int arr2[r2][c2];
    int result[r1][c2];

    printf("Enter elements of first matrix:\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for(i = 0; i < r2; i++)
    {
        for(j = 0; j < c2; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                result[i][j] = result[i][j] + arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("Result of matrix multiplication:\n");

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            printf("%d ", result[i][j]);
        }

        printf("\n");
    }

    return 0;
}