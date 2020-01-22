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
void handle_space_chars(int c);
void state_reset();
int in_fold_threshold(int index);

int main() {
    fold_lines();
    return 0; 
}

void fold_lines() {
    int c;
    char trailing[FOLD_LIMIT - FOLD_BREAKPOINT];

    while((c = getchar()) != EOF) {
        handle_space_chars(c);
        if (in_fold_threshold(line_index) == TRUE)
            trailing[line_index] = c;
        else if (line_index == FOLD_LIMIT) {
            if (last_word_index > FOLD_BREAKPOINT) {
                int j = 0;
                for (j; j < (FOLD_LIMIT - FOLD_BREAKPOINT); ++j)
                    if (j == last_word_index)
                        putchar('\n');    
                    putchar(trailing[j]);
                state_reset();
            }
        }
        else {
            putchar(c);
            line_index++;
        }
    }
}

void handle_space_chars(int c) {
    if (c == ' ' || '\t')
        last_word_index = line_index;
    else if (c == '\n')
        state_reset();
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