// to check if string is palindrome.
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j, len, flag = 1;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    len = strlen(str);

    for(i = 0; i < len; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }

    i = 0;
    j = len - 1;

    while(i < j)
    {
        if(str[i] == ' ')
        {
            i++;
        }
        else if(str[j] == ' ')
        {
            j--;
        }
        else
        {
            if(str[i] != str[j])
            {
                flag = 0;
                break;
            }

            i++;
            j--;
        }
    }

    if(flag)
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}