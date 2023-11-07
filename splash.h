#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void displayScreen(void);

int main(void)
{
    displayScreen();
}


void displayScreen(void)
{

    printf("\033[1;34m");
    printf("                 @-_________________-@ \n");
    printf("           @-_____|   WELCOME TO   |_____-@ \n");
    printf("           |    MOVIE TICKETING SYSTEM   | \n");
    printf("    _______|_____________________________|__________ \n");
    printf("   |________________________________________________| \n");
    printf("   |               -                -               | \n");
    printf("   |   -       -             -                    - | \n");
    printf("   |        ____    ______________-   ____          | \n");
    printf("   | -  -  |    |   |  TICKETS   |   |    | -       | \n");
    printf("   |       |    |   |            |   |    |         | \n");
    printf("   |  --   |____| - |_o___oo___o_| - |____|     -   | \n");
    printf("   | -     |    |  |     --       |  |    |         | \n");
    printf("   |    -  |    |- | -      -     |  |    | --      | \n");
    printf("   |_______|====|__|______________|__|====|_________| \n");
    printf("  /             RKCHAMP MOVIE CENTER                 \\ \n");
    printf(" /____________________________________________________\\ \n");

    sleep(4);
    system("cls");

    sleep(2);
    system("cls");
}