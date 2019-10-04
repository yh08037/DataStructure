#ifndef CALCULATOR_H
#define CALCULATOR_H

// #include "arr_stack.h"
#include "ll_stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_EXPRESSION_LEN 100

typedef enum {
    LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
    PLUS = '+', MINUS = '-', MULTIPLY = '*', DIVIDE = '/',
    SPACE = ' ', OPERAND
} SYMBOL;

void GetExpression(char* Expression);
bool IsValidParenthesis(char* Expression);
bool IsNumber(char chr);
int GetPriority(char Operator, bool InStack);
bool IsPrior(char OperatorInStack, char OperatorInToken);
int GetNextToken(char* Expression, char* Token, int* type);
char* CharToString(char chr);
void GetPostfix(char* InfixExpression, char* PostfixExpression);
double Calculate(char* PostfixExpression);


#endif
