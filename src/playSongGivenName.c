#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include "../include/given.h"


/* Task 5 */
int playSongGivenName(A3Song *headLL, char givenSongName[MAX_LENGTH]) {

    // declare variables  
    int found = 0; // check if song is found

    // check if playlist is empty 
    if (headLL == NULL) {
        printf("Playlist is empty.\n");
        return -1;
    }

    // loop through each song in the playlist
    while (headLL != NULL) {

        // check if current song name matches input (case-insensitive)
        if (strcasecmp(headLL->songName, givenSongName) == 0) {

            // mark song as found
            found = 1;

            // print song ID and name
            printf("Song ID: %d\n", headLL->songId);
            printf("Song name: %s\n", headLL->songName);
            printf("Notes:\n");

            // loop through notes and print each one
            for (int i = 0; i < 21; i++) {
                printf("%s", headLL->songNotes[i]);

                // print dot between notes
                if (i != 20) {
                    printf(".");
                }
            }

            // newline after last note
            printf("\n");

            // exit loop 
            break;
        }

        // move to next song
        headLL = headLL->nextSong;
    }

    // if not found, tell user and return -1
    if (found == 0) {
        printf("Song %s not found.\n", givenSongName);
        return -1;
    }

    // song found and played
    return 1;
}