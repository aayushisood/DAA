// Write a C program to rotate an array to the right by K positions without using another array.
#include <stdio.h>

int main()
{
    int n, k, i, j, temp;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of K: ");
    scanf("%d", &k);

    k = k % n;

    for(i = 0; i < k; i++)
    {
        temp = arr[n - 1];

        for(j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }

        arr[0] = temp;
    }

    printf("Array after rotation:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}