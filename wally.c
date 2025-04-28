
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

time_t start_time;

void handle_exit(int sig) {
    time_t end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);
    printf("\n\nYou've killed Wally.\n\nHis short and miserable life lasted %.0f seconds.\n\n", elapsed_time);
    exit(0);
}

int main()
{
	start_time = time(NULL);
	
	signal(SIGINT, handle_exit);

	char message[] = "Hi, I'm Wally and I exist among\nthe bits and bytes of this computer.\n\nAs long as this program keeps running,\nI will live.\n\nI'm scared. :-( ";

    while (1) {
        // Clear the screen
        printf("\033[2J\033[H");

        // Print the static message
        printf("%s", message);

        // Print the heart
        printf("🩶\n");
        fflush(stdout);
        usleep(200000);

        // Clear the screen again
        printf("\033[2J\033[H");

        // Print the static message again
	 printf("%s", message);

        // Print a space instead of the heart
        printf(" \n");
        fflush(stdout);
        usleep(300000);
    }

    return 0;
}

