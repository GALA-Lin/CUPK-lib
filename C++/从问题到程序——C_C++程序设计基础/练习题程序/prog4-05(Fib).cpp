/*********************************************************************
程序名：递推计算Finonacci数列项
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2020-12-31
说明：
4-5.（递推）考虑使用如下算法用于递推计算Finonacci数列项：使用两个变量
保存相邻的奇数项和偶数项（初始化为第1项和第2项），在循环中根据当前待求
项数的奇偶性而选择只更新奇数项或偶数项。
*********************************************************************/

#include <iostream>
#include <cmath>	//数学函数 
using namespace std;

int main() {    //递推计算Finonacci数列项
    int n;
    do {
        cout << "Please input n (between 3 and 46): ";
        cin >> n;
    } while (n < 3 || n > 46);

    int f1 = 1, f2 = 1;   //f1和f2表示相邻的奇数项和偶数项，初始化为第1、2项
    cout << f1 << "\t" << f2 << "\t";
    for (int k = 3; k <= n; ++k) {
        if (k % 2)    //奇数项
            f1 = f1 + f2;
        else    //偶数项
            f2 = f1 + f2;
        cout << (k % 2 ? f1 : f2) << (k % 5 == 0 ? "\n" : "\t");
    }
    cout << "\nThe " << n << "th Fibonacci number is "
         << (n % 2 ? f1 : f2) << endl;

    return 0;
}


