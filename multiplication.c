#include <stdio.h>
#include <monty.h>

int main(void)
{
    int num1, num2, result;

    printf("Enter two digits: ");
    scanf("%1d %1d", &num1, &num2);

    result = num1 * num2;

    printf("The result is: %d\n", result);

    return 0;
}
