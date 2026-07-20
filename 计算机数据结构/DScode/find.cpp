#include <bits/stdc++.h> // 引入标准库头文件
using namespace std;

#define ll long long // 定义long long类型为ll
const ll N = 1e5 + 10; // 定义常量N为100010

// 定义变量
ll n, m, flag[N], a[N], b[N], fa[N], ans, maxn;

// 并查集的查找函数，用于找到元素的根节点
ll find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]); // 如果x是根节点，返回x；否则递归查找并路径压缩
}

// 并查集的合并函数，用于合并两个集合
void merge(int x, int y)
{
    x = find(x); // 找到x的根节点
    y = find(y); // 找到y的根节点
    if (x != y)  // 如果x和y不在同一个集合
    {
        fa[x] = y; // 将x的根节点指向y
        a[y] += a[x]; // 合并集合的元素数量
    }
}

// 主函数，程序入口
int main()
{
    cin >> n; // 输入n
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i]; // 输入数组a的元素
        fa[i] = i; // 初始化并查集，每个元素的父节点是自己
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> b[i]; // 输入数组b的元素
    }
    for (ll i = n; i >= 2; i--)
    {
        flag[b[i]] = 1; // 标记b[i]已访问
        if (flag[b[i] - 1] && !flag[b[i] + 1]) // 如果b[i]-1已访问且b[i]+1未访问
            merge(b[i], b[i] - 1); // 合并b[i]和b[i]-1
        if (!flag[b[i] - 1] && flag[b[i] + 1]) // 如果b[i]-1未访问且b[i]+1已访问
            merge(b[i], b[i] + 1); // 合并b[i]和b[i]+1
        if (flag[b[i] - 1] && flag[b[i] + 1]) // 如果b[i]-1和b[i]+1都已访问
            merge(b[i], b[i] - 1), merge(b[i], b[i] + 1); // 合并b[i]和b[i]-1及b[i]+1
        maxn = max(maxn, a[find(b[i])]); // 更新最大集合大小
        ans += maxn; // 累加结果
    }
    cout << ans; // 输出结果
    return 0;
}
