/*********************************************************************
程序名：求双曲正弦反函数（通项计算）
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-20
说明：
4-8.(通项计算）已知双曲正弦反函数 asinh(x)= ......                 ，
写程序计算 asinh(x)的近似值（尾项的值小于10?7时截断)。并与标准库函数
asinh 相比较以确认结果是否正确。
*********************************************************************/

#include <iostream>
#include <cmath>	//数学函数
#include <iomanip>
using namespace std;

int main() {
	int i;
	double x, term = 0, sum = 0;

	cout << "计算双曲正弦反函数 asinh(x)" << endl;
	//cout << "请输入 x (|x|<1): " ;
	//cin >> x;
	x = 0.8;
	if (fabs(x) >= 1) {
		cout << "ERROR：x >= 1" << endl;
		return 1;
	}

	sum = term = x;	// 首项 （或者称为 第 0 项）
	for (i = 1; fabs(term) > 1e-7; i++) {
		//后一项与前一项的关系：乘以 -x*x ，分子乘以 (2*i-1)*(2*i-1)，分母乘以 (2*i)*(2*i+1)
		term = term * (-1) * x * x * (2*i-1) * (2*i-1) /(2*i) / (2*i+1);
		sum = sum + term;
		cout << "i= " << i << setprecision(10) << "\tterm= " << term << "\tasinh(x)= " << sum << endl;
	}
	cout << "x= " << x << "\t   asinh(x)= " << sum << endl;
	cout << "标准库函数 asinh(x)= " << asinh(x) << endl;

	return 0;
}

