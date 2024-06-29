/*********************************************************************
程序名：求x平方根的迭代公式（递推公式）
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-20
说明：
4-4.（迭代和逼近）已知求 x 平方根的迭代公式（递推公式）是：.... ，
写一个程序，从键盘上输入 x 值，然后利用这个公式求 x 的平方根的近似值，
要求达到精度为 相对误差小于 10^-6。

分析：此题与教材正文中求立方根的例题是完全相似的，只需修改迭代公式即可。
*********************************************************************/

#include <iostream>
#include <cmath>	//数学函数 
using namespace std;

int main() {
	double x, x1, x2;

	cout << "Calculate square root of x" << endl;
	cout << "Please input x: ";
	cin >> x;
	x2 = x;

	if (x == 0) {
		cout << "square root of "<< x << " is : " << x2;
		return 0;    //程序结束，返回值为0
	}

	do {
		x1 = x2;
		x2 = (x1 + x / x1 ) / 2.0;	//!!!
		cout << x2 << endl;
	} while (fabs((x2 - x1) / x1) >= 1E-6);
	cout << "square root of "<< x << " is : " << x2;

	return 0;
}


