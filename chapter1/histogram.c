#include <stdio.h>
#include <string.h>

#define IN  1
#define OUT 0

void horizontal_histogram();
void vertical_histogram(int arr_size, char*, void x_axis_printer(int), void count_rule(int, int*));
void count_word_lengths(int, int*);
void count_chars(int, int*);
void print_vertical_histogram();
void word_length_x_axis_printer(int index);
void char_count_x_axis_printer(int index);
void space_out(int);

int main() {
    // horizontal_histogram();
    // vertical_histogram(20, "Word Length", count_word_lengths);
    vertical_histogram(26, "Characters", char_count_x_axis_printer, count_chars);
    return 0;
}

void space_out(int spaces) {
    for (int x = 0; x < spaces; ++x)
        putchar(' ');
}

void horizontal_histogram() {
    int upper_lim = 20;
    int arr[20];
    count_word_lengths(upper_lim, arr);

    for (int i = 0; i <= upper_lim; ++i) {
        putchar('\n');
        printf("%2d ", i);
        for (int j = 0; j < arr[i]; j++)
            putchar('X');
    }
    putchar('\n');
}

void vertical_histogram(int arr_size, char* x_axis_label, void x_axis_printer(int), void count_rule(int, int*)) {
    int greatest_count, x_axis_str_len;
    int arr[arr_size];
    
    x_axis_str_len = strlen(x_axis_label);
    count_rule(arr_size, arr);
    greatest_count = arr[0];
    for (int i = 1; i < arr_size; ++i) {
        if (arr[i] > greatest_count)
            greatest_count = arr[i];
    }
    
    putchar('\n');
    for (int i = greatest_count; i > 0; --i) {
        space_out(x_axis_str_len);
        printf("%3d ", i);
        for (int j = 0; j < arr_size; j++) {
            if (arr[j] >= i)
                printf("| X ");
            else
                printf("|   ");
        }
        putchar('\n');
    }
    printf("%s", x_axis_label);
    space_out(4);
    for (int j = 0; j < arr_size; j++) {
        putchar('|');
        x_axis_printer(j);
    }
    putchar('\n');
}

void word_length_x_axis_printer(int index) {
    printf("%3d", index);
}

void char_count_x_axis_printer(int index) {
    printf("%3c", index + 65);
}

void count_word_lengths(int upper_lim, int* arr) {
    int c, char_count, state;
    char_count = 0;

    for (int i = 0; i <= upper_lim; ++i)
        arr[i] = 0;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN)
                ++arr[char_count];
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            char_count = 1;
        }
        else
            ++char_count;
    }
    if (state == IN)
        ++arr[char_count];
}

void count_chars(int upper_lim, int* arr) {
    int c;

    for (int i = 0; i <= upper_lim; ++i)
        arr[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= 97 && c <= 122)
            ++arr[c - 97];
        else if (c >= 65 && c <= 90)
            ++arr[c - 65];
    }
}