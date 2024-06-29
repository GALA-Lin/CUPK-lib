/*********************************************************************
程序名：银行利息
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
prog3-14 请改进例3-19中的输出九九乘法表程序，给输出的乘法表加上美观的表头，
以及被乘数列和乘数行。按自己的想法进一步尽可能地美化乘法表的输出。
*********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int m, n;
    cout << "9*9 multiplication table" << endl;
    for (m = 1; m <= 9; m++) {
        cout << setw(2) << m << "  ";
        for (n = 1; n <= m; n++)  // n <= m
            cout << m << "*" << n << "=" << setw(2) << m *n << "  ";
        cout << endl;
    }
    cout << " *  ";
    for (m = 1; m <= 9; m++)  // n <= m
        cout << setw(6) << m << "  ";

    return 0;
}

