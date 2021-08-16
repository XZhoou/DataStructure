#include <stdio.h>
//回溯法解决八皇后问题
int queens[8] = {0}; //全局变量，8个元素，分别代表从1-8行的皇后都在第几列（1-8）
int sum = 0;         //记录一共有多少种八皇后问题的解法

int Eight_Queen(int);

int Judge(int, int);

void output(int *);
