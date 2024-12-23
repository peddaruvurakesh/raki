#include <stdio.h>
#include <stdlib.h>

void cat(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int c;
    while ((c = fgetc(file)) != EOF) {
        if (fputc(c, stdout) == EOF) {
            perror("Error writing to stdout");
            fclose(file);
            return;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [file2 ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        cat(argv[i]);
    }

    return 0;
}

