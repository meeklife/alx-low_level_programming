#include "main.h"
/**
 * append_text_to_file - Function that appends text at the end of a file.
 * @filename: Name of file.
 * @text_content: String to write.
 * Return: 1
 */

int append_text_to_file(const char *filename, char *text_content) {
    int fd, write_size = 0;
    struct stat st;
    
    if (filename == NULL) {
        return -1;
    }

    if (text_content == NULL) {
        return 1;
    }

    if (stat(filename, &st) == -1) {
        return -1;
    }

    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1) {
        return -1;
    }

    while (text_content[write_size] != '\0') {
        write_size++;
    }

    write_size = write(fd, text_content, write_size);
    if (write_size == -1) {
        close(fd);
        return -1;
    }

    close(fd);
    return 1;
}

