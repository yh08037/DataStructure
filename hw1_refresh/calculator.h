#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "ll_stack.h"
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LEN 300

typedef enum {
    LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
    PLUS = '+', MINUS = '-', TIMES = '*', DIVIDE = '/',
    SPACE = ' '
} SYMBOL;

char* getString(void);

bool isValidParenthesis(char* string);
bool isValidCharacter(char* string);

bool isOperator(char chr);
bool isNumber(char chr);
bool isValidExpression(char* string);

int getPriority(char chr);
char* Infix2Postfix(char* string);

bool isOperatorString(char* subString);
double evaluate(double op1, double op2, char oprator);
double evaluatePostfix(char* string);

#endif
