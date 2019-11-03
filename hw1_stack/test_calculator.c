#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  char* string;
  char* expression;
  double result;

  printf("Input Conditions\n");
  printf(" * Non-negative integer only.\n");
  printf(" * Available operators : +, -, *, /, (, )\n");
  printf(" * You CANNOT omit * operator.\n");
  printf(" * You CANNOT use unary operator -.\n\n");

  printf("Input : ");

  if ( !(string = getString()) ) {
    printf("Input buffer allocation failed. Program terminates.\n");
    return -1;
  }

  if ( !isValidCharaters(string) ) {
    printf("Invalid charater in expression. Program terminates.\n");
    return -2;
  }

  if ( !isValidParenthesis(string) ) {
    printf("Invalid parenthesis. Program terminates.\n");
    return -3;
  }

  if ( !isValidExpression(string) ) {
    printf("Invalid expression. Program terminates.\n");
    return -4;
  }

  if ( !(expression = Infix2Postfix(string)) ) {
    printf("Stack alloction falied in Infix2Postfix(). Program terminates.\n");
    return -5;
  }

  printf("postfix : %s\n", expression);

  result = evaluatePostfix(expression);
  printf("result : %lf\n", result);


  return 0;
}
