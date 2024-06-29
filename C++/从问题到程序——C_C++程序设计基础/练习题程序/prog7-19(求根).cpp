/*********************************************************************
程序名：数值求根方法：二分法和牛顿迭代法
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
7-19. 常用的对数学函数的数值求根方法还有二分法和牛顿迭代法。二分法求根的
初始情况与弦截法类似，也是从两端点函数值异号的一个区间开始，每次求出区间
中点，从中点函数值的符号决定取左边半区间还是右边半区间作为缩短的区间。
不断重复这个操作，直到得到满意的结果。而用牛顿迭代法求方程 f(x) = 0的根
的迭代公式是：...... ，其中 f'(x) 是 f(x) 的导数。由某个初始值 x 出发，
反复使用上面公式可以求出方程根的近似值。写出分别用二分法和牛顿迭代法对
数学函数求根的函数（使用函数指针作参数）。用它们求一些方程（多项式方程
或包含超越函数的方程）在某点附近或某对点之间的根。若有可能，请考察方程
情况与循环次数的关系（这就需要统计程序循环执行的次数）。

解题分析：（1）参照教材正文中给出的弦截法，进行简单修改即可写出二分法；
（2）牛顿迭代法需要用于方程本身及其导数，故其参数需要二个指向函数的指针，
还只需要一个起始点。参照教材第4章中讲到的迭代法编写此函数。
（3）对于待求根的数学函数，需要写一个相应的函数，在使用牛顿迭代法时还要
对其导数写一个相应的函数。
**********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

//下面提供了三个示例函数可供测试。f1 和 f2 来自教材正文，f3 来自本题。
//读者可以在如下网站快速绘制曲线图，了解函数性质：http://www.fooplot.com
double f1 (double x) {
	return x * sin(x) - 2 * x * x + 2 * x;
}

double f2 (double x) {
	return ((x-5.0)*x+16.0)*x-80.0;
}

double f3 (double x) {	//
	return x * x * x - 7.7 * x * x + 19.2 * x -15.3;
}

double f3d(double x) {	//f3 的导数
	return 3 * x * x - 15.4 * x + 19.2;
}

double cross(double (*pf)(double), double x1, double x2) {
	double y1 = pf(x1), y2 = pf(x2);
	return (x1 * y2 - x2 * y1) / (y2 - y1);
}

double chordroot(double (*pf)(double), double x1, double x2) {
//弦截法求根
	double x, y, y1 = pf(x1);
	do {
		x = cross(pf, x1, x2);
		y = pf(x);
		if (y * y1 > 0.0) {
			y1 = y;
			x1 = x;
		} else
			x2 = x;
	} while (y >= 1E-6 || y <= -1E-6);

	return x;
}


double binaryroot(double (*pf)(double), double x1, double x2) {//二分法求根
	int iterate = 0;	//迭代次数
	cout << "二分法求根\n" ;
	cout << "次数\t" << "x1\t\t" << "x2\t\t" << "y1\t\t" << "y2\n";

	double x, y, y1, y2;
	if (pf(x1) * pf(x2) > 0)
		cout << "区间两端点的函数值同号，可能无法求解\n";
	do	{
		x = (x1 + x2) / 2;	//区间中点
		y = pf(x);
		y1 = pf(x1);
		y2 = pf(x2);
		if(y1 * y > 0) //y1 与 y 同号
			x1 = x;
		else if( y2 * y > 0)
			x2 = x;
		cout << fixed << ++iterate << "\t"
			<< x1 << "\t" << x2 << "\t" << y1 << "\t" << y2 << endl;
	} while (!(fabs(y1) <= 1E-6 || fabs(y2) <= 1E-6));//直到其中一个点的值足够小

	return (fabs(y1) < fabs(y2) ? x1 : x2);	//返回函数值绝对值较小的那个 x 值
}

double newtonroot(double (*pf)(double), double (*pfd)(double), double x1) {//牛顿迭代法求根
	int iterate = 0;	//迭代次数
	cout << "牛顿迭代法求根\n" ;
	cout << "次数\t" << "x\t\t" << "y\n";

	double x2;
	while( fabs(pf(x1)) >0.000001) {
		x2 = x1 - pf(x1) / pfd(x1);
		x1 = x2;
		cout << ++iterate << "\t" << x2 << "\t" << pf(x2) << "\n";
	}
	return x2;
}


int main() {
	cout << "数值求根\n";
	double x;
//	x = chordroot(f1, 1.26, 7.03);
//	cout <<"A root of equation f1 is: "<< x <<endl;
//
//	x = chordroot(f2, 1.26, 7.03);
//	cout <<"A root of equation f2 is: "<< x <<endl;
//
//	x = chordroot(sin, 0.4, 4.5);
//	cout <<"A root of equation sin is: "<< x <<endl;
//
//	x = chordroot(cos, 0.4, 4.5);
//	cout<<"A root of equation cos is: "<< x <<endl;

	x = binaryroot(f3, 1, 2);
	cout<<"A root of equation f3 by binaryroot is: " << x << "\n\n";

	x = newtonroot(f3, f3d, 1);
	cout<<"A root of equation f3 by newtonroot is: "<< x << "\n\n";

	return 0;
}

