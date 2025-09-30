#ifndef TOKEN_H
#define TOKEN_H
#include <stddef.h>
typedef enum {
    // Keywords
    TOK_INT,
    TOK_RETURN,
    TOK_CONST,
    TOK_IF,
    TOK_ELSE,
    TOK_WHILE,
    TOK_FOR,
    TOK_VOID,

    // Identifiers + literals
    TOK_IDENTIFIER,
    TOK_INT_LITERAL,
    TOK_STRING_LITERAL,
    TOK_CHAR_LITERAL,

    // Operators
    TOK_ADD,       // +
    TOK_SUB,       // -
    TOK_MUL,       // *
    TOK_DIV,       // /
    TOK_MOD,       // %
    TOK_ASSIGN,    // =
    TOK_EQ,        // ==
    TOK_NEQ,       // !=
    TOK_LT,        // <
    TOK_GT,        // >
    TOK_LEQ,       // <=
    TOK_GEQ,       // >=
    TOK_AND,       // &&
    TOK_OR,        // ||
    TOK_NOT,       // !

    // Delimiters
    TOK_LPAREN,    // (
    TOK_RPAREN,    // )
    TOK_LBRACE,    // {
    TOK_RBRACE,    // }
    TOK_SEMICOLON, // ;
    TOK_COMMA,     // ,
    TOK_LBRACKET,  // [
    TOK_RBRACKET,  // ]
    
    // End of file
    TOK_EOF
} TokenType;

typedef struct {
    TokenType type;
    const char *lexeme;
    size_t length;
    int line;
    int col;
} Token;

typedef struct {
    Token *data;
    size_t size;
    size_t capacity;
} TokenList;

Token create_token(TokenType t, const char *start, size_t len, int line, int col);

void init_token_list(TokenList *t_list, size_t list_capacity);
void token_list_push(TokenList *t_list, Token token);
void free_token_list(TokenList *t_list);

const char *token_type_to_string(TokenType t);

#endif