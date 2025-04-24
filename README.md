
# musicalLL – Linked List-Based Music Playlist Manager in C

`musicalLL` is a command-line program built in C that allows users to manage musical playlists using linked lists. It supports operations such as adding, playing, searching, and deleting songs — all managed dynamically in memory. Each song includes an auto-generated ID, a name, and a fixed-length sequence of musical notes.

This project was developed at the **University of Guelph** to explore dynamic memory management and linked list data structures in a real-world context.

---

## 📦 Features

- 🎵 Create and load playlists from CSV files
- ➕ Add new songs to the beginning or end of a playlist
- ▶️ Play songs by ID or name
- 🔁 Display the entire playlist with all notes
- 🔍 Count occurrences of specific notes
- ❌ Delete individual songs or the full playlist
- 🧭 Menu-driven interface with clear options

---

## 🛠 Requirements

- GCC compiler (C99 standard)
- Make utility

---

## 📂 Folder Structure

```
A3/
├── bin/           # Compiled executable (musicalLL)
├── include/       # Header files (given.h)
├── src/           # Source files (one for each function, plus main)
└── makefile       # Build instructions
```

---

## ⚙️ Build Instructions

To compile the project:

```bash
make
```

To clean object files and executables:

```bash
make clean
```

---

## ▶️ Run Instructions

To run the program:

```bash
./bin/musicalLL
```

The menu will guide you through creating and managing your musical playlist.

---

## 🧪 Functionality

- **Create Playlist:** Load songs from a CSV file into a linked list
- **Add Song:** Dynamically create a song with a unique ID and random notes
- **Play Playlist or Songs:** Display song info based on ID or name
- **Delete Songs:** Remove one song or the whole playlist from memory
- **Count Notes:** Search a song for how often a note appears

---

## 📄 License

This project is provided as-is for educational use. No license is currently specified.
