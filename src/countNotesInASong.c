#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include "../include/given.h"


/* Task 6 */
int countNotesInASong(A3Song *headLL, int givenSongId, char whichNote[4]) {
    
    // declare variables 
    int counter = 0; // counter 
    int found = 0; // check if song is found 
    
    // check if playlist is empty 
    if (headLL == NULL) {
        printf("Playlist is empty.\n");
        return -1;
    }
    
    // loop through each song in the playlist
    while (headLL != NULL) {

        // check if current song matches the given id
        if (headLL->songId == givenSongId) {
            found = 1; // mark that we found the song

            // loop through all notes
            for (int i = 0; i < 21; i++) {
                
                // if note matches the one we're looking for
                if (strcmp(headLL->songNotes[i], whichNote) == 0) {
                    counter++; // increment counter
                }
            }

            break; // exit
        }

        // move to the next song
        headLL = headLL->nextSong;
    }

    // if not found, return -1
    if (found == 0) {
        return -1;
    }

    // return number of matching notes
    return counter;
}