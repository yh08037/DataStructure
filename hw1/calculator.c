#include "calculator.h"

char NUMBER[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };


void GetExpression(char* expression) {
    scanf("%[^\n]", expression);
}


bool IsValidParenthesis(char* Expression) {
    int index = 0;
    char* item;
    char tmp;

    Stack* pStack;
    pStack = CreateStack(MAX_EXPRESSION_LEN);

    while ( (tmp = Expression[index++]) != '\0' ) {
        if ( tmp == LEFT_PARENTHESIS )
            Push(pStack, tmp);
        else if ( tmp == RIGHT_PARENTHESIS ) {
            if (IsEmptyStack(pStack))
                return  false;
            else
                Pop(pStack);
        }
    }

    if ( !IsEmptyStack(pStack) )
        return false;

    DestroyStack(pStack);
    return true;
}


bool IsNumber(char chr) {
    int i = 0;
    int len = sizeof(NUMBER);

    for (i = 0; i < len; i++) {
        if (chr == NUMBER[i])
        return true;
    }

    return false;
}


int GetPriority(char Operator, bool InStack) {
    int Priority = -1;

    switch ( Operator ) {
        case LEFT_PARENTHESIS:
            if (InStack)
                Priority = 3;
            else
                Priority = 0;
            break;

        case MULTIPLY:
        case DIVIDE:
            Priority = 1;
            break;

        case PLUS:
        case MINUS:
            Priority = 2;
            break;
    }

    return Priority;
}


bool IsPrior(char OperatorInStack, char OperatorInToken) {
    return GetPriority(OperatorInStack, true) > GetPriority(OperatorInToken, false);
}


int GetNextToken(char* Expression, char* Token, int* Type) {
    int i = 0;

    for (i = 0; Expression[i] != 0; i++) {
        Token[i] = Expression[i];

        if ( IsNumber(Expression[i]) ) {
            *Type = OPERAND;

            if ( !IsNumber(Expression[i+1]) )
                break;
        }
        else {
            *Type = Expression[i];
            break;
        }
    }

    Token[++i] = '\0';
    return i;
}


char* CharToString(char chr) {
    char* str = (char*)malloc(sizeof(char)*2);
    sprintf(str, "%c", chr);

    return str;
}


void GetPostfix(char* InfixExpression, char* PostfixExpression) {
    Stack* pStack;

    char Token[32];
    int Type = -1;
    int Position = 0;
    int Length = strlen(InfixExpression);

    pStack = CreateStack(MAX_EXPRESSION_LEN);

    while (Position < Length) {
        Position += GetNextToken(&InfixExpression[Position], Token, &Type);

        if (Type == SPACE) continue;

        if ( Type == OPERAND ) {
            strcat(PostfixExpression, Token);
            strcat(PostfixExpression, " ");
        }
        else if (Type == RIGHT_PARENTHESIS) {
            while ( !IsEmptyStack(pStack) ) {
                char* Popped = CharToString(Pop(pStack));

                if ( Popped[0] != LEFT_PARENTHESIS )
                    strcat(PostfixExpression, Popped);
            }
        }
        else {
            while ( !IsEmptyStack(pStack) &&
                    !IsPrior(Top(pStack), Token[0])) {
                char* Popped = CharToString(Pop(pStack));

                if ( Popped[0] != LEFT_PARENTHESIS )
                    strcat(PostfixExpression, Popped);
            }

            Push(pStack, Token[0]);
        }
    }

    while ( !IsEmptyStack(pStack) ) {
        char* Popped = CharToString(Pop(pStack));

        if (Popped[0] != LEFT_PARENTHESIS)
            strcat(PostfixExpression, Popped);
    }
}


double Calculate(char* PostfixExpression) {
    Stack* pStack;

    double Result = 0.0;
    char Token[32];
    int Type = -1;
    int Read = 0;
    int Length = strlen(PostfixExpression);

    pStack = CreateStack(MAX_EXPRESSION_LEN);

    while ( Read < Length ) {
        Read += GetNextToken(&PostfixExpression[Read], Token, &Type);

        // printf("%c, %s, %c\n", PostfixExpression[Read], Token, Type);

        if ( Type == SPACE )
            continue;

        if ( Type == OPERAND )
            Push(pStack, Token[0]);

        else {
            char ResultString[32];
            double Operand1, Operand2, tmp;

            Operand2 = (double) (Pop(pStack) - '0');
            Operand1 = (double) (Pop(pStack) - '0');

            // printf("%lf, %lf\n", Operand1, Operand2);

            switch ( Type ) {
                case PLUS: tmp = Operand1 + Operand2; break;
                case MINUS: tmp = Operand1 - Operand2; break;
                case MULTIPLY: tmp = Operand1 * Operand2; break;
                case DIVIDE: tmp = Operand1 / Operand2; break;
            }

            Push(pStack, (int)tmp+'0');
        }
    }


    Result = (double) (Pop(pStack)-'0');

    // DestroyStack(pStack);

    return Result;
}
