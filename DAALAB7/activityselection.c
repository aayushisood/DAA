
#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    printf("Enter start and finish times:\n");

    for(i = 0; i < n; i++)
    {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Sort activities according to finish time
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(finish[j] > finish[j + 1])
            {
                int temp;

                temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;

                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }

    printf("\nSelected Activities:\n");

    // Select the first activity
    int lastFinish = finish[0];

    printf("Activity 1 (Start: %d, Finish: %d)\n",
           start[0], finish[0]);

    int count = 1;

    // Select remaining compatible activities
    for(i = 1; i < n; i++)
    {
        if(start[i] >= lastFinish)
        {
            printf("Activity (Start: %d, Finish: %d)\n",
                   start[i], finish[i]);

            lastFinish = finish[i];
            count++;
        }
    }

    printf("\nMaximum number of activities = %d\n", count);

    return 0;
}
