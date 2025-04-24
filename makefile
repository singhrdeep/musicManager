bin/musicalLL: main.o createPlayList.o addNewSong.o playPlayList.o playSongGivenId.o playSongGivenName.o countNotesInASong.o deleteASongGivenId.o deletePlayList.o
	gcc -Wall -std=c99 mainA3.o createPlayList.o addNewSong.o playPlayList.o playSongGivenId.o playSongGivenName.o countNotesInASong.o deleteASongGivenId.o deletePlayList.o -o bin/musicalLL

mainA3.o: src/main.c include/given.h
	gcc -Wall -std=c99 -c src/main.c

createPlayList.o: src/createPlayList.c include/given.h
	gcc -Wall -std=c99 -c src/createPlayList.c

addNewSong.o: src/addNewSong.c include/given.h
	gcc -Wall -std=c99 -c src/addNewSong.c

playPlayList.o: src/playPlayList.c include/given.h
	gcc -Wall -std=c99 -c src/playPlayList.c

playSongGivenId.o: src/playSongGivenId.c include/given.h
	gcc -Wall -std=c99 -c src/playSongGivenId.c

playSongGivenName.o: src/playSongGivenName.c include/given.h
	gcc -Wall -std=c99 -c src/playSongGivenName.c

countNotesInASong.o: src/countNotesInASong.c include/given.h
	gcc -Wall -std=c99 -c src/countNotesInASong.c

deleteASongGivenId.o: src/deleteASongGivenId.c include/given.h
	gcc -Wall -std=c99 -c src/deleteASongGivenId.c

deletePlayList.o: src/deletePlayList.c include/given.h
	gcc -Wall -std=c99 -c src/deletePlayList.c

clean:
	rm -f *.o bin/musicalLL

