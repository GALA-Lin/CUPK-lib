/*********************************************************************
程序名：多项式求值与绘图
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-22
说明：6-11.（1）参照【例6-6】，实现一个求由数组表示的多项式的值的函数。
函数原型设为double polynomial(int n, double po[], double x)。
（2）写两个函数分别求出一个double数组中的最大值和最小值。函数原型分别为：
double arraymax(int n, double a[])和double arraymin(int n, double a[]);
（3）调用函数 polynomial 求出多项式在 [-5, 5] 区间内间隔为 0.2 的一系列
（共51个）点的值并存放于数组中，然后利用函数 arraymax 和 arraymin 求出
其中的最大值和最小值。
*（4）将上一步中存放于数组中的值进行规格化（转换到 [0, 1] 区间），然后
设法用星号在屏幕上打印显示上述多项式在[-5, 5]区间内的近似图形。
*********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

double polynomial(int n, double po[], double x) {
//函数功能：计算最大次数为 n 的多项式在自变量为 x 时的值。
//多项式的各个系数依次存放于数组 po 中。
	int k;
	double sum;
	for (sum = 0.0, k = n - 1; k >= 0; --k)
		sum = sum * x + po[k];
	//cout << "Polynomial value: " << sum << endl;
	return sum;
}

double arraymax(int n, double a[]) {  //求一个double数组中的最大值
	double amax = a[0];	//定义用于记录最大值的变量并初始化为 a[0]
	for (int i = 0; i < n; i++)
		if (a[i] > amax)
			amax = a[i];
	return amax;
}

double arraymin(int n, double a[]){	//求一个double数组中的最小值
	double amin = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] < amin)
			amin = a[i];
	return amin;
}

int main() {
	//示例多项式：40 - 10 * x - 1.2 * x^2 + 0.5 * x^3
	double po[] = {40, -10, -1.2, 0.5}; //定义数组并初始化
	int len = sizeof(po)/sizeof(po[0]);
	int i, j;

	double dmin = -5, dmax = 5;	//x的区间 [-5, 5]
	const int num = 51;	//取点数
	double d = (dmax - dmin) / (num - 1);	//x 的取点间距
	double x[num], y[num];	// x 和 y 的一系列值

	cout << "x \ty\n";	//屏幕输出时的标题行
	for (i = 0; i < num; i++) {
		x[i] = dmin + d * i;
		y[i] = polynomial(len, po, x[i]);
		cout  << setprecision(5) << x[i] << "\t" << y[i] << endl;
	}

	double ymax = arraymax(num, y);
	double ymin = arraymin(num, y);
	cout << "ymin = " << ymin << "\tymax = " << ymax << endl;

	//将 y 数组中的值进行规格化（转换到区间 [0, 1] ）
	for (i = 0; i < num; i++) {
		y[i] = y[i] / (ymax - ymin);
		//cout << fixed << x[i] << "\t" << y[i] << endl;
	}

	cout << "\n横向绘图（y 值横向绘制，最大值设为 maxlen）\n";
	int maxlen = 60;	//字符终端窗口通常是25行80列，取一个合适的最大列数。
	for (i = 0; i < num; i++) {
		cout << setw(8) << fixed << setprecision(2)  << x[i] << "|";
		for (j = 0; j < y[i] * maxlen-1; j++)
			putchar(' ');//输出一系列空格
		cout << "*\n";	//输出星号和回车
	}
	cout << setw(8) << ymin << "-"
		<< setw(maxlen) << setfill('-')<< ymax << setfill(' ') << endl;//横轴标记

	cout << "\n纵向绘图（y值纵向绘制）\n";
	//技巧：字符界面上只能逐行绘制，相当于是从曲线图形的上方往下方绘制；
	//所以在程序中是对 y 从大到小地绘制，对每个 y 值都检查一次哪个相应的 x 值与之对应。
	maxlen = 20;	//字符终端窗口通常是25行80列，取一个合适的最大行数。
	for (int iy = maxlen; iy >= 0; iy--) {	//绘图 y 值从大到小地变化
		cout << setw(8) << setprecision (2) << ymin + (ymax - ymin)*iy << "|";
		for (int jx = 0; jx < num; jx++) {	//检查各个 x 值的多项式值是否与绘图y值对应
			if ((int)(y[jx] * maxlen) != iy)
				putchar(' ');	//输出空格
			else
				putchar('*');	//输出星号
		}
		cout << endl;
	}
	cout << setw(8) << dmin << "-"
		<< setw(num) << setfill('-')<< dmax << setfill(' ') << endl;//横轴标记
	return 0;
}
