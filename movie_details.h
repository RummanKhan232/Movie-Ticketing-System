
#include<stdio.h>
#include<string.h>

int main(void)
{
    display_movie();
}
void display_movie(void)
{
    FILE *file = fopen("file.txt", "r");

    if (file == NULL)
    {
        printf("File Can not open.\n");
        // return 1;
    }

    struct Movie
    {
        char title[100];
        char actors[100];
        char date[50];
        char genre[50];
        char time[50];
        char duration[25];
    };
    struct Movie movies[10];

    int numMovies = 0;

    while (fgets(movies[numMovies].title, 100, file) != NULL)
    {

        fgets(movies[numMovies].actors, 100, file);
        fgets(movies[numMovies].genre, 50, file);
        fgets(movies[numMovies].duration, 25, file);
        fgets(movies[numMovies].date, 50, file);
        fgets(movies[numMovies].time, 50, file);

        fgetc(file);

        numMovies++;

        fgetc(file);
    }

    fclose(file);

    for (int i = 0; i < numMovies; i++)
    {
        printf("Movie %d:\n", i + 1);
        printf("%s", movies[i].title);
        printf("%s", movies[i].actors);
        printf("%s", movies[i].genre);
        printf("%s", movies[i].duration);
        printf("%s", movies[i].date);
        printf("%s", movies[i].time);

        printf("\n");
    }
}