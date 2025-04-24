#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include "../include/given.h"


/* Task 2 */
bool addNewSong(A3Song **headLL, int beginOrEnd) {

	// declare variables
	int length;  // store length of song name

	// validate input
	if (beginOrEnd != 1 && beginOrEnd != 2) {
		printf("Please select either 1 or 2");
		return false; // exit program
	}

	// dynamically allocate memory for new song pointer
	A3Song *newSong = malloc(sizeof(A3Song));

	// check if malloc was successful
	if (newSong == NULL) {
		printf("Memory allocation failed.\n");
		return false;
	}

	// clear song name before input
	for (int i = 0; i < MAX_LENGTH; i++) {
		newSong->songName[i] = '\0'; // clear name buffer
	}

	// prompt user to enter song name
	printf("Enter the song name: ");
	fgets(newSong->songName, MAX_LENGTH, stdin); // read line into songName

	// remove newline from song name if present
	length = strlen(newSong->songName); // find length of song name

	// check if last character is newline
	if (length > 0 && newSong->songName[length - 1] == '\n') {
		// replace newline character with null
		newSong->songName[length - 1] = '\0';
	}

	// declare array for the notes to generate
	char *notes[] = {"do", "re", "mi", "fa", "sol", "la", "ti"};

	// for loop to read and display notes
	for (int i = 0; i < 21; i++) {
		// randomize notes
		int randomIndex; // declare variable
		randomIndex = rand() % 7; // randomize

		// copy random note into songNotes[i]
		strncpy(newSong->songNotes[i], notes[randomIndex], NOTE_LENGTH);

		// terminate note string
		newSong->songNotes[i][NOTE_LENGTH - 1] = '\0';
	}

	// generate random id for song between 1 and 1000
	newSong->songId = rand() % 1000 + 1;

	// set next pointer to NULL temporarily
	newSong->nextSong = NULL;

	// check if new song should be at beginning
	if (beginOrEnd == 1) {
		// point new song to current head
		newSong->nextSong = *headLL;

		// update head to be new song
		*headLL = newSong;
		printf("Song ID: %d\n", newSong->songId); // print new generated song id

		// print generated notes
		printf("Notes: ");
		for (int i = 0; i < 21; i++) {
			printf("%s", newSong->songNotes[i]);

			// add dot between notes
			if (i != 20) {
				printf(".");
			}
		}
		printf("\n");
	}

	// check if new song should be at the end
	else if (beginOrEnd == 2) {

		// if list is empty, song becomes head
		if (*headLL == NULL) {
			*headLL = newSong;
		}

		else {
			// iterate through list to find last song
			A3Song *current = *headLL;

			// iterate until next is NULL
			while (current->nextSong != NULL) {
				current = current->nextSong;
			}

			// add new song at end
			current->nextSong = newSong;
			printf("Song ID: %d\n", newSong->songId); // print new generated song id

			// print generated notes
			printf("Notes: ");
			for (int i = 0; i < 21; i++) {
				printf("%s", newSong->songNotes[i]);

				// add dot between notes
				if (i != 20) {
					printf(".");
				}
			}
		}
	}

	// return success
	return true;
}