#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include "../include/given.h"


/* Task 3 */
void playPlayList(A3Song *headLL) {
    
    // check if playlist is empty 
    if (headLL == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    
    // print header 
    printf("Playing the playlist..\n");
    
    // iterate through list and print each song 
    while (headLL != NULL) {
        
        // print song id 
        printf("Song ID: %d\n", headLL->songId);
        
        // print song name
        printf("Song Name: %s\n", headLL->songName);
        
        // print notes 
        printf("Notes:\n");
        
        // iterate and print the notes 
        for (int i = 0; i < 21; i++) {
            // print the note 
            printf("%s", headLL->songNotes[i]);
            
            // print dot after note 
            if (i != 20) {
                printf(".");
            }
        }
        
        // newLine
        printf("\n");
        
        // move to next song 
        headLL = headLL->nextSong;
        
    }

}