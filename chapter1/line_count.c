#include <stdio.h>

#define MAXLINE 1000
#define LONG_LINE 80
#define NEW_LINE 1
#define NON_NEW_LINE 0 

int get_line(char s[], int lim);
void count_long_lines();
void remove_white_space();
void reverse_line();

int main() {
    count_long_lines();
    remove_white_space();
    reverse_line();
    return 0;
}

void count_long_lines() {
    int count;
    char line[MAXLINE];

    count = 0;
    while ((count = get_line(line, MAXLINE)) > 0) {
        if (count > LONG_LINE)
            printf("%s", line);
    }
}

void remove_white_space() {
    int c, state;

    state = NEW_LINE;
    while ((c = getchar()) != EOF) {
        if (state == NEW_LINE && (c == '\t' || c == ' '))
            continue;
        if (c == '\n') {
            if (state == NEW_LINE)
                continue;
            state = NEW_LINE;
        }
        else {
            state = NON_NEW_LINE;
        }
        putchar(c);
    }
}

void reverse_line() {
    int count;
    char line[MAXLINE];

    count = 0;
    while ((count = get_line(line, MAXLINE)) > 0) {
        for (int i = count - 1; i >= 0; --i)
            putchar(line[i]);
    }
}

int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
