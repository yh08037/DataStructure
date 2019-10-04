#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  char* string;
  char* expression;
  int len_expression;
  bool validity;
  double result;

  string = getString();

  if ( validity = isValidExpression(string) ) {
    printf("validity : %d\n", validity);
    expression = Infix2Postfix(string);
    printf("postfix : %s\n", expression);
    result = evaluatePostfix(expression);
    printf("result : %lf\n", result);
  }
  else {
    printf("invalid expression.\n");
  }

  return 0;
}
