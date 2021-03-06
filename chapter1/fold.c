#include <stdio.h>

#define FOLD_LIMIT  120
#define FOLD_BREAKPOINT 100
#define LINE_LIMIT 1000
#define TRUE  1
#define FALSE 0

int line_index = 0;
int last_word_index = 0;
char trailing[FOLD_LIMIT - FOLD_BREAKPOINT];

void fold_lines();
int space_char(int c);
void state_reset();
int in_fold_threshold(int index);
void print_until_last_space(int last_char);
void split_large_word(int last_char);

int main() {
    fold_lines();
    return 0; 
}

void fold_lines() {
    int c;

    while((c = getchar()) != EOF) {
        if (space_char(c) == TRUE)
            last_word_index = line_index;
        if (in_fold_threshold(line_index) == TRUE) {
            trailing[line_index - FOLD_BREAKPOINT] = c;
            if (c == '\n') {
                for (int j = 0; j < (line_index - FOLD_BREAKPOINT); ++j)
                    putchar(trailing[j]);
                putchar(c);
                state_reset();
            }
        }
        else if (line_index == FOLD_LIMIT) {
            if (last_word_index > FOLD_BREAKPOINT) {
                print_until_last_space(c);
                continue;
            }
            split_large_word(c);
        }
        else {
            putchar(c);
            if (c == '\n')
                state_reset();
        }
        ++line_index;
    }
}

int space_char(int c) {
    if (c == ' ' || c == '\t')
        return TRUE;
    return FALSE;
}

void state_reset() {
    line_index = last_word_index = 0;
    char trailing[FOLD_LIMIT - FOLD_BREAKPOINT];
}

int in_fold_threshold(int index) {
    if (index >= FOLD_BREAKPOINT && index < FOLD_LIMIT)
        return TRUE;
    return FALSE;
}

void print_until_last_space(int last_char) {
    for (int j = 0; j < (FOLD_LIMIT - FOLD_BREAKPOINT); ++j) {
        if (j == (last_word_index - FOLD_BREAKPOINT)) {
            putchar('\n');
            line_index = last_word_index = 0;
            continue;
        }
        putchar(trailing[j]);
        ++line_index;
    }
    putchar(last_char);
    state_reset();
}

void split_large_word(int last_char) {    
    for (int j = 0; j < (FOLD_LIMIT - FOLD_BREAKPOINT); ++j)
        putchar(trailing[j]);
    putchar('-');
    putchar('\n');
    putchar(last_char);
    putchar(trailing[FOLD_LIMIT - 1]);
    state_reset();
}