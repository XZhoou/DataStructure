#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//多项式的链式表示

struct node
{
    int coef;
    int exp;
    struct node *link;
};
typedef struct node NODE;

void output(NODE *);

NODE *INIT(int);

NODE *attach(int, int, NODE *);
//前两个int分别表示指数和系数，最后一个NODE*表示新的多项式的尾指针
//attach函数主要用来延长链表，把信息添加到新的链表上，作为一个子算法发挥作用
//手动输入整数作为多项式的系数，将两个多项式相加并输出结果
//先输入最高项次数，之后按照次数递减输入对应系数，如果该项系数为0则输入0

NODE *add(NODE *, NODE *);

NODE *input(void);

int main(void)
{
    srand(time(NULL));

    NODE *H;

    H = input();

    NODE *G;

    G = input();

    output(H);

    output(G);

    NODE *F;

    F = add(H, G);
    printf("\nAftert the Adding Function:\n");
    output(F);

    return 0;
}

void output(NODE *head)
{
    NODE *p;
    p = head;

    printf("\nThe polynomial is:\n");

    if (p != NULL)
    {
        if (p->coef > 0)
        {
            if (p->exp != 0)
                printf("%dx^%d", p->coef, p->exp);
            else
                printf("%d", p->coef);
        }

        else if (p->coef < 0)
        {
            if (p->exp != 0)
                printf("%dx^%d", p->coef, p->exp);
            else
                printf("%d", p->coef);
        }
        else
            ;
        p = p->link;
    }

    while (p != NULL)
    {
        if (p->coef > 0)
        {
            if (p->exp != 0)
                printf(" + %dx^%d", p->coef, p->exp);
            else
                printf(" + %d", p->coef);
        }

        else if (p->coef < 0)
        {
            if (p->exp != 0)
                printf(" %dx^%d", p->coef, p->exp);
            else
                printf(" %d", p->coef);
        }
        else
            ;
        p = p->link;
    }
    printf("\n");
}

NODE *INIT(int length)
{
    NODE *head = (NODE *)calloc(1, sizeof(NODE));
    if (head == NULL)
    {
        printf("Failed in allocating.\n");
        exit(EXIT_FAILURE);
    }

    head->coef = rand() % 10 - 5;
    head->exp = length;
    head->link = NULL;

    NODE *p;
    p = head;

    for (int i = 1; i <= length; i++)
    {
        p->link = (NODE *)calloc(1, sizeof(NODE));
        if (p->link == NULL)
        {
            printf("Failed in allocating.\n");
            exit(EXIT_FAILURE);
        }
        p = p->link;

        p->coef = rand() % 10 - 5;
        p->exp = length - i;
        p->link = NULL;
    }

    return head;
}

NODE *attach(int ex, int co, NODE *pt) //接受了一个尾指针，返回了一个更靠后的新的尾指针
{
    NODE *new = (NODE *)calloc(1, sizeof(NODE));
    if (new == NULL)
    {
        printf("Failed in allocating.\n");
        exit(EXIT_FAILURE);
    }

    new->coef = co;
    new->exp = ex;
    new->link = NULL;

    pt->link = new;

    return new;
}

NODE *add(NODE *head1, NODE *head2)
{
    NODE *head = (NODE *)calloc(1, sizeof(NODE));
    if (head == NULL)
    {
        printf("Failed in allocating.\n");
        exit(EXIT_FAILURE);
    }

    NODE *p;
    p = head;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->exp > head2->exp)
        {
            p = attach(head1->exp, head1->coef, p);
            head1 = head1->link;
        }
        else if (head2->exp > head1->exp)
        {
            p = attach(head2->exp, head2->coef, p);
            head2 = head2->link;
        }
        else if (head2->exp == head1->exp)
        {
            p = attach(head1->exp, head1->coef + head2->coef, p);
            head1 = head1->link;
            head2 = head2->link;
        }
    }
    while (head1 != NULL)
    {
        p = attach(head1->exp, head1->coef, p);
        head1 = head1->link;
    }
    while (head2 != NULL)
    {
        p = attach(head2->exp, head2->coef, p);
        head2 = head2->link;
    }

    p->link = NULL;

    return head->link;
}

NODE *input(void)
{
    printf("Please input the exponent of highest term of polynomial:\n");

    int length;
    scanf("%d", &length);

    printf("Input the coefficient of the polynomial:\n");

    int num;
    scanf("%d", &num);

    NODE *head = (NODE *)calloc(1, sizeof(NODE));
    if (head == NULL)
    {
        printf("Failed in allocating.\n");
        exit(EXIT_FAILURE);
    }

    head->exp = length;
    head->coef = num;
    head->link = NULL;

    NODE *p;
    p = head;

    for (int i = 1; i <= length; i++)
    {
        scanf("%d", &num);

        p->link = (NODE *)calloc(1, sizeof(NODE));

        if (p->link == NULL)
        {
            printf("Failed in allocating.\n");
            exit(EXIT_FAILURE);
        }

        p = p->link;
        p->exp = length - i;
        p->coef = num;
    }

    return head;
}
/*
3
-10 9 19 2
5
10 0 9 10 85 1
 */

/*
5
8 11 -9 15 23 74
5
-3 6 29 77 1 -26
*/