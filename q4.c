/*Write a program that use a structure to hold information about movies, such as title, genre, director, release year, and rating. 
Write a program that allows users to add new movies, search for movies by genre, and display all movie details*/
#include <stdio.h>
#include <string.h>


struct Movie{
    char title[50],genre[30],  director[50];
    int release_year;
    float rating;
};
void addMovie(struct Movie movies[], int *count){
    printf("\nEnter movie title: ");
    getchar();
    fgets(movies[*count].title,sizeof(movies[*count].title),stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = '\0'; //This removes newline which fgets make

    printf("Enter movie genre: ");
    fgets(movies[*count].genre,sizeof(movies[*count].genre),stdin);
    movies[*count].genre[strcspn(movies[*count].genre, "\n")] = '\0'; 

    printf("Enter movie director: ");
    fgets(movies[*count].director,sizeof(movies[*count].director),stdin);
    movies[*count].director[strcspn(movies[*count].director, "\n")] = '\0'; 

    printf("Enter release year: ");
    scanf("%d",&movies[*count].release_year);

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f",&movies[*count].rating);

    (*count)++;
    printf("\nMovie added successfully!\n");
}//end addMovie(struct Movie movies[], int *count)

void displayMovies(struct Movie movies[],int count){
    if (count==0) 
    {
         printf("\nNo movies available.\n");
        return;

    }
    for (int i = 0;i < count;i++) {
         printf("\nMovie %d\n", i + 1);
        printf("Title: %s\n",movies[i].title); printf("Genre: %s\n",movies[i].genre);
         printf("Director: %s\n",  movies[i].director);
        printf("Release Year: %d\n", movies[i].release_year);
        printf("Rating: %.1f\n",movies[i].rating);
    
    }
}//displayMovies(struct Movie movies[],int count) ending

void searchMoviesByGenre(struct Movie movies[], int count, const char *genre) 
{
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printf("\nFound Movie %d:\n", i + 1);
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Release Year: %d\n", movies[i].release_year);
            printf("Rating: %.1f\n", movies[i].rating);
            found = 1;
        }//end if
    }//end forloop
    if (!found) {
        printf("\nNo movies found with genre %s.\n", genre);
    }//end if
}

int main(void){
    struct Movie movies[100];
    int count = 0, choice;
    
    while (choice!=4) {
   
        printf("\nMovie Database Menu:\n1. Add New Movie\n2. Display All Movies\n3. Search Movies by Genre\n4. Exit\nEnter your choice: ");

        scanf("%d",&choice);
        
        switch (choice) {
            case 1:
                addMovie(movies,&count);
                break;
            case 2:
                displayMovies(movies,count);
                break;
            case 3: {
                char genre[30];
                printf("\nEnter genre to search: ");
                 getchar();
               
                fgets(genre, sizeof(genre), stdin);
                genre[strcspn(genre,"\n")]= '\0'; 
                 searchMoviesByGenre(movies,count,genre);
                break;
            }
            case 4:
                printf("\nExiting program. \n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
