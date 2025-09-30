#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/token.h"

#define INIT_TOKEN_LIST_MAX_CAP 25

// Function Prototypes
char *read_file(const char *PATH);

int main(void) {
    char *source = read_file("examples/test.c"); // Examples of c files in examples folder
    if (source) {
        printf("-----------------------------\n");
        printf("Source code:\n");
        printf("%s\n", source);

        TokenList test_t_list;
        init_token_list(&test_t_list, INIT_TOKEN_LIST_MAX_CAP);

        // Create and push token to token list
        Token t0 = create_token(TOK_CONST, "const", 3, 1, 1);
        token_list_push(&test_t_list, t0);

        // Retrieve token from token list
        Token t = test_t_list.data[0];
        printf("\nToken example -> %s : %s at line %i:%i\n", token_type_to_string(t.type),
            t.lexeme, t.line, t.col);
        printf("\n");

        free_token_list(&test_t_list);
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

/* 
    Run tests with these commands
     gcc src/compiler.c src/token.c -o compiler
     ./compiler
*/