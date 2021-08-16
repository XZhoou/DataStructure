/*
编写一个程序，
寻找有向图中顶点u到顶点v的一条有向路径，
图采用邻接表存储。
要求顶点u和v通过键盘输入。
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define VER_NUM 10
#define EDGE_NUM 14
//建立一个10个顶点，14条边的有向图
//从顶点1出发，向顶点4走
//因为有向图并非网络，所以在边结点的结构体中并没有给边赋权
struct link
{
    int adjvex;
    int weight;
    struct link *next;
};
typedef struct link Elink;

struct ver
{
    int name;
    Elink *link;
};
typedef struct ver Vlink;

void Init(Vlink[], int, int);

void InfoShow(Vlink[], int, int);

//输出从u到v的可能路径
int DFS(Vlink[], int, int);

int visited[VER_NUM + 1] = {0};

int main(void)
{
    int u, v;
    Vlink Vs[MAX];
    Init(Vs, VER_NUM + 1, EDGE_NUM);
    //建立的顺序表设置为11个单元，更方便下标和节点名称的统一
    InfoShow(Vs, VER_NUM + 1, EDGE_NUM);
    printf("请输入u和v结点：\n");
    scanf("%d %d", &u, &v);
    printf("从结点 %d 到结点 %d 的一条路径为：\n", u, v);

    DFS(Vs, u, v);
    printf("%d", v);

    return 0;
}

void Init(Vlink Vs[], int n, int e)
{
    int vi, vj;
    for (int i = 1; i <= n; i++)
    {
        Vs[i].name = i;
        Vs[i].link = NULL;
    }
    Elink *p, *q;
    printf("请输入 %d 条边的起始结点和终结点\n", e);
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &vi, &vj);
        p = (Elink *)calloc(1, sizeof(Elink));
        p->adjvex = vj;
        p->weight = 1;
        p->next = NULL;
        if (Vs[vi].link == NULL)
        {
            Vs[vi].link = p;
        }
        else
        {
            q = Vs[vi].link;
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = p;
        }
    }
}

void InfoShow(Vlink Vs[], int n, int e)
{
    Elink *p, *q;
    printf("\n这个有向图共有 %d 个顶点， %d 个边。\n", n - 1, e);
    for (int i = 1; i < n; i++)
    {
        if (Vs[i].link != NULL)
        {
            p = Vs[i].link;
            while (p != NULL)
            {
                printf("存在从顶点 %d 到顶点 %d 的边，权值为%d。\n", i, p->adjvex, p->weight);
                p = p->next;
            }
        }
    }
}

int DFS(Vlink Vs[], int u, int v)
{
    int w;
    Elink *p;
    visited[u] = 1;
    printf("%d -> ", u);
    if (Vs[u].link == NULL)
    {
        w = -1;
    }
    else
    {
        p = Vs[u].link;
        w = p->adjvex;
        if (w == v)
        {
            return 0;
        }
    }
    while (w != -1)
    {
        if (visited[w] == 0)
        {
            DFS(Vs, w, v);
        }
        if (p->next == NULL)
        {
            w = -1;
        }
        else
        {
            w = p->adjvex;
            p = p->next;

            if (w == v)
            {
                return 0;
            }
        }
    }
}

/*
1 2
1 7
2 8
3 4
4 6
5 4
5 8
6 7
7 8
8 9
9 10
10 1
10 3
10 5
*/