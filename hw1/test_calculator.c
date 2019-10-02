#include "calculator.h"

int main() {
    char InfixExpression[MAX_EXPRESSION_LEN];
    char PostfixExpression[MAX_EXPRESSION_LEN];

    double result = 0.0;

    memset(InfixExpression, 0, sizeof(InfixExpression));
    memset(PostfixExpression, 0, sizeof(PostfixExpression));

    GetExpression(InfixExpression);

    printf("%s\n", InfixExpression);

    if ( !IsValidParenthesis(InfixExpression) ) {
        printf("Error: Invalid parenthesis. Program terminates.\n");
        return -1;
    }

    GetPostfix(InfixExpression, PostfixExpression);

    printf("%s\n", PostfixExpression);

    result = Calculate(PostfixExpression);

    printf("%lf\n", result);

    return 0;
}
