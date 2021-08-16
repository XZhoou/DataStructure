#include <stdio.h>
#include <stdlib.h>

void add(int A[][3], int B[][3], int C[][3]); //A和B应该是具有相同行数和列数的

void output(int M[][3]);

void input(int M[][3]);

int main(void)
{
    printf("Input the first line of Matrix(A):\n");
    int lines, col, items1, items2;
    scanf("%d %d %d", &lines, &col, &items1);

    int elems1 = items1 + 1;
    int A[elems1][3];
    A[0][0] = lines;
    A[0][1] = col;
    A[0][2] = items1;
    printf("Input the element of Matrix(A):\n");
    input(A);

    printf("Input the first line of Matrix(B):\n");
    scanf("%d %d %d", &lines, &col, &items2);
    int elems2 = items2 + 1;
    int B[elems2][3];
    B[0][0] = lines;
    B[0][1] = col;
    B[0][2] = items2;
    printf("Input the element of Matrix(B):\n");
    input(B);

    printf("\nA is:\n");
    output(A);

    printf("\nB is:\n");
    output(B);

    int final_elems = lines * col;
    int C[final_elems + 1][3];

    add(A, B, C);

    printf("\nC is:\n");
    output(C);

    return 0;
}

void add(int A[][3], int B[][3], int C[][3])
{
    int i = 1;
    int j = 1;
    int k = 1;

    int s;

    while (i <= A[0][2] && j <= B[0][2])
    {
        if (A[i][0] == B[j][0])
        {
            if (A[i][1] < B[j][1])
            {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = A[i][2];
                k++;
                i++;
            }
            else if (A[i][1] > B[j][1])
            {
                C[k][0] = B[j][0];
                C[k][1] = B[j][1];
                C[k][2] = B[j][2];
                k++;
                j++;
            }
            else
            {
                s = A[i][2] + B[j][2];
                if (s != 0)
                {
                    C[k][0] = A[i][0];
                    C[k][1] = A[i][1];
                    C[k][2] = s;
                    k++;
                }
                i++;
                j++;
            }
        }
        else if (A[i][0] < B[j][0])
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            k++;
            i++;
        }
        else
        {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            k++;
            j++;
        }
    }
    if (i > A[0][2])
    {
        for (; j <= B[0][2]; j++)
        {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            k++;
        }
    }
    else if (j > B[0][2])
    {
        for (; i <= A[0][2]; i++)
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            k++;
        }
    }

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];
    C[0][2] = k - 1;
}

void output(int M[][3])
{
    int line_matrix = M[0][0];
    int col_matrix = M[0][1];
    int List[line_matrix][col_matrix];

    for (int i = 0; i < line_matrix; i++)
    {
        for (int j = 0; j < col_matrix; j++)
        {
            List[i][j] = 0;
        }
    }

    for (int i = 1; i <= M[0][2]; i++)
    {
        List[M[i][0] - 1][M[i][1] - 1] = M[i][2];
    }

    for (int i = 0; i < line_matrix; i++)
    {
        for (int j = 0; j < col_matrix; j++)
        {
            printf("%3d", List[i][j]);
        }
        printf("\n");
    }
}

void input(int M[][3])
{
    int lines = M[0][0];
    int col = M[0][1];

    for (int i = 1; i <= M[0][2]; i++)
    {
        scanf("%d %d %d", &M[i][0], &M[i][1], &M[i][2]);
    }
}
/* 
2 2 3
1 1 5
1 2 9
2 1 8
2 2 1
2 2 6
 */

/*
6 6 3
1 1 5
1 2 9
2 1 8
6 6 2
3 6 1
5 3 9
*/