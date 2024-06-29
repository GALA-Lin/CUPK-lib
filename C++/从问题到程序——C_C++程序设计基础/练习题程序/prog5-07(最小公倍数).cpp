/*********************************************************************
程序名：求两个数的最小公倍数
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-21
说明：
5-7.定义一个函数（函数取名为lcm），计算两个正整数的最小公倍数（least
common multiple）。提示：两数相乘的积除以这两个数的最大公约数就是最小
公倍数。然后编写主函数，求出从键盘上输入的两个正整数的最小公倍数。
*********************************************************************/
#include <iostream>
using namespace std;

//需要求得两个数的最大公约数，所以此处保留上一题所编写的一个求最大公约数的函数 
long gcdcycle2 (long m, long n) {	
//循环方式实现用辗转相减法求两个数的最大公约数 
	m = (m >= 0 ? m : -m);
	n = (n >= 0 ? n : -n);
	if (m == 0) return n;
	if (n == 0 || n == m ) return m;
		
	while(m != n)
		if(m > n ) m = m - n;
		else n = n -m;
	return m; 
}

long lcm (long m, long n) {
	return m * n / gcdcycle2(m, n);
}

int main() {

	cout << "求两个数的最小公倍数" << endl;
	// 要使用各种参数对两个函数分别进行测试 

	//两个普通参数，最大公约数不为 1 
	cout << "18  24 : " << lcm(18, 24) << endl;	
	cout << "24  18 : " << lcm(24, 18) << endl;
	//两个参数互质，最大公约数为 1 
	cout << "18   5 : " << lcm(18, 5) << endl;
	cout << " 5  18 : " << lcm(5, 18) << endl;
	//其中一个参数为 0 
	cout << "18   0 : " << lcm(18, 0) << endl;
	cout << " 0  18 : " << lcm(0, 18) << endl;
	//其中一个参数为负数
	cout << "-18  24 : " << lcm(-18, 24) << endl;	 
	cout << "24  -18 : " << lcm(24, -18) << endl;

	return 0;
}

