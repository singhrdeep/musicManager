#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include "../include/given.h"


/* Task 7 */
int deleteASongGivenId(A3Song **headLL, int givenSongId) { 
    
    // declare pointer variables 
    A3Song *current = *headLL; // current song 
    A3Song *prev = NULL; // song before the current 
    
    // check if the playlist is empty 
    if (*headLL == NULL) {
        printf("Playlist is empty.\n");
        return -1;
    }
    
    // iterate through playlist to find song 
    while (current != NULL) {
        
        // check if current song id matches the song to delete 
        if (current->songId == givenSongId) {
            
            // if deleting head of playlist 
            if (prev == NULL) {
                *headLL = current->nextSong; // update head to next
            }
            
            else {
                prev->nextSong = current->nextSong; // skip current
            }
            
            // free memory 
            free(current);
            
            // return 1
            return 1; 
        }
        
        // move to next song 
        prev = current;
        current = current->nextSong;
    }
    
    // song not found 
    return -1;
    
    }