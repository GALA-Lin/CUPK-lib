/*********************************************************************
程序名：把数组写法改写为指针写法
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：
7-3.把上一章中用数组方式定义的函数【例6-7】（求元素平均值）和【例6-8】
（反转数组里的元素）改写为用指针运算的方式定义。
*********************************************************************/
#include <iostream>
using namespace std;

//【例6-7】求数组元素平均值的函数
double avrg(int len, double a[]) {	//原有的数组写法
    double sum = 0.0;

    for (int i = 0; i < len; ++i)
        sum += a[i];

    return sum / len;
}

double avrg_ptr(int len, double *a) {//指针写法：参数 a[] 改写为 *a
    double sum = 0.0;

    for (int i = 0; i < len; ++i)
        sum += *(a + i);	// 把 a[i] 改写为 *(a+i)

    return sum / len;
}

//【例6-8】反转数组里的元素。
void rev(int len, int a[]) {	//原有的数组写法
    int t, i, j;

    for (i = 0, j = len - 1; i < j; ++i, --j) {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}

void rev_ptr(int len, int *a) {	//指针写法：参数 a[] 改为 *a
    int t, i, j;
    for (i = 0, j = len - 1; i < j; ++i, --j) {
        //把 a[i] 改写为 *(a + i)，把 a[j] 改写为  *(a + j)
        t = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = t;
    }
}

void printall(int n, int a[]) {
    for (int i = 0; i < n; ++i)
        cout << *(a + i) << '\t';
    cout << endl;
}

int main() {

    cout << "\n测试【例6-7】求元素平均值\n";
    double a1[5] = {6.54, 9.23, 8.463, 4.25, 0.386};    //定义数组并以示例数据初始化

    cout << "averages of a1: " << avrg_ptr(3, a1) << endl;

    cout << "\n测试【例6-8】反转数组里的元素\n";
    int i, a2[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(a2) / sizeof(a2[0]);
    cout << "before reversion:" << endl;
    printall(len, a2);

    rev_ptr(len, a2);	//!!!

    cout << endl << "After reversion:" << endl;
    printall(len, a2);

    return 0;
}




