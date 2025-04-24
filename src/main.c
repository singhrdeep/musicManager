#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "../include/given.h"


int main() {

	// declare variables for task 1
	int returnVal; // return values from functions
	char fileName[MAX_LENGTH]; // for filename 

	// declare variables for task 2
	int beginOrEnd; // stores if song is added to beginning or end

	// declare variables for task 4
	int songId; // stores input for song id

	// declare variables for task 5
	char songName[MAX_LENGTH]; // store input for song name
	int length; // store song name

	// declare variables for task 6
	char note[NOTE_LENGTH]; // stores note
	int counter; // counter for notes

	// declare linked list pointer for playlist
	A3Song *headLL = NULL;

	// declare variables for menu
	char input[50]; // for input
	int choice = 0; // menu choice

	// start timer for song id
	srand(time(NULL));

	// do-while loop for menu
	do {

		// display menu
		printf("======================================================\n");
		printf("1. Create a new playlist\n");
		printf("2. Add a new song to an existing playlist\n");
		printf("3. Play all songs in the given playlist\n");
		printf("4. Play a song from the playlist, given its id\n");
		printf("5. Play a song from the playlist, given its name\n");
		printf("6. Count the number of occurrences of a note in a given song\n");
		printf("7. Delete a song from the playlist, given its id\n");
		printf("8. Delete the entire playlist\n");
		printf("9. Exit\n");
		printf("======================================================\n");
		printf("Enter your choice: ");

		// read user input
		fgets(input, sizeof(input), stdin);
        
		// convert to int
		if (sscanf(input, "%d", &choice) != 1) {

			// if invalid tell user
			printf("\nInvalid Type\n\n");
			getchar(); // clear newLine
			choice = 0; // reset choice so loop continues
			continue;
		}

		// menu range
		if (choice < 1 || choice > 9) {
			printf("\nInvalid Choice\n\n");
			getchar(); // clear newLine
			continue;
		}

		// switch case to handle options
		switch (choice) {

		// task 1: create playlist
		case 1:
		    // load playlist from csv 
			strcpy(fileName, "MusicalTunes.csv");
			returnVal = createPlayList(&headLL, fileName);
			
			printf("\nNumber of songs in the playlist: %d\n\n", returnVal);
			
			break;

		// task 2: add song
		case 2:
		    // ask for value
			printf("\nEnter the value for beginOrEnd: ");
			scanf("%d", &beginOrEnd); 
			getchar(); // clear newline 

            // check if value is valid
			if (beginOrEnd != 1 && beginOrEnd != 2) {
				
				printf("\ninvalid beginOrEnd value entered.\n\n");
				
				break;
			}

            // call addNewSong
			if (addNewSong(&headLL, beginOrEnd)) {
			    // if song was added at beginning
				if (beginOrEnd == 1) {
					printf("\nSong added at the beginning\n\n");
				}
                // if song was added at end
				else {
					printf("\nSong added at the end\n\n");
				}
			}

            // if program couldnt add song
			else {
				printf("\nFailed to add song.\n\n");
			}
			
			break;

		// task 3: play playlist
		case 3:
		    // newline
			printf("\n");
			
			// call playPlaylist and print all songs
			playPlayList(headLL);
			
			printf("\n"); // newline
			
			break;

		// task 4: play by id
		case 4:

            // ask user and read id 
			printf("\nEnter the id of the song you want to play: ");
			scanf("%d", &songId); // read song id 
			getchar(); // clear newLine

            // call function and store into returnVal
			returnVal = playSongGivenId(headLL, songId);

            // if not found 
			if (returnVal == -1) {
				printf("\nNo song found\n\n");
			}

            // if found 
			else {
				printf("\n");
			}

			break;

		// task 5: play by name
		case 5:
			
			// ask user for input 
			printf("\nEnter the name of the song you want to play: ");
			fgets(songName, MAX_LENGTH, stdin);

            // remove newline from song name
			length = strlen(songName);
			
			// remove newline
			if (length > 0 && songName[length - 1] == '\n') {
				songName[length - 1] = '\0';
			}

            // call function 
			returnVal = playSongGivenName(headLL, songName);
			
			// if not found
			if (returnVal == -1) {
				printf("\nNo song found\n\n");
			} 
			
			// if found
			else {
				printf("\n");
			}
			
			break;
			
			// task 6: count note
            case 6:
                
                // ask user for input 
                printf("\nEnter the id of the song you want to count the notes in: ");
                scanf("%d", &songId);
                getchar(); // clear newline

                // ask user for input
                printf("Enter the note you want to count: ");
                fgets(note, NOTE_LENGTH, stdin);
                
                // remove newLine fro note
                length = strlen(note);
                
                // remove newline
                if (length > 0 && note[length - 1] == '\n') {
                    note[length - 1] = '\0';
                }

                // call countNotesInASong and store into count
                counter = countNotesInASong(headLL, songId, note);
                
                // if song not found
                if (counter == -1) {
                    printf("\nSong not found\n\n");
                } 
                
                // else print result
                else {
                    printf("\nNumber of times the note appears: %d\n\n", counter);
                }
                
                break;
                
            // task 7: delete by id
            case 7:
                
                // ask user for input
                printf("\nEnter the id of the song you want to delete: ");
                scanf("%d", &songId); // read song id 
                getchar(); // clear newLine
                
                // call deleteASongGivenId and store output
                returnVal = deleteASongGivenId(&headLL, songId);
                
                // if not found
                if (returnVal == -1) {
                    printf("\nSong not found\n\n");
                } 
                
                // if found
                else {
                    printf("\nSong Deleted\n\n");
                }
                
                break;
                
            // task 8: delete all
            case 8:
                // call deletePlayList function
                deletePlayList(&headLL);
                
                printf("\nDeleting Playlist\n\n");
                
                break;

            // task 9: exit
            case 9:
                
                // exit program
                printf("\nExiting the program\n\n");
                
                break;
		}
		
	} while (choice != 9); // loop until user chooses exit
	
	return 0; // return
}
