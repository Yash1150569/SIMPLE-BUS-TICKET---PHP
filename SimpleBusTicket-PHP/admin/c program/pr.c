#include <stdio.h>
#include <ctype.h>

void count_characters(FILE *file, int *num_chars) {
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        (*num_chars)++;
    }
    fseek(file, 0, SEEK_SET); // Reset file pointer for next function
}

void count_words(FILE *file, int *num_words) {
    char ch;
    int in_word = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            (*num_words)++;
        }
    }
    fseek(file, 0, SEEK_SET); // Reset file pointer for next function
}

void count_whitespaces(FILE *file, int *num_whitespaces) {
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ') {
            (*num_whitespaces)++;
        }
    }
    fseek(file, 0, SEEK_SET); // Reset file pointer for next function
}

void count_newlines(FILE *file, int *num_newlines) {
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            (*num_newlines)++;
        }
    }
}

void print_file_contents(FILE *file) {
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fseek(file, 0, SEEK_SET); // Reset file pointer for next function
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int num_chars = 0, num_words = 0, num_whitespaces = 0, num_newlines = 0;

    // Print file contents
    printf("File contents:\n");
    print_file_contents(file);

    // Perform counts
    count_characters(file, &num_chars);
    count_words(file, &num_words);
    count_whitespaces(file, &num_whitespaces);
    count_newlines(file, &num_newlines);

    // Display counts
    printf("\nCharacters: %d, Words: %d, Whitespaces: %d, New lines: %d\n", num_chars, num_words, num_whitespaces, num_newlines);

    fclose(file);
    return 0;
}
