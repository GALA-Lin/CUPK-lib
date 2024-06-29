/*********************************************************************
程序名：多项式
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
7-17.多项式（polynomial）可以数组表示，例如用一个 n + 2 个元素的整数数组
a 表示一个 n 次的整系数多项式，其中的在a[0]中保存多项式最高次的次数（由此
也可以决定多项式的项数），其余元素顺序表示一个多项式的0次项、1次项、2次项
等等的系数，多项式的变量隐含假定为x。这种数组可以通过动态存储分配创建。
请基于这种表示方式实现一元多项式的输入（自己设计一种输入方式）和输出。
输出时尽可能采用直观的类似数学中的表示形式（例如输出为3 + 2 x + 4 x^2，
系数为 0 的项不输出）。然后进一步写函数实现两个多项式相加、相减和相乘的
运算，并写一个主函数测试这些功能。
**********************************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

int * poly_input() {	//多项式输入
	int n;
	cout << "请输入整系数多项式的最高次：" ;
	cin >> n;
	int *a = new int[n + 2];	//申请存储块
	if (a == NULL) {
		cout << "程序出错：动态申请存储失败！\n";
		return NULL;
	}
	//下面用数组写法（也可以用指针写法）
	a[0] = n;	//在a[0]中保存多项式最高次的次数
	cout << "请输入 0 -- " << n << " 次项的系数：";
	for (int i = 0; i <= n; i++) {
		if ( !(cin >> a[i + 1]) )	//用户输入 a[i+1] 的值
			a[i + 1] = 0;	//非正常输入则赋值为0
	}
	cin.sync();
	cin.clear();

	return a;
}

void poly_output(int * a) {	//多项式输出
	if (a == NULL)	//空指针则直接退出
		return;
	int eq0 = 1;	//前面的项数是否等于 0
	for (int i = 0; i <= a[0]; i++) {
		if (a[i + 1] == 0) //系数为0的项，不输出
			continue;
		//下面输出系数不为0的项
		//先处理正负符号
		if (a[i + 1] >= 0 && !eq0)	//当前项的系数大于 0，且前面至少有一项非零系数
			cout << " + ";
		if (a[i + 1] < 0)
			cout << " - ";
		eq0 = 0;	//至少有一项的系数不等于 0
		//然后处理系数的绝对值
		cout << fabs(a[i + 1]);
		//再输出 x 的几次方。0次方不需要输出。
		if (i >= 1)	//
			cout << " x";
		if (i > 1)
			cout << "^" << i;
	}
	if (eq0 == 1)	//所有系数都等于 0
		cout << 0;

	cout << endl;
}

int * poly_add(int *a1, int *a2) {	//多项式相加
	int i, max, min;
	max = (a1[0] > a2[0] ? a1[0] : a2[0]);
	min = (a1[0] < a2[0] ? a1[0] : a2[0]);

	int *a = new int[max + 2];	//申请存储块
	if (a == NULL) {
		cout << "程序出错：动态申请存储失败！\n";
		return NULL;
	}

	a[0] = max;	//在a[0]中保存多项式最高次的次数
	for (i = 0; i <= min; i++)	//两式都有的次数，系数相加
		a[i+1] = a1[i+1] + a2[i+1];
	//处理其中一式超出的次数
	for (i = min + 1; i <= a1[0]; i++)
		a[i+1] = a1[i+1];
	for (i = min + 1; i <= a2[0]; i++)
		a[i+1] = a2[i+1];
	return a;
}

int * poly_minus(int *a1, int *a2) {	//多项式相减
	int i, max, min;
	max = (a1[0] > a2[0] ? a1[0] : a2[0]);
	min = (a1[0] < a2[0] ? a1[0] : a2[0]);

	int *a = new int[max + 2];	//申请存储块
	if (a == NULL) {
		cout << "程序出错：动态申请存储失败！\n";
		return NULL;
	}

	a[0] = max;	//在a[0]中保存多项式最高次的次数
	for (i = 0; i <= min; i++)	//两式都有的次数，系数相减
		a[i+1] = a1[i+1] - a2[i+1];
	//处理其中一式超出的次数
	for (i = min+1; i <= a1[0]; i++)
		a[i+1] = a1[i+1];
	for (i = min+1; i <= a2[0]; i++)
		a[i+1] = -a2[i+1];	//此处为减
	return a;
}

int * poly_multi(int *a1, int *a2) {	//多项式相乘
	int i, j, n;

	n = a1[0] + a2[0];
	int *a = new int[n + 2]();	//申请存储块。并全部初始化为 0
	if (a == NULL) {
		cout << "程序出错：动态申请存储失败！\n";
		return NULL;
	}
	a[0] = n;	//在a[0]中保存多项式最高次的次数

	//多项式相乘：各项系数相乘，同次项的系数累加
	for (i = 0; i <= a1[0]; i++)
		for (j = 0; j <= a2[0]; j++)
			a[i + j + 1] += a1[i + 1] * a2 [j + 1];
	return a;
}

int main() {
	cout << "多项式处理\n" ;
	int *p1, *p2, *p3;

	cout << "输入多项式 p1 \n" ;
	p1 = poly_input();	//输入
	cout << "多项式 p1 = " ;
	poly_output(p1);	//输出

	cout << "\n输入多项式 p2 \n" ;
	p2 = poly_input();	//输入
	cout << "多项式 p2 = " ;
	poly_output(p2);	//输出

	p3 = poly_add (p1, p2);	//相加
	cout << "\n多项式 p1 + p2 = " ;
	poly_output(p3);
	delete []p3;

	p3 = poly_minus (p1, p2);	//相减
	cout << "\n多项式 p1 - p2 = " ;
	poly_output(p3);
	delete []p3;

	p3 = poly_multi (p1, p2);	//相乘
	cout << "\n多项式 p1 * p2 = " ;
	poly_output(p3);
	delete []p3;

	delete []p1;
	delete []p2;

	return 0;
}

