    
#include <stdio.h>
#include <string.h>

#define d 256
#define q 101

int main()
{
    char text[100], pattern[50];

    int n, m, i, j;
    int p = 0, t = 0, h = 1;
    int found = 0;

    printf("Enter the text: ");
    scanf("%99s", text);

    printf("Enter the pattern: ");
    scanf("%49s", pattern);

    n = strlen(text);
    m = strlen(pattern);

    if(m > n)
    {
        printf("Pattern not found.\n");
        return 0;
    }

    // Calculate h = d^(m-1) % q
    for(i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values
    for(i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text
    for(i = 0; i <= n - m; i++)
    {
        // Check hash values
        if(p == t)
        {
            // Verify actual characters
            for(j = 0; j < m; j++)
            {
                if(text[i + j] != pattern[j])
                    break;
            }

            if(j == m)
            {
                printf("Pattern found at index %d\n", i);
                found = 1;
            }
        }

        // Calculate hash for next window
        if(i < n - m)
        {
            t = (d * (t - text[i] * h)
                 + text[i + m]) % q;

            if(t < 0)
                t += q;
        }
    }

    if(found == 0)
        printf("Pattern not found.\n");

    return 0;
}
