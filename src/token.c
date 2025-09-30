#include <stdio.h>
#include <stdlib.h>
#include "../include/token.h"

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

void init_token_list(TokenList *t_list, size_t list_capacity) {
    if (list_capacity == 0) {
        fprintf(stderr, "warning: Initial list length must be greater than 0. List capacity set to 1. \n");
        t_list->capacity = 1;
    } else {
        t_list->capacity = list_capacity;
    }
    t_list->data = malloc(sizeof(Token) * list_capacity);
    if (!t_list->data) {
        perror("malloc failed!");
        exit(1);
    }
    t_list->size = 0;
}

void token_list_push(TokenList *t_list, Token new_token) {
    // Doubling factor after of 0.75 full
    if (t_list->size >= t_list->capacity * 3 / 4) {
        t_list->capacity *= 2;

        Token *tmp = realloc(t_list->data, sizeof(Token) * t_list->capacity);
        if (!tmp) {
            perror("realloc failed");
            exit(1);
        }
        t_list->data = tmp;
    }
    t_list->data[t_list->size++] = new_token;
}

void free_token_list(TokenList *t_list) {
    free(t_list->data);
    t_list->data = NULL;
    t_list->size = 0;
    t_list->capacity = 0;
}

const char *token_type_to_string(TokenType t) {
    switch(t) {
        case TOK_INT:           return "int";
        case TOK_RETURN:        return "return";
        case TOK_CONST:         return "const";
        case TOK_IF:            return "if";
        case TOK_ELSE:          return "else";
        case TOK_WHILE:         return "while";
        case TOK_FOR:           return "for";
        case TOK_VOID:          return "void";

        case TOK_IDENTIFIER:    return "identifier";
        case TOK_INT_LITERAL:   return "int literal";
        case TOK_STRING_LITERAL:return "string literal";
        case TOK_CHAR_LITERAL:  return "char literal";

        case TOK_ADD:           return "+";
        case TOK_SUB:           return "-";
        case TOK_MUL:           return "*";
        case TOK_DIV:           return "/";
        case TOK_MOD:           return "%";
        case TOK_ASSIGN:        return "=";
        case TOK_EQ:            return "==";
        case TOK_NEQ:           return "!=";
        case TOK_LT:            return "<";
        case TOK_GT:            return ">";
        case TOK_LEQ:           return "<=";
        case TOK_GEQ:           return ">=";
        case TOK_AND:           return "&&";
        case TOK_OR:            return "||";
        case TOK_NOT:           return "!";

        case TOK_LPAREN:        return "(";
        case TOK_RPAREN:        return ")";
        case TOK_LBRACE:        return "{";
        case TOK_RBRACE:        return "}";
        case TOK_SEMICOLON:     return ";";
        case TOK_COMMA:         return ",";
        case TOK_LBRACKET:      return "[";
        case TOK_RBRACKET:      return "]";

        case TOK_EOF:           return "eof";
        default:                return "unknown";
    }
}