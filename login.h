#include <stdio.h>
#include <string.h>

struct Users
{
    char username[50];
    char password[50];
};

void registration(void)
{

    FILE *file = fopen("Login.txt", "w");

    if (file == NULL)
    {
        printf("File Does not exist.\n");
        return;
    }

    struct Users user;

    printf("\n\t\tWelcome to Register:\n");
    printf("\t\tEnter a userame: ");
    scanf("%s", user.username);

    printf("\t\tEnter a password: ");
    scanf("%s", user.password);

    fprintf(file, "%s %s\n", user.username, user.password);
    fclose(file);

    printf("\n\t\t\n  Successfully Registered!\n");
    sleep(2);
}

void login(void)
{
    FILE *file = fopen("Login.txt", "r");

    if (file == NULL)
    {
        printf("File can not open.\n");
        return;
    }

    struct Users inp;
    struct Users user;
    int flag = 0;
    int attempts = 5;

    while (attempts > 0)
    {
        printf("\n\t\tWelcome to Login\n");
        printf("\t\tEnter username: ");
        scanf("%s", inp.username);

        printf("\t\tEnter the password: ");
        scanf("%s", inp.password);

        system("cls");

        fseek(file, 0, SEEK_SET);

        while (fscanf(file, "%s %s", user.username, user.password) != EOF)
        {
            if (strcmp(inp.username, user.username) == 0 && strcmp(inp.password, user.password) == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            printf("\n\t\tSuccessfully logged in!\n\n");
            break;
        }

        else
        {
            printf("\n\t\tInvalid Username or Password, Try again.");
            attempts--;
            printf(" (%d attempts remaining)\n", attempts);
        }
    }

    if (attempts == 0)
        printf("\t\tYou've exceeded the maximum number of attempts, Try Later\n");
}
