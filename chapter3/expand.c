#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]);
int fill_until(char start, char end, int ind, char s2[]);
int valid_char_range(char a, char b);

int main() {
    char a[100] = "Helloa-d\n0-40-5\nC-F\nF-A\n5-2\n----\na-C  0-F";
    char b[100];
    expand(a,b);
    printf("%s\n", b);
    return 0;
}

void expand(char s1[], char s2[]) {
    int c,i,j,first;
    i = j = 1;
    first = s1[0];
    s2[0] = first;
    if (first == '\0')
        return;   

    // Continue until no dashes in case the string starts with a sequence of dashes
    for(; s1[i] == '-'; ++i,++j)
        s2[i] = '-';

    for(; (c = s1[i]) != '\0'; ++i) {
        for(;(c = s1[i]) != '\0' && c != '-'; ++i, ++j)
            s2[j] = c;
        
        if (c == '\0') {
            s2[j] = c;
            break;
        }
        else if (c == '-') {
            if (s1[i+1] == '\0') {
                s2[j] = c;
                s2[j+1] = '\0';
                break;
            }
            j = fill_until(s1[i-1], s1[i+1], j, s2);
        }
    }
}

int fill_until(char start, char end, int ind, char s2[]) {
    int c;
    c = start;
    if (!valid_char_range(start, end)) {
        s2[ind++] = '-';
        s2[ind] = end;
        return ind;
    }

    int increment = start <= end ? 1 : -1;
    c += increment;
    for (; c != end + increment; ++ind, c += increment)
        s2[ind] = c;
    return --ind;
}

int valid_char_range(char a, char b) {
    int c, both_lower, both_upper, both_digit;
    both_lower = islower(a) && islower(b);
    both_upper = isupper(a) && isupper(b);
    both_digit = isdigit(a) && isdigit(b);
    return both_lower || both_upper || both_digit;
}