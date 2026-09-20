#include <stdio.h>

int main()
{
    int a[10][10];
    int n, i, j, celebrity;
    int row, col;

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter the matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    celebrity = -1;

    for(i = 0; i < n; i++)
    {
        row = 1;
        col = 1;

        // Check row 
        for(j = 0; j < n; j++)
        {
            if(i != j && a[i][j] != 0)
            {
                row = 0;
                break;
            }
        }

        // Check column 
        for(j = 0; j < n; j++)
        {
            if(i != j && a[j][i] != 1)
            {
                col = 0;
                break;
            }
        }

        if(row == 1 && col == 1)
        {
            celebrity = i;
            break;
        }
    }

    if(celebrity != -1)
        printf("Celebrity is person %d", celebrity);
    else
        printf("No celebrity");

    return 0;
}