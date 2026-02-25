# Book Stack

In this section, you will complete the code to create and manage a stack of books, where each book includes a title, author, year, and page count. You will implement stack operations such as push, pop, peek, and duplicate detection. You will practice working with structs, pointers, dynamic memory, and linked lists.

Starter code is provided:

- `book_stack.h` - Struct definitions plus function declarations
- `book_stack.c` - Where you'll implement stack operations (**your main work!**)
- `main.c` - Interactive CLI menu (Provided, no modification needed)

## Getting Started

### Requirements

- C compiler
- Readline library (for main.c menu, *available* on the ecelinux server and many Linux/macOS systems).  

### Assignment Tasks

Fork and clone this repository.

Implement all stack functions in `book_stack.c`:

- [ ] `create_stack`
- [ ] `push`
- [ ] `peek`
- [ ] `pop`
- [ ] `clear_book`
- [ ] `destroy_stack`
- [ ] `find_duplicate_books`

See the TODOs and docstrings in `book_stack.c` for full specifications.

**DO NOT** change function signatures or struct definitions.  
**DO NOT** modify `main.c`.

## Compiling and Running

**Compile:**

```bash
gcc -Wall -Werror -c book_stack.c
gcc -Wall -Werror -c main.c
gcc book_stack.o main.o -o book_stack -lreadline
```

**Run:**

```bash
./book_stack
```

**Sample Menu Interaction:**

```
==== Library Book Stack Menu ====
1. Add (push) a book
2. Remove (pop) top book
3. Show top book
4. Print all books
5. Find duplicate books
6. Exit
Choose an option [1-6]: 1
Enter book title: The Hobbit
Enter book author: J.R.R. Tolkien
Enter publication year: 1937
Enter page count: 310

==== Library Book Stack Menu ====
1. Add (push) a book
2. Remove (pop) top book
3. Show top book
4. Print all books
5. Find duplicate books
6. Exit
Choose an option [1-6]: 1
Enter book title: Dune
Enter book author: Frank Herbert
Enter publication year: 1965
Enter page count: 412

==== Library Book Stack Menu ====
1. Add (push) a book
2. Remove (pop) top book
3. Show top book
4. Print all books
5. Find duplicate books
6. Exit
Choose an option [1-6]: 4

Book Stack (size: 2):
---------------------------
1. "Dune" by Frank Herbert (1965) - 412 pages
2. "The Hobbit" by J.R.R. Tolkien (1937) - 310 pages
---------------------------

==== Library Book Stack Menu ====
Choose an option [1-6]: 5
No duplicate books found.

==== Library Book Stack Menu ====
Choose an option [1-6]: 1
Enter book title: Dune
Enter book author: Frank Herbert
Enter publication year: 1965
Enter page count: 412
Added book: "Dune" to the stack

==== Library Book Stack Menu ====
1. Add (push) a book
2. Remove (pop) top book
3. Show top book
4. Print all books
5. Find duplicate books
6. Exit
Choose an option [1-6]: 4

Book Stack (size: 3):
---------------------------
1. "Dune" by Frank Herbert (1965) - 412 pages
2. "Dune" by Frank Herbert (1965) - 412 pages
3. "The Hobbit" by J.R.R. Tolkien (1937) - 310 pages
---------------------------

==== Library Book Stack Menu ====
Choose an option [1-6]: 5

Searching for duplicate books...
Found duplicate: "Dune" by Frank Herbert (1970) - 412 pages

==== Library Book Stack Menu ====
1. Add (push) a book
2. Remove (pop) top book
3. Show top book
4. Print all books
5. Find duplicate books
6. Exit
Choose an option [1-6]: 2
Removed top book: "Dune" by Frank Herbert (1965) - 412 pages

==== Library Book Stack Menu ====
1. Add (push) a book
2. Remove (pop) top book
3. Show top book
4. Print all books
5. Find duplicate books
6. Exit
Choose an option [1-6]: 4

Book Stack (size: 2):
---------------------------
1. "Dune" by Frank Herbert (1965) - 412 pages
2. "The Hobbit" by J.R.R. Tolkien (1937) - 310 pages
---------------------------

==== Library Book Stack Menu ====
1. Add (push) a book
2. Remove (pop) top book
3. Show top book
4. Print all books
5. Find duplicate books
6. Exit
Choose an option [1-6]: 5
No duplicate books found.

==== Library Book Stack Menu ====
Choose an option [1-6]: 6
Program exited.
```

## Time Complexity Discussion

At the end of this assignment, we will have an **in-class discussion of the (Big O) time complexity** for each stack operation you implemented. Consider both best- and worst-case scenarios, and think about how your implementation impacts these runtimes.
