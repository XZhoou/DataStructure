/*
快速排序和谢尔排序方法对一个输入序列进行降序排序，
并比较两个算法的比较次数和元素移动次数。
 */

#include <stdio.h>
#include <stdlib.h>

void shellsort(int list[], int n);

void quick(int list[], int s, int t);

void quicksort(int list[], int n);

int times_quicksort;
int compare_quicksort;

int main(void)
{
    int num[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    printf("\nThe number sequence is:\n");
    for (int i = 0; i < sizeof(num) / sizeof(int); i++)
    {
        printf("%3d", num[i]);
    }
    printf("\n\nAfter the shellsort function:\n");
    shellsort(num, sizeof(num) / sizeof(int));

    printf("\nThe number sequence is:\n");
    int num2[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    for (int i = 0; i < sizeof(num2) / sizeof(int); i++)
    {
        printf("%3d", num2[i]);
    }
    printf("\n\nAfter the quicksort function:\n");
    quicksort(num2, sizeof(num2) / sizeof(int));
    for (int i = 0; i < sizeof(num2) / sizeof(int); i++)
    {
        printf("%3d", num2[i]);
    }
    printf("\n快速排序法————比较了 %d 次，元素交换了 %d 次。\n", compare_quicksort, times_quicksort);

    return 0;
}

void shellsort(int list[], int n)
{
    int times = 0;
    int compare = 0;
    int flag;
    int gap = n;
    int temp;
    int j;
    while (gap > 1)
    {
        gap = gap / 2;
        do
        {
            flag = 0;
            for (int i = 0; i <= n - gap; i++)
            {
                j = i + gap;
                compare++;
                if (list[i] > list[j])
                {
                    temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                    flag = 1;
                    times++;
                }
            }
        } while (flag != 0);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%3d", list[i]);
    }
    printf("\n希尔排序法————比较了 %d 次，元素交换了 %d 次。\n", compare, times);
}

void quick(int list[], int s, int t)
{
    int i, j;
    int temp;
    if (s < t)
    {
        i = s;
        j = t + 1;
        while (1)
        {
            do
            {
                compare_quicksort++;
                i++;
            } while (!(list[s] <= list[i] || i == t));
            do
            {
                compare_quicksort++;
                j--;
            } while (!(list[s] >= list[j] || j == s));
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
                times_quicksort++;
            }
            else
                break;
        }
        temp = list[s];
        list[s] = list[j];
        list[j] = temp;
        times_quicksort++;
        quick(list, s, j - 1);
        quick(list, j + 1, t);
    }
}

void quicksort(int list[], int n)
{
    quick(list, 0, n);
}