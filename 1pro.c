#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//Josephu Question
//相当于循环链表

struct node
{
    int num;
    struct node *next;
};
typedef struct node NODE;

NODE *INIT(int);

void output(NODE *);

void josephus(void);

int main(void)
{
    josephus();

    return 0;
}

NODE *INIT(int length)
{
    NODE *head = (NODE *)calloc(1, sizeof(NODE));
    head->next = NULL;
    head->num = 1;

    NODE *new;
    new = head;

    for (int i = 1; i < length; i++)
    {
        new->next = (NODE *)calloc(1, sizeof(NODE));
        if (new->next == NULL)
        {
            printf("Failed in allocating.\n");
            exit(EXIT_FAILURE);
        }
        new = new->next;
        new->num = i + 1;
        new->next = NULL;
    }
    new->next = head;

    return head;
}

void josephus(void)
{
    int n, m, k;
    printf("请输入总人数：");
    scanf("%d", &n);
    printf("请输入起始玩家的位置：");
    scanf("%d", &m);
    printf("请输入报数的间隔：");
    scanf("%d", &k);
    NODE *head = INIT(n);

    output(head);

    NODE *pre;
    pre = head;

    printf("Josephus环出局顺序为：\n");
    for (int i = 1; i < m; i++)
    {
        pre = head;
        head = head->next;
    }

    while (head->next != head)
    {
        for (int i = 1; i < k; i++)
        {
            pre = head;
            head = head->next;
        }

        pre->next = head->next;

        printf("%d-", head->num);

        head = pre->next;
    }
    printf("%d", head->num);

    printf("\n\n最后的胜者为%d号玩家。\n", head->num);
}

void output(NODE *head)
{
    NODE *tmp;
    tmp = head;
    printf("\n----------Start----------");
    printf("\n最开始的玩家顺序为：");

    while (tmp->next != head)
    {
        printf("%d->", tmp->num);
        tmp = tmp->next;
    }
    printf("%d", tmp->num);

    printf("\n----------End------------\n\n");
}
