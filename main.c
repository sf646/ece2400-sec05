#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "book_stack.h"

// ============= Input helpers (do NOT edit) =============
bool get_string(const char *prompt, char **dest) {
    char *input = readline(prompt);
    
    if (!input) {
        return false;
    }
    
    if (!dest) {
        free(input);
        return false;
    }
    
    *dest = input;
    return true;
}

bool get_integer(const char *prompt, long *dest) {
    char *string = NULL;
    if (!get_string(prompt, &string)) {
        return false;
    }
    
    char *end = NULL;
    long integer = strtol(string, &end, 0);
    // strtol failed
    if (end == string || (end && *end != '\0')) {
        free(string);
        return false;
    }
    
    if (!dest) {
        free(string);
        return false;
    }
    
    free(string);
    *dest = integer;
    return true;
}
 
bool get_integer_between(const char *prompt, long start, long stop, long *dest) {
    long integer;
    if (!get_integer(prompt, &integer)) {
        return false;
    }
    
    if (integer < start || integer >= stop) {
        return false;
    }
    
    if (!dest) {
        return false;
    }
    
    *dest = integer;
    return true;
}

// ============== Main Function: DO NOT MODIFY ============
int main() {
    book_stack_t* library_stack = create_stack();
    int running = 1;

    while (running) {
        printf("\n==== Library Book Stack Menu ====\n");
        printf("1. Add (push) a book\n");
        printf("2. Remove (pop) top book\n");
        printf("3. Show top book\n");
        printf("4. Print all books\n");
        printf("5. Find duplicate books\n");
        printf("6. Exit\n");

        long choice = 0;
        if (!get_integer_between("Choose an option [1-6]: ", 1, 7, &choice)) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        switch (choice) {
            case 1: { // Add a book
                char *title = NULL, *author = NULL;
                long year = 0, pages = 0;

                if (!get_string("Enter book title: ", &title) || strlen(title) == 0) {
                    printf("Error: Title cannot be empty.\n");
                    free(title);
                    break;
                }

                if (!get_string("Enter book author: ", &author) || strlen(author) == 0) {
                    printf("Error: Author cannot be empty.\n");
                    free(title);
                    free(author);
                    break;
                }

                if (!get_integer("Enter publication year: ", &year)) {
                    printf("Invalid year.\n");
                    free(title);
                    free(author);
                    break;
                }

                if (!get_integer("Enter page count: ", &pages) || pages <= 0) {
                    printf("Invalid number of pages.\n");
                    free(title);
                    free(author);
                    break;
                }

                push(library_stack, title, author, (int)year, (int)pages);

                // push makes its own copies, so free input
                free(title);
                free(author);
                break;
            }

            case 2: { // Remove top book
                if (library_stack->size == 0) {
                    printf("Stack is empty. Nothing to remove.\n");
                    break;
                }
                book_t removed = {0};
                if (pop(library_stack, &removed)) {
                    printf("Removed top book: ");
                    print_book(&removed);
                    clear_book(&removed);
                }
                break;
            }

            case 3: { // Show top book
                book_t* top = peek(library_stack);
                if (!top) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Top book: ");
                    print_book(top);
                }
                break;
            }

            case 4: // Print all books
                print_stack(library_stack);
                break;

            case 5: // Find duplicates
                find_duplicate_books(library_stack);
                break;

            case 6: // Exit
                running = 0;
                break;

            default:
                printf("Unknown option.\n");
        }
    }

    destroy_stack(library_stack);
    printf("Program exited.\n");
    return 0;
}