#include <iostream>
using namespace std;
int f[1111], degree[1111];

void init(int n) {
    for (int i = 1; i <= n; i++)
        f[i] = i;
}

int getf(int x) {
    if (x == f[x])
        return x;
    return f[x] = getf(f[x]);
}

void merge(int a, int b) {
    a = getf(a);
    b = getf(b);
    if (a != b)
        f[b] = a;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        merge(a, b);
        degree[a]++;
        degree[b]++;
    }
    // 1:欧拉回路，2：欧拉路径
    int root = f[1], flag1 = 1, flag2 = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] & 1)
            cnt++;
        if (f[i] != root || degree[i] & 1) {
            flag1 = 0;
            break;
        }
    }
    if (cnt == 2 || cnt == 0)
        flag2 = 1;
    cout << flag1 << endl<<flag2;
    return 0;
}
