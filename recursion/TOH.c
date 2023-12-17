#include <stdio.h>
#include <stdlib.h>
long int c = 0;
void toh(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("from %c to %c\n", from, to);
        c++;
        return;
    }
    toh(n - 1, from, aux, to);
    toh(1, from, to, aux);
    toh(n - 1, aux, to, from);
}
int main()
{
    int n = 3;
    toh(n, 'f', 't', 'a');
    printf("%d", c);
    return 0;
}