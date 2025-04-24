#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include "../include/given.h"


/* Task 1 */
int createPlayList(A3Song **headLL, char fileName[MAX_LENGTH]) {
    
    // open file  
    FILE *file = fopen(fileName, "r");
    
    // check if the file opened successfully
    if (file == NULL) {
        printf("Error opening file: %s\n", fileName);
        return -1;
    }
    
    // start timer for randomized notes and ids 
    srand(time(NULL));
    
    // declare variables  
    char line[300]; // read lines
    int counter = 0; // parse lines 
    char nameBuffer[MAX_LENGTH]; // buffer for song name 
    char tempNoteBuffer[21][NOTE_LENGTH]; // temp storage for notes 
    
    // skip header line
    fgets(line, sizeof(line), file);
    
    // read the first line 
    if (fgets(line, sizeof(line), file) == NULL) {
        printf("Error, unable to read file\n");
        fclose(file);
        return 0;
    }
    
    // do-while loop to process lines
    do {
        
        // declare variables for parsing 
        int linePos = 0;
        int nameIndex = 0;
        
        // clear nameBuffer 
        for (int i = 0; i < MAX_LENGTH; i++) { 
            nameBuffer[i] = '\0';
        }
        
        // reset note buffer 
        for (int i = 0; i < 21; i++) { // iterate each note 
            for (int j = 0; j < NOTE_LENGTH; j++) { // clear all characters in that note 
                tempNoteBuffer[i][j] = '\0';
            }
        }
        
        // extract characters until comma, newline or null is found
        while (line[linePos] != ',' && line[linePos] != '\n' && line[linePos] != '\0') {
            
            // copy to nameBuffer
            if (nameIndex < MAX_LENGTH - 1) {
                nameBuffer[nameIndex] = line[linePos]; // copy character to nameBuffer 
                nameIndex++; 
            }
            linePos++; // move to next character
        }
        
        // terminate name string 
        nameBuffer[nameIndex] = '\0';
        
        // skip comma after name if possible
        if (line[linePos] == ',') {
            linePos++;
        }
        
        // extract 21 notes from line and store them in tempNoteBuffer 
        for (int noteIndex = 0; noteIndex < 21; noteIndex++) {
            
            // declare variable to track position within note 
            int charIndex = 0;
            
            // extract characters until comma, newline or null is found
            while (line[linePos] != ',' && line[linePos] != '\n' && line[linePos] != '\0') {
                
                // copy into tempNoteBuffer 
                if (charIndex < NOTE_LENGTH - 1) {
                    tempNoteBuffer[noteIndex][charIndex] = line[linePos]; // copy character to tempNoteBuffer
                    charIndex++; // move to next character in note 
                }
                linePos++; // move to next character
                
            }
            
            // terminate note string 
            tempNoteBuffer[noteIndex][charIndex] = '\0';
            
            // skip comma after name if possible
            if (line[linePos] == ',') {
                linePos++;
            }
        }
        
        // dynamically allocate memory for new A3 song pointer 
        A3Song *newSong = malloc(sizeof(A3Song));
        
        // copy song name into pointer 
        strncpy(newSong->songName, nameBuffer, MAX_LENGTH);
        newSong->songName[MAX_LENGTH - 1] = '\0'; // null terminate string 
        
        // copy note from tempNoteBuffer into new pointer 
        for (int i = 0; i < 21; i++) {
            strncpy(newSong->songNotes[i], tempNoteBuffer[i], NOTE_LENGTH);
            newSong->songNotes[i][NOTE_LENGTH - 1] = '\0'; // null terminate string 
        }
        
        // generate random id for song between 1 and 1000 
        newSong->songId = rand() % 1000 + 1;
        
        // set nextSong pointer to NULL 
        newSong->nextSong = NULL;
        
        // if list empty, turn new song into head 
        if (*headLL == NULL) {
            *headLL = newSong;
        }
        
        // else find end of list and put new song there 
        else {
            A3Song *current = *headLL; // start at head
            
            // iterate through the list until last song 
            while (current->nextSong != NULL) {
                current = current->nextSong;
            }
        
            // add new song to end of list 
            current->nextSong = newSong;
        }
        
        // increment counter after adding song 
        counter++;
        
    } while (fgets(line, sizeof(line), file) != NULL); // continue while there are more lines
    
    // close file 
    fclose(file);
    
    // return total number of songs added to playlist
    return counter;
}