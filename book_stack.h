#ifndef BOOK_STACK_H
#define BOOK_STACK_H

// Structure for a book with dynamically allocated memory for title and author
typedef struct {
    char* title;       // Dynamically allocated string
    char* author;      // Dynamically allocated string
    int year;
    int pages;
} book_t;

// Structure for a stack node
typedef struct stack_node {
    book_t book;                 // Book data
    struct stack_node* next;    // Pointer to the next node
} stack_node_t;

// Structure for the stack itself
typedef struct {
    stack_node_t* top;    // Pointer to the top of the stack
    int size;          // Current size of the stack
} book_stack_t;

/**
 * Creates a new, empty stack.
 * Returns a pointer to a new stack structure.
 */
book_stack_t* create_stack();
/**
 * Pushes a new book onto the stack.
 * Copies title/author strings using dynamic memory allocation.
 */
void push(book_stack_t* stack, const char* title, const char* author, int year, int pages);

/**
 * Peek at the top book of the stack (non-destructive).
 * Returns pointer to the top book, or NULL if empty.
 */
book_t* peek(book_stack_t* stack);

/**
 * Pops/removes the top book from the stack.
 * Writes the removed book to 'output' if provided (caller must free title/author).
 * Returns 1 if successful, 0 if the stack was empty.
 */
int pop(book_stack_t* stack, book_t* output);

/**
 * Frees all memory for a book (title and author fields), but not the struct itself.
 */
void clear_book(book_t* book);

/**
 * Prints book details.
 */
void print_book(const book_t* book);

/**
 * Prints all books in the stack from top to bottom.
 */
void print_stack(const book_stack_t* stack);

/**
 * Frees all dynamically allocated memory, destroys the stack.
 */
void destroy_stack(book_stack_t* stack);

/**
 * Finds and prints duplicate books.
 * Duplicate is defined as same title AND same author.
 */
void find_duplicate_books(book_stack_t* stack);

#endif