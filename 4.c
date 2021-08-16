#include <stdio.h>
#include <stdlib.h>
//可以输出100以内的奇数阶魔方阵
void init(int M[][100], int n);

void output(int M[][100], int n);

int main(void)
{
    int n;

    printf("Please enter an odd number as the dimension of the matrix:\n");

    scanf("%d", &n);

    if (n % 2 == 0)
    {
        printf("Please check your input, and make sure it is an odd number.\n");
        exit(EXIT_FAILURE);
    }
    else if (n % 2 == 1)
    {
        printf("Good! It's an odd number.\n");
    }

    int cube[100][100];

    init(cube, n);

    output(cube, n);

    return 0;
}

void init(int M[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M[i][j] = 0;
        }
    }

    int i = 0;
    int j = (n - 1) / 2;

    int num;

    for (num = 1; num <= n * n; num++)
    {
        if (i < 0 && j < 0 || M[i][j] != 0)
        {
            i += 2;
            j++;
        }
        M[i--][j--] = num;
        if (i < 0 && j >= 0)
        {
            i = n - 1;
        }
        if (j < 0 && i >= 0)
        {
            j = n - 1;
        }
        if (i < 0 && j < 0)
        {
            i = 1;
            j = 0;
        }
    }
}

void output(int M[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", M[i][j]);
        }
        printf("\n");
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += M[i][0];
    }
    printf("The sum of each row, column and two diagonal lines is %d.", sum);
}
