#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include "../include/given.h"


/* Task 8 */
void deletePlayList(A3Song **headLL) {
    
    // declare pointer variables 
    A3Song *current = *headLL; // current song 
    A3Song *temp; // temporary pointer to store song before deleting 
    
    // loop through entire playlist 
    while (current != NULL) {
        
        // save next song before deleting current 
        temp = current->nextSong;
        
        // free current song 
        free(current);
        
        // move to next song 
        current = temp;
    }

    // set head pointer to null after deleting 
    *headLL = NULL;
    
}