/*********************************************************************
程序名：梯形法计算定积分
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
7-20.为了计算出更加准确的定积分，采用梯形代替矩形计算定积分近似值，其思想是
求若干个梯形的面积之和，这些梯形的长短边高由函数值来决定。这些梯形左上角和
右上角在被积函数上。这样，这些梯形的面积之和就约等于定积分的近似值。
利用函数指针功能，写出利用梯形法求数值积分的函数。

解题分析：借鉴教材上的数值定积分函数，只要把其中的矩形计算公式修改为梯形
计算公式即可。
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
	return ((x - 5.0) * x + 16.0) * x - 80.0;
}

double f3 (double x) {	//
	return x * x * x - 7.7 * x * x + 19.2 * x -15.3;
}

double numInt2(double (*pf)(double), double a, double b) {	//梯形法积分
    long i, divn = 10;

    double step, dif, res, result = (pf(b) + pf(a)) * (b - a) / 2;
    for (dif = 1.0; dif > 1E-6 || dif < -1E-6; divn *= 2) {
        res = result;
        step = (b - a) / divn;
        for (result = 0.0, i = 0; i < divn; ++i)
        //    result += pf(a + i * step) * step;	//矩形积分
            result += (pf(a + i * step) + pf(a + i * step + step)) * step / 2;	//!!!梯形积分
        dif = result - res;
    }
    return res;
}

int main() {

	cout << "Function f1 integrated in [0, 1.5]: " << numInt2(f1, 0, 1.5) << endl;

	cout << "Function f2 integrated in [2, 8]: " << numInt2(f2, 2, 8) << endl;
    return 0;
}

