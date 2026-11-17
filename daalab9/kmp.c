
#include <stdio.h>
#include <string.h>

// Function to create LPS array
void computeLPS(char pattern[], int m, int lps[])
{
    int len = 0;
    int i = 1;

    lps[0] = 0;

    while(i < m)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP pattern matching function
void KMP(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    int lps[m];

    computeLPS(pattern, m, lps);

    int i = 0, j = 0;
    int found = 0;

    while(i < n)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if(j == m)
        {
            printf("Pattern found at index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        }
        else if(i < n && text[i] != pattern[j])
        {
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if(found == 0)
        printf("Pattern not found.\n");
}

int main()
{
    char text[100], pattern[50];

    printf("Enter the text: ");
    scanf("%99s", text);

    printf("Enter the pattern: ");
    scanf("%49s", pattern);

    KMP(text, pattern);

    return 0;
}
