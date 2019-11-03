#include "calculator.h"
#include <stdio.h>


char* getString(void) {
  char* inputString;
  int bufferSize = sizeof(char) * MAX_INPUT_LEN;

  if ( !(inputString = (char*)malloc(bufferSize)) )
    return NULL;

  memset(inputString, 0, bufferSize);

  scanf("%[^\n]", inputString);

  return inputString;
}


bool isValidCharaters(char* string) {
  int index = -1;
  char chr;

  while ( (chr = string[++index]) != '\0' ) {
    if (
      !isOperator(chr) && !isNumber(chr) && chr != LEFT_PARENTHESIS
      && chr != RIGHT_PARENTHESIS && chr != SPACE
    ) {
      return false;
    }
  }

  return true;
}


bool isValidParenthesis(char* string) {
  int index = -1;
  int paren = 0;

  while ( string[++index] != '\0' ) {
    if ( string[index] == LEFT_PARENTHESIS )
      paren++;
    else {
      if ( string[index] == RIGHT_PARENTHESIS )
        if ( paren == 0 )
          return false;
        else
          paren--;
    }
  }
  if ( paren != 0 )
    return false;

  return true;
}


bool isOperator(char chr) {
  return chr == PLUS || chr == MINUS || chr == TIMES || chr == DIVIDE;
}


bool isNumber(char chr) {
  return ('0' <= chr && chr <= '9');
}


bool isValidExpression(char* string) {
  int index = -1;
  bool isContinue = false;
  char past = PLUS;
  char curr;


  while ( (curr = string[++index]) != '\0' ) {
    if ( curr == SPACE )
      continue;

    isContinue = (past == string[index-1]);                     // 53

    if (
      (isNumber(past) && curr==LEFT_PARENTHESIS)                // 2 (
      || (past==LEFT_PARENTHESIS && isOperator(curr))           // ( +

      || (past==RIGHT_PARENTHESIS && isNumber(curr))            // ) 3
      || (isOperator(past) && curr==RIGHT_PARENTHESIS)          // + )

      || (!isContinue) && (isNumber(past) && isNumber(curr))    // 2 3
      || (isOperator(past) && isOperator(curr))                 // + -

      || (past==LEFT_PARENTHESIS && curr==RIGHT_PARENTHESIS)    // ( )
      || (past==RIGHT_PARENTHESIS && curr==LEFT_PARENTHESIS)    // ) (
    ) {
      return false;
    }

    past = curr;
  }

  return true;
}


int getPriority(char chr) {
  switch (chr) {
    case TIMES:    case DIVIDE:
      return 2;
    case PLUS:     case MINUS:
  return 1;
    case LEFT_PARENTHESIS:
      return 0;
    default:
      return -1;
  }
}

char* Infix2Postfix(char* string) {
  char* postfix;
  Stack* stack;
  char data;
  char prev = PLUS;
  char* ptr;
  int index = -1;
  char temp[3] = {0};

  if ( !(postfix = (char*) calloc(MAX_INPUT_LEN, sizeof(char))) )
    return NULL;

  if ( !(stack = CreateStack(MAX_INPUT_LEN)) )
    return NULL;

  while ( (data = string[++index]) != '\0' ) {

    if ( isNumber(data) ) {
      temp[0] = data;
      temp[1] = isNumber(string[index+1]) ? '\0' : SPACE;
      strcat(postfix, temp);
    }

    else if ( data == LEFT_PARENTHESIS ) {
      ptr = (char*)malloc(sizeof(char));
      *ptr = data;
      Push(stack, ptr);
    }

    else if ( isOperator(data) ) {
      ptr = (char*)Top(stack);
      while ( !IsEmptyStack(stack) && (getPriority(data) <= getPriority(*ptr)) ) {
        temp[0] = *(char*)Pop(stack);
        temp[1] = SPACE;
        strcat(postfix, temp);
        ptr = (char*)Top(stack);
      }
      ptr = (char*)malloc(sizeof(char));
      *ptr = data;
      Push(stack, ptr);
    }

    else if ( data == RIGHT_PARENTHESIS ) {
      data = *(char*)Top(stack);
      while ( data != LEFT_PARENTHESIS ) {
        temp[0] = *(char*)Pop(stack);
        temp[1] = SPACE;
        strcat(postfix, temp);
        data = *(char*)Top(stack);
      }
      Pop(stack);
    }

    else {
      continue;
    }
  }

  while ( !IsEmptyStack(stack) ) {
    temp[0] = *(char*)Pop(stack);
    strcat(postfix, temp);
  }

  free(ptr);
  DestroyStack(stack);

  return postfix;
}


bool isOperatorString(char* subString) {
  return isOperator(subString[0]) && subString[1] == '\0';
}

double evaluate(double op1, double op2, char operator) {
    switch ( operator ) {
      case PLUS:    return op1 + op2;
      case MINUS:   return op1 - op2;
      case TIMES:   return op1 * op2;
      case DIVIDE:  return op1 / op2;
    }
}


double evaluatePostfix(char* string) {
  char* token = strtok(string, " ");
  Stack* stack = CreateStack(MAX_INPUT_LEN);
  double* operand;
  double *op1, *op2;

  while ( token != NULL ) {
    if ( !isOperatorString(token) ) {
      operand = (double*)malloc(sizeof(double));
      *operand = atof(token);
      Push(stack, operand);
    }
    else {
      op2 = (double*)Pop(stack);
      op1 = (double*)Pop(stack);
      operand = (double*)malloc(sizeof(double));
      *operand = evaluate(*op1, *op2, token[0]);
      Push(stack, operand);
    }
    token = strtok(NULL, " ");
  }

  return *(double*)Pop(stack);
}
