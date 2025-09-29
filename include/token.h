#ifndef TOKEN_H
#define TOKEN_H
#include <stddef.h>

/*
    Support for this basic c program

    int main() {
        const a = 1;
        const b = 2;
        return a + b;
    }

*/

typedef enum {
    // Types
    TOK_INT,
    TOK_FLOAT,
    TOK_CONST,

    // Operators
    TOK_ADD,
    TOK_SUB,
    TOK_DIV,
    TOK_MUL,
    
    TOK_SEMICOLON,
    TOK_COMMA,
    TOK_RETURN,
    TOK_IDENTIFIER,
    TOK_ASSIGN,

    // Brackets
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_LBRACE,
    TOK_RBRACE,
    TOK_INT_LITERAL,

    // Misc
    TOK_EOF,
    TOK_UNKNOWN,
} TokenType;

typedef struct {
    TokenType type;
    const char *lexeme;
    size_t length;
    int line;
    int col;
} Token;

Token make_token(TokenType t, const char *start, size_t len, int line, int col);
const char *token_type_to_string(TokenType t);

#endif