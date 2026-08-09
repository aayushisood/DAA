//  Library Book Management
#include <stdio.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    int total;
    int available;
};

int main()
{
    struct Book book[100];
    int n = 0;
    int choice, id, i, found;

    while(1)
    {
        printf("\n\nLibrary Menu\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Display Unavailable Books\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter book ID: ");
            scanf("%d", &book[n].id);

            printf("Enter book title: ");
            scanf(" %[^\n]", book[n].title);

            printf("Enter author name: ");
            scanf(" %[^\n]", book[n].author);

            printf("Enter total copies: ");
            scanf("%d", &book[n].total);

            book[n].available = book[n].total;

            n++;

            printf("Book added successfully.\n");
        }

        else if(choice == 2)
        {
            printf("Enter book ID to search: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++)
            {
                if(book[i].id == id)
                {
                    printf("\nBook ID: %d", book[i].id);
                    printf("\nTitle: %s", book[i].title);
                    printf("\nAuthor: %s", book[i].author);
                    printf("\nTotal copies: %d", book[i].total);
                    printf("\nAvailable copies: %d", book[i].available);

                    found = 1;
                    break;
                }
            }

            if(found == 0)
            {
                printf("Book not found.\n");
            }
        }

        else if(choice == 3)
        {
            printf("Enter book ID to issue: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++)
            {
                if(book[i].id == id)
                {
                    found = 1;

                    if(book[i].available > 0)
                    {
                        book[i].available--;
                        printf("Book issued successfully.\n");
                    }
                    else
                    {
                        printf("Book is currently unavailable.\n");
                    }

                    break;
                }
            }

            if(found == 0)
            {
                printf("Book not found.\n");
            }
        }

        else if(choice == 4)
        {
            printf("Enter book ID to return: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++)
            {
                if(book[i].id == id)
                {
                    found = 1;

                    if(book[i].available < book[i].total)
                    {
                        book[i].available++;
                        printf("Book returned successfully.\n");
                    }
                    else
                    {
                        printf("All copies are already available.\n");
                    }

                    break;
                }
            }

            if(found == 0)
            {
                printf("Book not found.\n");
            }
        }

        else if(choice == 5)
        {
            found = 0;

            printf("\nCurrently unavailable books:\n");

            for(i = 0; i < n; i++)
            {
                if(book[i].available == 0)
                {
                    printf("\nBook ID: %d", book[i].id);
                    printf("\nTitle: %s", book[i].title);
                    printf("\nAuthor: %s\n", book[i].author);

                    found = 1;
                }
            }

            if(found == 0)
            {
                printf("No books are currently unavailable.\n");
            }
        }

        else if(choice == 6)
        {
            printf("Exiting program...\n");
            break;
        }

        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}