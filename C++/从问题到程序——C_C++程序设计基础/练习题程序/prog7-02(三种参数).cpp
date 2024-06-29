/*********************************************************************
程序名：C/C++程序中的值参数、引用参数与指针参数
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-12-29 15:43
说明：
7-2. 把例5-8、例5-9和例7-1中的三个函数写在一个程序中，并写一个主函数
分别调用它们，以对比三种参数机制的异同。
*********************************************************************/
#include <iostream>
using namespace std;

//【例5-8】值参数
void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
    cout << "swaped inside: a= " << a << "  b= " << b << endl;
}

//【例5-9】引用参数
void swapref(int &a, int &b)  { //形参a, b都是引用
    int t = a;
    a = b;
    b = t;
    cout << "swaped inside: a= " << a << "  b= " << b << endl;
}

//【例7-1】指针参数
void swapptr(int *p, int *q) {
    int t = *p;
    *p = *q;
    *q = t;
    cout << "swaped inside: *p= " << *p << "  *q= " << *q << endl;
}

int main() {
    int m = 10, n = 25;
    cout << "before swap: m= " << m << "  n= " << n << endl;
    swap(m, n);		//【例5-8】值参数
    cout << "after swap:  m= " << m << "  n= " << n << endl;

    m = 10, n = 25;
    cout << endl << "before swapref: m= " << m << "  n= " << n << endl;
    swapref(m, n);	//【例5-9】引用参数
    cout << "after swapref:  m= " << m << "  n= " << n << endl;

    m = 10, n = 25;
    cout << endl << "before swapptr: m= " << m << "  n= " << n << endl;
    swapptr(&m, &n);	//【例7-1】指针参数
    cout << "after swapptr:  m= " << m << "  n= " << n << endl;
    return 0;
}

