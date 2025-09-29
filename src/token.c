#include <stdio.h>
#include "token.h"

//void free_token(Token *t);

Token create_token(TokenType type, const char *start, size_t len, int line, int col) {
    Token tok;
    tok.lexeme = start; 
    tok.length = len;
    tok.type = type;
    tok.line = line;
    tok.col = col;
    return tok;
} 

const char *token_type_to_string(TokenType t) {
    switch(t) {
        case TOK_INT:           return "int";
        case TOK_RETURN:        return "return";
        case TOK_CONST:         return "const";
        case TOK_IDENTIFIER:    return "identifier";
        case TOK_INT_LITERAL:   return "number";
        case TOK_ADD:           return "+";
        case TOK_SUB:           return "-";
        case TOK_MUL:           return "*";
        case TOK_DIV:           return "/";
        case TOK_ASSIGN:        return "=";
        case TOK_LPAREN:        return "(";
        case TOK_RPAREN:        return ")";
        case TOK_LBRACE:        return "{";
        case TOK_RBRACE:        return "}";
        case TOK_SEMICOLON:     return ";";
        case TOK_COMMA:         return ",";
        case TOK_EOF:           return "eof";
        default:                return "unknown";
    }
}