#include <stdio.h>

int space_char(int);
void blank_count();
void blank_condense();
void replace_blanks_with_chars();

int main() {
    // blank_count();
    // blank_condense();
    replace_blanks_with_chars();
}

int space_char(int c) {
    return c == ' ' || c == '\t' || c == '\n';
}

void blank_count() {
    int c, space_count;

    space_count = 0;
    while((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n')
            ++space_count;
    printf("%d\n", space_count);
}

void blank_condense() {
    int c;
    while ((c = getchar()) != EOF) {
        if (space_char(c)) {
            putchar(' ');
            while(space_char(c))
                c = getchar();
                if (c == EOF)
                    break;
            putchar(c);
            continue;
        }
        putchar(c);
    }
}

void replace_blanks_with_chars() {
    int c;
    while ((c = getchar()) != EOF) {
        switch (c)
        {
        case '\t':
            putchar('\\');
            putchar('t');
            break;
        case '\\':
            putchar('\\');
            putchar('\\');
            break;
        case '\b':
            putchar('\\');
            putchar('b');
            break;
        default:
            putchar(c);
        }
    }
}