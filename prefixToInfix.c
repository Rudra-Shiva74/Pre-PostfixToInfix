#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char Stack[MAX][MAX];
int Top = -1;
void push(char *x)
{
    strcpy(Stack[++Top], x);
}
char *pop()
{
    return Stack[Top--];
}
int main()
{
    char Exp[MAX], Temp[2], op[2] = {')', '\0'}, cl[2] = {'(', '\0'};
    int i = 0, j = 0;
    printf("Enter Your Prefix Expression : ");
    gets(Exp);
    strcpy(Exp, strrev(Exp));
    while (Exp[i] != '\0')
    {
        char exp[MAX] = {'\0'}, op1[MAX] = {'\0'}, op2[MAX] = {'\0'};
        Temp[0] = Exp[i];
        Temp[1] = '\0';
        if (isalnum(Temp[0]))
        {
            push(Temp);
        }
        else if (Temp[0] == '+' || Temp[0] == '-' || Temp[0] == '*' || Temp[0] == '/' || Temp[0] == '^')
        {
            strcpy(op2, pop());
            strcpy(op1, pop());
            strcat(exp, op);
            strcat(exp, op1);
            strcat(exp, Temp);
            strcat(exp, op2);
            strcat(exp, cl);
            push(exp);
        }
        else
        {
            printf("Invalid Arithmetic expression!\n");
            exit(0);
        }
        i++;
    }
    printf("Your Infix Expression is : ");
    puts(strrev(Stack[0]));
}