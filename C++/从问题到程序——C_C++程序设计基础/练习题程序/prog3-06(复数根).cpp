/*********************************************************************
程序名：一元二次方程求根（可处理复数根） 
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
【例3-12】对求解一元二次方程 ax^2 + bx + c = 0 的问题，请编写一个程序，
使它能根据判别式 b^2 - 4ac 的值来判断方程的实根情况，并且计算出实根的值。

3-6.改进例3-12，使之能够处理一元二次方程复数根的情形（以类似于“a + bi”
的形式输出）。
*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a, b, c, d, tmp;
	
	cout << "please input a, b, c: ";
	cin >> a >> b >> c;
	d = b * b - 4 * a * c;
	cout << "d = " << d <<endl; 
	if (d > 0){	//两个实根，例如 a=1, b=2, c=-3
		tmp = sqrt(d);
		cout << "two real roots: ";
		cout << (-b + tmp) / (2 * a) << ", ";
		cout << (-b - tmp) /(2 * a) << endl;
	}
	else if (d == 0) 	//两个实根，例如 a=1, b=2, c=1
		cout << "One real root: " <<  -b / (2 * a) << endl;
	else {	//虚根。例如 a=-2, b=2, c=-1 
		tmp = sqrt(-d);
		cout << "two image roots: " ;
		//cout << "tmp = " << tmp <<endl;
		cout << -b / (2 * a) << " + " << fabs(tmp / (2 * a)) << "i,  ";
		cout << -b / (2 * a) << " - " << fabs(tmp / (2 * a)) << "i" << endl;
		//由程序中指定输出正负号，后面只需输出 tmp / (2 * a)的绝对值 
	}
	return 0;
}
