#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int prec(char ch)
{
    switch (ch)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    default:
        return 0;
    }
}
void push(char st[], int *top, char val)
{
    if (*top == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    st[++(*top)] = val;
}
void pop(char st[], int *top)
{
    if (*top == -1)
    {
        printf("Underflow\n");
        return;
    }
    (*top)--;
}
char peek(char st[], int top)
{
    if (top == -1)
    {
        return -1;
    }
    return st[top];
}
int isEmpty(int top)
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    char st[MAX];
    char str[50] = "a*b+d-e/f";
    char ans[50] = "";
    int top = -1;
    int idx = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            ans[idx++] = str[i];
        }
        else
        {
            if (str[i] == ')')
            {
                while (peek(st, top) != '(')
                {
                    ans[idx++] = peek(st, top);
                    pop(st, &top);
                }
                pop(st, &top);
            }
            else if (str[i] == '(' || isEmpty(top) || prec(str[i]) > prec(peek(st, top)))
            {
                push(st, &top, str[i]);
            }
            else if (prec(str[i]) <= prec(peek(st, top)))
            {
                while (!isEmpty(top) && prec(str[i]) <= prec(peek(st, top)))
                {
                    ans[idx++] = peek(st, top);
                    pop(st, &top);
                }
                push(st, &top, str[i]);
            }
        }
    }
    while (!isEmpty(top))
    {
        ans[idx++] = peek(st, top);
        pop(st, &top);
    }
    printf("%s", ans);
    return 0;
}