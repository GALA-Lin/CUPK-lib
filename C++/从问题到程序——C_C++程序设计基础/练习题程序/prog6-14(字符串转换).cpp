/*********************************************************************
程序名：数字字符串转换成整数
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-22
说明：6-14.（1）写一个把数字字符串转换成整数的函数，它只有一个字符数组
参数。（2）类似地，写一个把合乎C/C++ 语言实数文字量形式的字符串转换成
一个双精度数的函数。
*********************************************************************/
#include <iostream>
using namespace std;

int str2int(const char str[]) {
	int num = 0;	//整型数字
	int sign = 1;	//正负号
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9')
			num = num*10 + str[i] - '0';
		if (str[i] == '-')
			sign = -1 * sign;
		//不能在这里直接设置 num 的正负。原因是 num 初始值为 0 ，不能对 0 设置正负。
	}
	num = num * sign;
	return num;
}

double str2double(const char str[]){	//注意，返回值为 double 类型
	double num = 0;	//双精度型数字
	int sign = 1;	//正负号
	int isfract = 0;	//是否为小数部分
	double fract = 0.1;	//小数部分的权
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '.')
			isfract = 1;	//后续为小数部分
		if (str[i] >= '0' && str[i] <= '9'){
			if (!isfract)	//整数部分
				num = num*10 + str[i] - '0';
			else{ 	//小数部分
				num = num + (str[i] - '0') * fract;
				fract = fract * 0.1;
			}
		}
		if (str[i] == '-')
			sign = -1 * sign;
		//不能在这里直接设置 num 的正负。原因是 num 初始值为 0 ，不能对 0 设置正负。
	}
	num = num * sign;
	return num;
}

int main () {
	char str[100];
	cout << str2int("1a2b3c4d") << endl;
	cout << str2int("-1a2b3c4d") << endl;

	cout << str2double("3.1415926d") << endl;
	cout << str2double("-3.1415926d") << endl;

	return 0;
}


