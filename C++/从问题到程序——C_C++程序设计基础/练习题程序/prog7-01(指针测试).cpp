/*********************************************************************
程序名：指针测试
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：
7-1. 把7.2.1和7.2.2的正文中零散地说到的指针变量定义语句和指针操作语句
都写在一个主函数中（需要合理地增删或调整），并添加一些 cout << 语句
进行输出，以查看变量的值（（例如：cout << "n = "<< n << "\t" << *p << endl;）
或变量的地址值（例如 cout << "&n=” << &n << "\t" << "p=" << p << endl; ），
这样构成一个可以运行的程序，以测试相关的知识。
*********************************************************************/
#include <iostream>
using namespace std;

int main() {
    //定义指针变量
    int *p, n, a[10], *q, *p1, m;
    char *pch, *pch1;    //定义字符指针pch和pch1
    double *px, *py;    //定义double 指针px和py

    //查看指针大小
    cout << "Size of int pointer : " << sizeof (p) << endl;
    cout << "Size of char pointer : " << sizeof (pch) << endl;
    cout << "Size of double pointer : " << sizeof (px) << endl;

    //取变量地址并赋给指针
    p = &n;
    q = p;
    p1 = &a[1];

    //int n = 10, *p = &n;
    //double x, y, *px = &x, *py = &y;

    px = NULL;

    //间接访问
    *p = 17;
    m = *p + *q * n;

    ++ *p;      // 使变量 n 的值加 1，变成 18
    (*p)++;     // 使变量 n 的值再加 1，变成 19。
    //注意：由于结合性的规定，*p++ 的意义与此不同
    *p += *q + n;    // 变量 n 被赋以新值 57
    q = &a[0];    // 指针 q 指向了数组 a 的元素
    *q = *p / 16;    // a[0]被赋值 3
    //输出指针所指变量的值
    cout << "*p = " << *p << endl;
    cout << "*q = " << *q << endl;

    //输出指针本身的值
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;

    return 0;
}


