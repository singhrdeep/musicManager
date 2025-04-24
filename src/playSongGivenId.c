#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include "../include/given.h"


/* Task 4 */
int playSongGivenId(A3Song *headLL, int songId) {

    // declare variables
    int found = 0; // check if song is found

    // check if playlist is empty
    if (headLL == NULL) {
        printf("Playlist is empty.\n");
        return -1; 
    }

    // loop through each song in playlist
    while (headLL != NULL) {

        // check if current song ID matches user input
        if (headLL->songId == songId) {

            // mark that match is found
            found = 1;

            // print song ID and name
            printf("Song ID: %d\n", headLL->songId);
            printf("Song name: %s\n", headLL->songName);
            printf("Notes:\n");

            // iterate and print the notes
            for (int i = 0; i < 21; i++) {
                // print the note
                printf("%s", headLL->songNotes[i]);

                // print dot after note, except after last note
                if (i != 20) {
                    printf(".");
                }
            }

            // print newline after notes
            printf("\n");

            // stop searching
            break;
        }

        // move to next song
        headLL = headLL->nextSong;
    }

    // if not found, tell user and return 0
    if (found == 0) {
        printf("Song %d not found.\n", songId);
        return -1;
    }

    // song found successfully
    return 1;
}