#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 100
//max number of the element is MAXN
//saddle point

void output(int M[][MAXN], int, int);

void input(int M[][MAXN], int, int);

int saddle(int M[][MAXN], int, int, int *, int *);

int main(void)
{
    int row, col;
    int M[MAXN][MAXN];
    int x = 0, y = 0;
    printf("Please enter the row and the column of the Matrix.\n");

    scanf("%d %d", &row, &col);

    input(M, row, col);

    output(M, row, col);

    int saddle_point_flag = saddle(M, row, col, &x, &y);

    if (saddle_point_flag != 0)
    {
        printf("\nThe saddle point exists, and the number of the saddle point is %d.\n", saddle_point_flag);
    }
    else if (saddle_point_flag == 0)
    {
        printf("\nThe saddle point does not exist.\n");
    }

    return 0;
}

void input(int M[][MAXN], int row, int col)
{
    printf("please enter the element of the matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }
}

int saddle(int M[][MAXN], int row, int col, int *x, int *y)
{
    int min_row[row], max_col[col];
    int flag = 0;

    for (int i = 0; i < col; i++)
    {
        max_col[i] = M[0][i];
        for (int j = 0; j < row; j++)
        {
            if (max_col[i] < M[j][i])
            {
                max_col[i] = M[j][i];
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        min_row[i] = M[i][0];
        for (int j = 0; j < col; j++)
        {
            if (min_row[i] > M[i][j])
            {
                min_row[i] = M[i][j];
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (min_row[i] == max_col[j])
            {
                flag += 1;
                printf("\nThe (%d,%d) element of the matrix is the saddle point.\n", i + 1, j + 1);

                printf("The value of the saddle point is %d.\n", M[i][j]);
            }
        }
    }
    return flag;
}

void output(int M[][MAXN], int row, int col)
{
    printf("\nThe matrix is:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }
}
/*
以下给出部分测试数据
/*

/*
3 3
2 2 3
1 1 8
1 1 9
*/
/*
4 4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
*/
/*
3 6
1 5 6 7 8 1
6 2 5 9 1 6
3 6 5 8 1 9
*/