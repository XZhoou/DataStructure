/*
编写一个程序，建立一个二叉排序树并用中序遍历算法遍历该二叉排序树。
要求：二叉排序树建立时采用升序方式；数据通过键盘输入，输入-1时结束
*/

/*
建立一个二叉排序后，若采用中序遍历方法遍历该二叉排序数，
即相当于按照升序的顺序访问二叉树中的元素
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Binary_Sort_Tree
{
    int data;
    struct Binary_Sort_Tree *Lchlid, *Rchlid;
};
typedef struct Binary_Sort_Tree BTNODE, *BTREE;

BTREE SortTree(int[]);

void Insert(BTREE *, int);

void Inorder(BTREE);

int main(void)
{
    int NUM[MAX];
    int n;
    int i = 0;
    printf("\nPlease input a number sequence:\n");
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
        {
            NUM[i] = -1;
            break;
        }
        else
        {
            NUM[i] = n;
            i++;
        }
    }
    i=0;
    printf("\nNumber sequence is :\n");
    while (NUM[i]!=-1)
    {
        printf("%5d",NUM[i]);
        i++;
    }
    BTREE T = SortTree(NUM);

    printf("\nAfter the Inorder Function :\n");

    Inorder(T);

    return 0;
}

BTREE SortTree(int list[])
{
    BTREE T = NULL;

    for (int i = 0; i < MAX; i++)
    {
        if (list[i] != -1)
        {
            Insert(&T, list[i]);
        }
        else
        {
            return T;
        }
    }
}

//递归方法建立二叉排序树
void Insert(BTREE *T, int number)
{
    if ((*T) == NULL)
    {
        (*T) = (BTREE)calloc(1, sizeof(BTNODE));
        (*T)->data = number;
        (*T)->Rchlid = NULL;
        (*T)->Lchlid = NULL;
    }
    else if (number < (*T)->data)
    {
        Insert(&((*T)->Lchlid), number);
    }
    else
    {
        Insert(&((*T)->Rchlid), number);
    }
}

void Inorder(BTREE T)
{
    if (T != NULL)
    {
        Inorder(T->Lchlid);
        printf("%5d", T->data);
        Inorder(T->Rchlid);
    }
}
/*
1 3 7 91 42 5 19 33 73 -1
9 5 16 -7 95 66 12 37 51 2 61 33 -1
18 97 2 8 6 15 39 5 1 22 -1
*/
