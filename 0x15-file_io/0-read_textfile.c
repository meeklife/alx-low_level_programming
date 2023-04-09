#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 *  read_textfile - function that reads a text file and prints.
 * @filename: Name of the file.
 * @letters: Number of characters to read.
 * Return: Actual number of letters read, 0 if end of file.
 */
ssize_t read_textfile(const char *filename, size_t letters) {
    ssize_t num_read = 0;
    char *buffer = NULL;
    FILE *fp;

    if (filename == NULL) {
        return 0;
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    buffer = malloc(sizeof(char) * (letters + 1));
    if (buffer == NULL) {
        fclose(fp);
        return 0;
    }

    num_read = fread(buffer, sizeof(char), letters, fp);
    if (num_read == 0) {
        fclose(fp);
        free(buffer);
        return 0;
    }

    buffer[num_read] = '\0';
    printf("%s", buffer);

    fclose(fp);
    free(buffer);

    return num_read;
}

