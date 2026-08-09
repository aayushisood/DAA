// ATM transaction system 
#include <stdio.h>

int main()
{
    int choice, i, count = 0;
    float balance = 0, amount;
    float transactions[5];

    while(1)
    {
        printf("\n\nATM Menu\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Current Balance: %.2f\n", balance);
        }

        else if(choice == 2)
        {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            if(amount > 0)
            {
                balance = balance + amount;

                if(count < 5)
                {
                    transactions[count] = amount;
                    count++;
                }
                else
                {
                    for(i = 0; i < 4; i++)
                    {
                        transactions[i] = transactions[i + 1];
                    }

                    transactions[4] = amount;
                }

                printf("Amount deposited successfully.\n");
            }
            else
            {
                printf("Invalid amount.\n");
            }
        }

        else if(choice == 3)
        {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if(amount > balance)
            {
                printf("Insufficient balance.\n");
            }
            else if(amount <= 0)
            {
                printf("Invalid amount.\n");
            }
            else
            {
                balance = balance - amount;

                if(count < 5)
                {
                    transactions[count] = -amount;
                    count++;
                }
                else
                {
                    for(i = 0; i < 4; i++)
                    {
                        transactions[i] = transactions[i + 1];
                    }

                    transactions[4] = -amount;
                }

                printf("Amount withdrawn successfully.\n");
            }
        }

        else if(choice == 4)
        {
            printf("\nLast five transactions:\n");

            for(i = 0; i < count; i++)
            {
                if(transactions[i] > 0)
                    printf("Deposited: %.2f\n", transactions[i]);
                else
                    printf("Withdrawn: %.2f\n", -transactions[i]);
            }

            printf("Thank you for using the ATM.\n");
            break;
        }

        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}