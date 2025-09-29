#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
char *read_file(const char *PATH);

int main(void) {
    char *source = read_file("examples/test.c"); // Examples of c files in examples folder
    if (source) {
        printf("%s\n", source);
        free(source);
    }
    return 0;
}

// Utility Functions
char *read_file(const char *PATH) {
    // Make sure to free dynamic memory with malloc(insert_name)
    FILE *fp = fopen(PATH, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }
    printf("File \'%s\' opened successfully!\n", PATH);

    if (fseek(fp, 0, SEEK_END) != 0) {
        perror("fseek");
        fclose(fp);
        return NULL;
    }

    long size = ftell(fp);
    if (size < 0 ) {
        perror("ftell");
        fclose(fp);
        return NULL;
    }
    rewind(fp);

    char *buffer = malloc(size + 1);
    if (!buffer) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    size_t read_size = fread(buffer, 1, size, fp);
    if (read_size != (size_t)size) {
        perror("fread");
        free(buffer);
        fclose(fp);
        return NULL;
    }

    buffer[size] = '\0';
    fclose(fp);
    return buffer;
}