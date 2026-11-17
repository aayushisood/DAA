
#include <stdio.h>

int main()
{
    int n, i, j, temp;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n], room[n];

    printf("Enter start and finish times:\n");

    for(i = 0; i < n; i++)
    {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
        room[i] = 0;
    }

    // Sort activities by start time
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(start[j] > start[j + 1])
            {
                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;

                temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;
            }
        }
    }

    int roomEnd[n];
    int rooms = 0;

    // Assign activities to rooms
    for(i = 0; i < n; i++)
    {
        int assigned = 0;

        for(j = 0; j < rooms; j++)
        {
            if(roomEnd[j] <= start[i])
            {
                roomEnd[j] = finish[i];
                room[i] = j + 1;
                assigned = 1;
                break;
            }
        }

        // Create a new room if none is available
        if(assigned == 0)
        {
            rooms++;
            roomEnd[rooms - 1] = finish[i];
            room[i] = rooms;
        }
    }

    printf("\nActivity Allocation:\n");

    for(i = 0; i < n; i++)
    {
        printf("Activity %d: %d - %d -> Room %d\n",
               i + 1, start[i], finish[i], room[i]);
    }

    printf("\nMinimum number of rooms required: %d\n", rooms);

    return 0;
}
