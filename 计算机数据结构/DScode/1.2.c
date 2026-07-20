#include <stdio.h>
#include <malloc.h>

struct Lnode
{
    int data[20];
    int last;
}; // 建立顺序
typedef struct Lnode *list;

list makeempty(int n)
{
    list ptrl;
    ptrl = (list)malloc(sizeof(struct Lnode));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptrl->data[i]);
    }
    ptrl->last = n - 1;
    return ptrl;
} // 建表
int find(int n, list ptrl)
{
    int i = 0;
    while (i <= ptrl->last && ptrl->data[i] != n)
    {
        i++;
    }
    if (i > ptrl->last)
    {
        return 0;
    }
    else
    {
        return n;
    }
} // 寻找相同元素
int main()
{
    int n1, n2, i, n, s = 0, a[20], j = 0, t, q, p;
    list p1, p2;
    scanf("%d", &n1);
    p1 = makeempty(n1);
    scanf("%d", &n2);
    p2 = makeempty(n2);
    for (i = 0; i < n1; i++)
    {
        n = p1->data[i];
        t = find(n, p2);
        if (t != 0)
        {
            a[j++] = t;
            s += 1;
        }
        if (i == n1 - 1)
        {
            for (q = 0; q < s; q++)
            {
                for (p = q + 1; p < s; p++)
                {
                    if (a[q] == a[p])
                    {
                        s -= 1;
                        a[p] = 0;
                    }
                }
            }
        }
    } // 通过第一个顺序表查询第二个顺序表中相同的元素并存在a[n]?
    printf("%d\n", s);
    if (s == 0)
    {
        printf("No same elements\n");
    }
    else
    {
        for (i = 0; i < s; i++)
        {
            if (a[i] != 0)
            {
                printf("%d ", a[i]);
            } // 输出相同元素
        }
    }
    return 0;
}
