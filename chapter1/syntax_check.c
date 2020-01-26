#include <stdio.h>

#define FOUND 1
#define HARD_BREAK 2

int brace_count, parens_count, bracket_count;

int until_string_close(int break_char);
int skip_until_char(int break_char);
int skip_until_adjacent_chars(int c1, int c2);
void inspect(int c);
void check_syntax();

int main() {
    check_syntax();
    return 0;
}

void check_syntax() {
    int c, rc;

    while ((c = getchar()) != EOF) {
        if (c == '\'' || c == '"') {
            if (until_string_close(c) == HARD_BREAK)
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
        }
        else {
            inspect(c);
        }
    }
    if (brace_count == parens_count == bracket_count == 0)
        printf("Code syntax passed inspection\n");
    else
        printf("There were syntax errors\n");
}

int until_string_close(int break_char) {
    int c;
    
    while(1) {
        if ((c = getchar()) == EOF)
            return HARD_BREAK;
        if (c == '\\') {    // If a backslash in a string we have to handle the case of a quote
            if ((c = getchar()) == EOF)
                return HARD_BREAK;
            continue;
        }
        if (c == break_char)
            return FOUND;
    }
}

int skip_until_char(int break_char) {
    int c;

    while(1) {
        if ((c = getchar()) == break_char)
            return FOUND;
        if (c == EOF)
            return HARD_BREAK;
    }
}

int skip_until_adjacent_chars(int c1, int c2) {
    int c;

    while(1) {
        if (skip_until_char(c1) == HARD_BREAK)
            return HARD_BREAK;
        if ((c = getchar()) == EOF)
            return HARD_BREAK;
        if (c == c2)
            return FOUND;
    }
}

void inspect(int c) {
    if (c == '{')
        ++brace_count;
    else if (c == '}')
        --brace_count;
    else if (c == '(')
        ++parens_count;
    else if (c == ')')
        --parens_count;
    else if (c == '[')
        ++bracket_count;
    else if (c == ']')
        --bracket_count;
}
