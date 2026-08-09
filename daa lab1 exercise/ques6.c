//  Write a C program to find all pairs of elements in an array whose sum is equal to a given target value. Each pair should be displayed only once.
#include <stdio.h>

int main()
{
    int n, i, j, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target value: ");
    scanf("%d", &target);

    printf("Pairs whose sum is equal to %d:\n", target);

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] + arr[j] == target)
            {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }

    return 0;
}