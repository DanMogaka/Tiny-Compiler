// tests/test_token.c
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../include/token.h"

// Token create_token(TokenType type, const char *start, size_t len, int line, int col);

void test_create_token() {
    Token test_tok;
    test_tok.type = TOK_IDENTIFIER;
    test_tok.col = 1;
    test_tok.line = 1;
    test_tok.lexeme = "test";
    test_tok.length = 4;


    assert(strcmp(test_tok.lexeme, "test") == 0);
    assert(test_tok.type == TOK_IDENTIFIER);
    assert(test_tok.length == strlen("test"));
    assert(test_tok.line == 1);
    assert(test_tok.col == 1);
}

void test_token_type_to_string() {
    assert(strcmp(token_type_to_string(TOK_INT), "int") == 0);
    assert(strcmp(token_type_to_string(TOK_IDENTIFIER), "identifier") == 0);
    assert(strcmp(token_type_to_string(TOK_INT_LITERAL), "number") == 0);
    assert(strcmp(token_type_to_string(TOK_EOF), "eof") == 0);

    // Test invalid token
    assert(strcmp(token_type_to_string((TokenType)999), "unknown") == 0);
}


int main() {
    test_create_token();
    test_token_type_to_string();

    TokenList test_t_list;

    Token int_token = create_token(TOK_INT, "int", 3, 1, 1);
    Token int_token2 = create_token(TOK_ASSIGN, "=", 1, 1, 5);

    init_token_list(&test_t_list, 100);

    token_list_push(&test_t_list, int_token);
    token_list_push(&test_t_list, int_token2);

    free_token_list(&test_t_list);

    printf("All token tests passed!\n");
    return 0;
}

// Run test with these on command line.
// gcc -Iinclude tests/test_token.c src/token.c -o run_test_token
// ./run_test_token