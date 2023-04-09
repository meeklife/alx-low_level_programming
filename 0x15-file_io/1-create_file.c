#include "main.h"
/**
 *  create_file - a function that creates a file
 *
 * @filename: name of file to create
 * @text_content: string to write to file
 *
 * Return: 1 on success OR -1 on faliure
*/
int create_file(const char *filename, char *text_content) {
    int fd, write_size = 0;
    mode_t mode = S_IRUSR | S_IWUSR;
    
    if (filename == NULL) {
        return -1;
    }

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
    if (fd == -1) {
        return -1;
    }

    if (text_content != NULL) {
        while (text_content[write_size] != '\0') {
            write_size++;
        }

        write_size = write(fd, text_content, write_size);
        if (write_size == -1) {
            close(fd);
            return -1;
        }
    }

    close(fd);
    return 1;
}

