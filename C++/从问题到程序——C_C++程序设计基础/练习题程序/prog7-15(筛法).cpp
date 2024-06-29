/*********************************************************************
程序名：字符串参数
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
7-15.修改7.5节的筛法程序，将分配数组的工作移到实现筛法的函数 sieve 里，
使它返回做好的数组，并对主函数做适当改造。从程序的清晰性和功能分配的
合理性等方面比较这两种实现方式。
**********************************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

//void sieve(int lim, int an[]) {
int * sieve2(int lim) {	//改写函数头：只需一个参数；返回值改为 int *
    int i, j, upb = sqrt(lim + 1);

	//修改：在函数中动态申请内存空间
	int * an = new int[lim];	//!!!
    if (an == NULL) {
        cout << "ERROR: No enough memory!\n";
        return NULL;	//如果动态分配内存失败，则函数返回 NULL 值
    }

    //初始化数组
    //an[0] = an[1] = 0;
    for (i = 2; i <= lim; ++i)
        an[i] = 1;

    for (i = 2; i <= upb; ++i)
        if (an[i] == 1) // i是素数
            for (j = i*2; j <= lim; j += i)
                an[j] = 0; // 这些数都是 i 的倍数，因此不是素数

    return an;	//!!! 返回在本函数中动态申请的内存空间的地址
}

int main() {
    int i, j, n = -1, *pn;

    do {
        cout << "please input an positive integer (>=2): ";
        cin >> n;
    } while (n < 2);


//    pn = new int[n];
//    if ( pn == NULL) {
//        cout << "ERROR: No enough memory!\n";
//        exit(1);
//    }
//    sieve(n, pn);    //筛法函数

    pn = sieve2(n);    //!!调用改写后的筛法函数：只提供参数 n，返回指针

    for(j = 0, i = 2; i <= n; ++i)
        if (pn[i] == 1)
            cout << i << ((++j) % 10 != 0 ? '\t' : '\n');
    cout << "\n总个数: " << j <<endl;

	delete []pn;

    return 0;
}

