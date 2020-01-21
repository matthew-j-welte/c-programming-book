#include <stdio.h>

#define PREVIOUS_SPACE 1
#define NON_PREVIOUS_SPACE 0

void detab(int tab_count);
void entab(int space_count);

int main() {
    entab(4);
}

void detab(int tab_count) {
    int c, tabs;
    tabs = tab_count;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (int i = 0; i < tabs; ++i)
                putchar(' ');
            tabs = tab_count;
            continue;
        }
        else if (c == ' ') {
            if (tabs == 1)
                tabs = tab_count;
            else
                --tabs;
        }
        putchar(c);
    }
}

void entab(int space_count) {
    int c, spaces, state;
    spaces = 0;

    state = NON_PREVIOUS_SPACE;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            state = PREVIOUS_SPACE;
            ++spaces;
            if (spaces % space_count == 0) {
                state = NON_PREVIOUS_SPACE;
                putchar('\t');
            }
            continue;
        }
        else if (state == PREVIOUS_SPACE)
            putchar('\t');
        spaces = 0;
        state = NON_PREVIOUS_SPACE;
        putchar(c);
    }
}