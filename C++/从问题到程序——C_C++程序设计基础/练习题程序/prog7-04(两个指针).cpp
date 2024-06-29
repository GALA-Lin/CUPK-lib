/*********************************************************************
程序名：把数组写法改写为指针写法
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2022-05-26
说明：
7-4. 编写如下函数（并编写主函数进行测试）：（1）把一个double数组的子序列
的元素值打印输出，函数原型为prtSeq(double *begin, double *end)；
（2）把一个double数组的任意子序列的值变换为原值的平方根，函数原型为
sqrtSeq(double *begin, double *end)。
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

void prtSeq(double *begin, double *end) {
    for ( ; begin < end; begin++)
        cout << *begin << "\t";
    cout << endl;
    return;
}

void sqrtSeq(double *begin, double *end) {
    for ( ; begin < end; begin++)
        *begin = sqrt(*begin);
    return;
}


int main() {
    //定义数组并以示例数据初始化
    double array[] = {3.2, 2.1, 5.3, 1.8, 7.9, 8.2, 10.3, 6.1, 5.4 };
    int len = sizeof(array) / sizeof(array[0]);  //求出数组长度

    prtSeq(array, array + len);  //打印输出一遍

    sqrtSeq(array, array + len); //元素值变换为原值的平方根

    prtSeq(array, array + len);  //再打印输出一遍


    return 0;
}




