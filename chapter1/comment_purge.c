#include <stdio.h>

#define FOUND 1
#define HARD_BREAK 2

void remove_comments();
int output_until_string_close(int break_char);
int skip_until_char(int c);
int skip_until_adjacent_chars(int c1, int c2);

int main() {
    remove_comments();
    return 0;
}

void remove_comments() {
    int c, rc;

    rc = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\'' || c == '"') {
            putchar(c);
            if (output_until_string_close(c) == HARD_BREAK)
                break;
            continue;
        }
        else if (c == '/') {
            c = getchar();
            if (c == '/') {
                rc = skip_until_char('\n');
                continue;
            }
            else if (c == '*') {
                rc = skip_until_adjacent_chars('*', '/');   // Used for multine block comments
                continue;
            }
            if (rc == HARD_BREAK)
                break;
            putchar('/');
        }
        putchar(c);
    }
}

/*
    Ignores comment purge rules while inside a quoted block 
*/
int output_until_string_close(int break_char) {
    int c;
    
    while(1) {
        c = getchar();
        if (c == EOF)
            return HARD_BREAK;
        putchar(c);
        if (c == '\\') {    // If a backslash in a string we have to handle the case of a quote
            c = getchar();
            if (c == EOF)
                return HARD_BREAK;
            putchar(c);
            continue;
        }
        if (c == break_char)
            return FOUND;
    }
}

/*
    Skip outputting chars until a certain char is reached
*/
int skip_until_char(int break_char) {
    int c;

    while(1) {
        c = getchar();
        if (c == break_char) {
            if (c == '\n')
                putchar('\n');
            return FOUND;
        }
        if (c == EOF)
            return HARD_BREAK;
    }
}

/*
    Skip outputting chars until two adjacent characters are reached
*/
int skip_until_adjacent_chars(int c1, int c2) {
    int c;

    while(1) {
        if (skip_until_char(c1) == HARD_BREAK)
            return HARD_BREAK;
        c = getchar();
        if (c == EOF)
            return HARD_BREAK;
        if (c == c2)
            return FOUND;
    }
}