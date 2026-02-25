/**
 * Book Stack Assignment
 * ---------------------
 * Complete this program by implementing the core stack operations for book management!
 * 
 * DO NOT change given function signatures or struct definitions.
 * Only fill in the code for the required stack functions marked with TODOs.
 */
#include <stdio.h>
#include "book_stack.h"

// === BOOK STACK OPERATIONS: IMPLEMENT THESE ===============================

/**
 * Creates a new, empty stack.
 * Returns a pointer to a new stack structure.
 */
book_stack_t* create_stack() {
    // TODO: Implement stack initialization
}
 
/**
 * Pushes a new book onto the stack.
 * Copies title/author strings using dynamic memory allocation.
 */
void push(book_stack_t* stack, const char* title, const char* author, int year, int pages) {
    // TODO: Implement push operation
}

/**
 * Peek at the top book of the stack (non-destructive).
 * Returns pointer to the top book, or NULL if empty.
 */
book_t* peek(book_stack_t* stack) {
    // TODO: Implement peek operation
}

/**
 * Pops/removes the top book from the stack.
 * Writes the removed book to 'output' if provided (caller must free title/author).
 * Returns 1 if successful, 0 if the stack was empty.
 */
int pop(book_stack_t* stack, book_t* output) {
    // TODO: Implement pop operation
}

/**
 * Frees all memory for a book (title and author fields), but not the struct itself.
 */
void clear_book(book_t* book) {
    // TODO: Free book title/author if non-null
}

/**
 * Prints book details.
 */
void print_book(const book_t* book) {
    if (book != NULL) {
        printf("\"%s\" by %s (%d) - %d pages\n", book->title, book->author, book->year, book->pages);
    }
}

/**
 * Prints all books in the stack from top to bottom.
 */
void print_stack(const book_stack_t* stack) {
    if (stack->size == 0) {
        printf("The stack is empty.\n");
        return;
    }
    
    printf("\nBook Stack (size: %d):\n", stack->size);
    printf("---------------------------\n");
    
    stack_node_t* current = stack->top;
    int position = 1;
    
    while (current != NULL) {
        printf("%d. ", position++);
        print_book(&current->book);
        current = current->next;
    }
    printf("---------------------------\n");
}

/**
 * Frees all dynamically allocated memory, destroys the stack.
 */
void destroy_stack(book_stack_t* stack) {
    // TODO: Implement memory clean-up for entire stack
}

/**
 * Finds and prints duplicate books.
 * Duplicate is defined as same title AND same author.
 */
void find_duplicate_books(book_stack_t* stack) {
    // TODO: Implement duplicate detection
}
