#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void main(void)
{

    int totalTicket, choice, totalPayment;
    char ch[5];
    displayScreen();

    printf("\n\n\n");

    do
    {

        // printf("\033[1;35m");

        system("cls");

        printf("\n||=======================================================================||");

        printf("\n||                                                                       ||");

        printf("\n||                RKCHAMP MOVIE TICKETING SYSTEM                         ||");

        printf("\n||                                                                       ||");

        printf("\n||=======================================================================||\n\n");

        printf("\n Press [1] To Register                                 ");

        printf("\n Press [2] To  Display Movies                                       ");

        printf("\n Press [3] To Book Ticket                                    ");

        printf("\n Press [4] To Make Payment                                   ");

        // printf("\n Press [6] To Cancel Ticket                                   ");

        printf("\n Press [5] To  Exit                                           ");

        printf("\n\n          Please Enter Your Choice::  ");

        scanf("%d", &choice);

        switch (choice)

        {
        case 1:
            registration();
            login();
            printf("\n\t\tEnter any key to go next step\n");
            scanf("%s", ch);
            break;

        case 2:
            display_movie();
            printf("\n\t\tEnter any Key to go next step\n");
            scanf("%s", ch);
            break;

        case 3:

            totalTicket = book_Ticket();
            printf("\n\t\tEnter any Character to go next step\n");
            scanf("%s", ch);
            break;

        case 4:

            totalPayment = payment(totalTicket);

            printf("you Booked total %d tickets\n", totalTicket);
            printf("Total Payment: %d\n", totalPayment);

            int option;

            struct UserInfo user;

            printf("Select Payment Option: \n");
            printf("1. Bkash\n");
            printf("2.Nagad\n");
            printf("3. Card\n");

            scanf("%d", &option);

            if (option == 1)
                payBkash(user);

            else if (option == 2)
                payNagad(user);

            else if (option == 3)
                payCard(user);

            else
                printf("Invalid Choice!\n");

            printf("\n\t\tEnter any Character to go next step\n");
            scanf("%s", ch);
            break;
        }

    } while (choice != 5);

    if (choice == 5)
        printf("Thanks For Visiting Our Server!\n");
}

int book_Ticket(void)

{
    initializeSeats();

    int sum_ticket = 0;

    while (1)
    {
        printf("\n1. Spider-Man: Far From Home \n");
        printf("2. Avengers: Infinity War\n");
        printf("3. Joker\n");

        printf("\nChoose a movie (1-%d) or 0 to exit: ", MAX_MOVIES);
        int movie;
        scanf("%d", &movie);

        if (movie == 0)

            break;

        else if (movie < 1 || movie > MAX_MOVIES)

            printf("Invalid movie selection. Please try again.\n");

        else
        {
            displaySeats(movie - 1);

            while (1)
            {
                int row, col;
                printf("\nEnter the row and column (e.g. 2 3) for the seat you want to book (0 to exit): \n");
                scanf("%d %d", &row, &col);

                if (row == 0 || col == 0)
                {
                    break;
                }

                if (bookSeat(movie - 1, row, col))
                {
                    displaySeats(movie - 1);
                }
            }
        }
    }

    for (int i = 0; i < MAX_MOVIES; i++)
    {
        printf("\tMovie %d: Successfully booked %d tickets\n", i + 1, num_tickets[i]);
        sum_ticket += num_tickets[i];
    }

    printf(" \tYou booked a total of %d tickets\n", sum_ticket);

    return sum_ticket;
}
