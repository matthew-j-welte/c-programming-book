#include <stdio.h>

#define IN  1
#define OUT 0

void count();
void word_per_line();

int main() {
    count();
    // word_per_line();
    return 0;
}

void count() {
    int c, num_lines, num_words, num_chars, state;
    
    state = OUT;
    num_lines = num_words = num_chars = 0;

    while ((c = getchar()) != EOF) {
        ++num_chars;
        if (c == '\n')
            ++num_lines;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++num_words;
        }
    }
    printf("\n%d %d %d\n", num_lines, num_words, num_chars);
}

void word_per_line() {
    int c, state;
    
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else {
            if (state == OUT) {
                state = IN;
                putchar('\n');
            }
            putchar(c);
        }
    }
}