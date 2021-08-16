#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXN 100
//栈内优先级
int ISP_Func(char);

//栈外优先级
int ICP_Func(char);

void convert_post(char *);

int main(void)
{
    char input[MAXN];
    char *s = input;
    printf("Please enter a nifix expression.\n");
    gets(s);
    strcat(s, "#");
    printf("The corresponding suffix expression is:\n");
    convert_post(s);
    return 0;
}

//栈内优先级
int ISP_Func(char i)
{
    int ISP = 1;
    switch (i)
    {
    case '+':
    case '-':
        ISP = 1;
        break;
    case '*':
    case '%':
    case '/':
        ISP = 2;
        break;
    case '^':
        ISP = 3;
        break;
    case '(':
        ISP = 0;
        break;
    case ')':
        ISP = 0;
        break;
    default:
        ISP = 0;
        break;
    }
    return ISP;
}

//栈外优先级
int ICP_Func(char i)
{
    int ICP = 1;
    switch (i)
    {
    case '+':
    case '-':
        ICP = 1;
        break;
    case '*':
    case '%':
    case '/':
        ICP = 2;
        break;
    case '^':
        ICP = 4;
        break;
    case '(':
        ICP = 5;
        break;
    case ')':
        ICP = 0;
        break;
    default:
        ICP = 0;
        break;
    }
    return ICP;
}

void convert_post(char *expression)
{
    char STACK[MAXN];
    STACK[0] = '#';
    int top = 0;

    char character;
    int i = 0;
    do
    {
        character = expression[i];
        switch (character)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
        case '(':
        {
            while (ISP_Func(STACK[top]) >= ICP_Func(character))
            {
                printf("%c", STACK[top--]);
            }
            STACK[++top] = character;
            break;
        }
        case ')':
        {
            while (STACK[top] != '(')
            {
                printf("%c", STACK[top]);
                top--;
            }
            top--;
            break;
        }
        case '#':
        {
            while (top > 0)
            {
                printf("%c", STACK[top--]);
            }
            break;
        }
        default:
            printf("%c", character);
            break;
        }
        i++;
    } while (character != '#');
}

/*
A+(B-C/D)*E
ABCD/-E*+

A/B^C+D
ABC^/D+
*/
