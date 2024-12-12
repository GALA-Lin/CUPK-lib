#include <iostream>
using namespace std;
int ans = 0;



/**
 * 递归解决汉诺塔问题的函数
 *
 * @param n 要移动的盘子数量
 * @param from 起始柱子3
 * @param to 目标柱子
 * @param aux 辅助柱子
 */

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "*将圆盘 1 "<<"从柱子 " << from << " 移动到柱子 " << to << endl;
        ans++;
        return;
    }
    
    hanoi(n - 1, from, aux, to);

    cout << "-将圆盘 " << n << " 从柱子 " << from << " 移动到柱子 " << to << endl;
    ans++;

    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;

    cin >> n;

    //从柱子 A 移动到柱子 C，使用柱子 B 作为辅助
    hanoi(n, 'A', 'C', 'B');
    cout << "共有 " << ans << " 步移动" << endl;
    return 0;
}
