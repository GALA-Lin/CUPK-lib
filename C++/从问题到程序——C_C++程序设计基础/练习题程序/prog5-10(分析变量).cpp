/*********************************************************************
程序名：分析变量的性质
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-21
说明：
5-10.对如下程序先思考运行时的输出结果，然后在计算机上编辑并运行该程序，
看看屏幕实际输出结果与自己思考的结果是否一致。如果不一致，请使用集成开发
环境中的动态调试工具（参见“4.5.2  使用调试工具除错”）逐句运行，并实时
查看各个变量的值，以便深入理解局部变量、全局变量和静态局变量的性质。
*********************************************************************/
#include <iostream>
using namespace std;

int a = 3, b = 4; 	//外部变量

void fun(int x1, int x2) {
	static int st = 0;
	cout << x1 + st << "\t" << x2 + st << "\n";
	cout << a + st << "\t" << b + st << "\n";
	st++;
	return;
}

int main() {
	int a = 50, b = 60; 	//局部变量
	cout << a << "\t" << b << "\n";
	fun(a, b);	//第一次调用
	fun(a, b);	//第二次调用
	fun(a, b);	//第三次调用
	return 0;
}

/*********************************************************************
实际运行结果为：
50      60
50      60
3       4
51      61
4       5
52      62
5       6

解释如下：
1、在 main 函数中定义了局部变量 a 和 b，它们遮蔽了全局变量 a 和 b，因此在
main 函数中用 cout << 输出的是这两个局部变量。
2、在 main 函数中执行函数调用语句 fun(a, b) 时，局部变量 a 和 b 的值被分别
复制给了形参 x1 和 x2。这两个形参的值分别为 50 和 60。而在函数 fun 中使用
变量名 a 和 b 时，是使用具有这两个名字的全局变量。
3、在函数 fun 中定义了静态局部变量 st ，在程序刚开始时（注意，不是该函数被
调用时）就被初始化为 0。在函数 fun 第一次被调用时，变量 st 具有初值 0，然后
执行语句 st++; 时，其值变为 1 ，而且该值会保持着，不会随着函数的结束而被撤
消。在函数 fun 第二次被调用时，st 的值为 1，然后自增变为 2；在函数第三次被
调用时，st 的值为 2，然后再自增变为 3。
*********************************************************************/

//附带说明：练习题 5-11 和 5-12 是整理原有代码并练习相应操作，请读者自行练习。

