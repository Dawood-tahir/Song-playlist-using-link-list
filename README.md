# 📚 Library & Music Playlist Systems

This repository contains two C++ console-based applications demonstrating **doubly linked list** implementations for real-world scenarios: a **Library Management System** and a **Music Playlist App**.

---

## 1️⃣ Library Management System

**Description:**
This program manages a collection of books using a doubly linked list. Each book has:

* `ISBN` (unique identifier)
* `Title`
* `Author`
* `Publication Year`

**Features:**

* Add a new book (ensures ISBN uniqueness)
* Search for a book by ISBN or title
* Update book details
* Display all books and total count

**Data Structure:** Doubly linked list for efficient forward/backward traversal.

---

### Example Usage:

```text
=======Welcome TO OUR Library========
1. To insert
2. To search
3. To update
4. To Display
5. Exit
Enter Your choice: 1
Enter Author, Title, Year, ISBN(Unique) of the Book
J.K.Rowling HarryPotter 2007 12345
```

---

## 2️⃣ Music Playlist App

**Description:**
A simple music playlist manager using a doubly linked list. Each song has:

* `ID` (unique)
* `Title`
* `Artist Name`
* `Duration` (in seconds)

**Features:**

* Insert a new song
* Search by artist or title
* Update song details
* Display all songs and total count
* Play next song
* Play previous song

**Data Structure:** Doubly linked list for efficient next/previous navigation.

---

### Example Usage:

```text
======WELCOME TO OUR MUSIC APP=======
1. To insert
2. To Search
3. To update
4. To Display
5. Play Next
6. Play previous
Enter your choice: 1
Enter ID: 1
Enter Artist Name: Arijit Singh
Enter Song Title: Tum Hi Ho
Enter Duration (secs): 240
```

---

## 💻 Project Details

* Language: **C++**
* Concepts Used:

  * Doubly Linked List
  * Pointers
  * Class & Object
  * Input/Output Streams
* Compiler: Any standard C++ compiler (GCC, Code::Blocks, Dev-C++, VS Code)

---

## 📝 Notes

* Unique identifiers (`ISBN` for books, `ID` for songs) are enforced.
* Traversal allows both forward and backward operations.
* Projects are console-based and meant for **learning DSA & OOP** concepts.

---

## 🔧 How to Run

1. Clone the repository:

```bash
git clone https://github.com/yourusername/Library-Music-DSA.git
```

2. Navigate to the folder and compile:

```bash
g++ library.cpp -o library
g++ music.cpp -o music
```

3. Run the program:

```bash
./library
./music
```

---

## ✅ Learning Outcomes

* Implementing and managing **doubly linked lists**
* Practicing **class design and object management**
* Handling **user input and data validation**
* Understanding **real-world scenarios** like libraries and music playlists


