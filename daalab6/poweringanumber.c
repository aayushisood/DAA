#include <stdio.h>

int power(int x, int n)
{
    int y;

    if (n == 0)
        return 1;

    y = power(x, n / 2);

    if (n % 2 == 0)
        return y * y;
    else
        return x * y * y;
}

int main()
{
    int x, n;

    printf("Enter number and power: ");
    scanf("%d %d", &x, &n);

    printf("Answer = %d", power(x, n));

    return 0;
}