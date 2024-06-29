/*********************************************************************
程序名：辗转相减求最大公约数
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-21
说明：
5-6.6.求最大公约数的另一种方法是辗转相减法，其递归定义为（其中m > 0, n > 0）：
              m              (m=n)
gcd(m, n) =   gcd(n, m) 	 (n>m)
              gcd(m-n, n)    (m>n)
利用这个定义，用递归和循环方式各写出一个求最大公约数的函数。
（用递归方法写出的函数取名为 gcdminus 和 gcdrecur2，循环方式写出的函数取名
为 gcdcycle2）
*********************************************************************/
#include <iostream>
using namespace std;

//用递归方法编写时，类似于教材中的示例，用两个函数完成所需的功能。
long gcdminus(long m, long n) {	
// m 和 n 皆不为 0 时用辗转相减法的递归方式计算最大公约数 
	if (m == n)
		return m;
	else if (n > m)
		return gcdminus(n, m);
	else
		return gcdminus(m - n, n);
	//上面是用 if 语句写成的，也可以用嵌套的条件表达式写成如下简短形式：
	//return m == n ? n : (n > m? gcdminus(n, m) : gcdminus(m -n, n);
}

long gcdrecur2(long m, long n) {
	if (m < 0) m = -m;
	if (n < 0) n = -n;
	
	//这里要单独考虑讨论 m 或 n 为 0 的情形 
	if (m == 0)
		return n;
	else if (n == 0)
		return m;
	else 
		return gcdminus(m, n);	//m 和 n 皆不为 0 的情形 
}

long gcdcycle2 (long m, long n) {	
//循环方式实现用辗转相减法求两个数的最大公约数 
	m = (m >= 0 ? m : -m);
	n = (n >= 0 ? n : -n);
	
	if (m == 0)
		return n;
	if (n == 0 || n == m )
		return m;
		
	while(m != n)
		if(m > n )
			m = m - n;
		else 
			n = n -m;
	return m; 
}

int main() {

	cout << "用辗转相减法求两个数的最大公约数" << endl;
	// 要使用各种参数对两个函数分别进行测试 

	cout << "递归方法：" << endl;
	
	//两个普通参数，最大公约数不为 1 
	cout << "18  24 : " << gcdrecur2(18, 24) << endl;	
	cout << "24  18 : " << gcdrecur2(24, 18) << endl;
	//两个参数互质，最大公约数为 1 
	cout << "18   5 : " << gcdrecur2(18, 5) << endl;
	cout << " 5  18 : " << gcdrecur2(5, 18) << endl;
	//其中一个参数为 0 
	cout << "18   0 : " << gcdrecur2(18, 0) << endl;
	cout << " 0  18 : " << gcdrecur2(0, 18) << endl;
	//其中一个参数为负数
	cout << "-18  24 : " << gcdrecur2(-18, 24) << endl;	 
	cout << "24  -18 : " << gcdrecur2(24, -18) << endl;
	

	cout << "循环方法：" << endl;
	//两个普通参数，最大公约数不为 1 
	cout << "18  24 : " << gcdcycle2(18, 24) << endl;
	cout << "24  18 : " << gcdcycle2(24, 18) << endl;
	//两个参数互质，最大公约数为 1
	cout << "18   5 : " << gcdcycle2(18, 5) << endl;
	cout << " 5  18 : " << gcdcycle2(5, 18) << endl;
	//其中一个参数为 0
	cout << "18   0 : " << gcdcycle2(18, 0) << endl;	 
	cout << " 0  18 : " << gcdcycle2(0, 18) << endl;
	//其中一个参数为负数
	cout << "-18  24 : " << gcdcycle2(-18, 24) << endl;	 
	cout << "24  -18 : " << gcdcycle2(24, -18) << endl;

	return 0;
}

