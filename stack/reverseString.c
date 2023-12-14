#include <stdio.h>
#define MAX 100

void push(char st[], int *top, char ch)
{
    if (*top == MAX - 1)
    {
        return;
    }
    st[++(*top)] = ch;
}
char pop(char st[], int *top)
{
    if (*top == -1)
    {
        return '\0';
    }
    return st[(*top)--];
}
int isEmpty(int top)
{
    return top == -1;
}
void reverseString(char str[])
{
    char stack[MAX];
    int top = -1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        push(stack, &top, str[i]);
    }
    int j = 0;
    while (!isEmpty(top))
    {
        str[j++] = pop(stack, &top);
    }
    str[j] = '\0';
}
int main()
{

    char str[MAX];
    printf("Enter String : ");
    scanf("%[^\n]s", str);
    reverseString(str);
    printf("Reverse string : ");
    printf("%s", str);
}
