/*********************************************************************
程序名：把数组写法改写为指针写法
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2022-05-26
说明：
7-5.把第6章中用数组方式定义的函数例6-16（字符串复制）改写为用指针运算的方式定义。
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

void stringcopy1(char *s, const char *t) {  //字符串复制，版本1
	int i = 0;
	while (*(t + i) != '\0') {
		*(s + i) = *(t + i);
		++i;
	}
	*(s + i) = '\0';
}

void stringcopy2(char *s, const char *t) {  //字符串复制，版本2
	int i = 0;
	while ((*(s + i) = *(t + i)) != '\0')
		++i;
}

void stringcopy3(char *s, const char *t) {  //字符串复制，版本3
	int i = 0;
	while (*(s + i) = *(t + i)) // 利用赋值表达式的值作为逻辑值
		++i;
}


int main() {
	//定义数组并以示例数据初始化
	char s[100] = "Hello, world!";
	char s1[100], s2[100], s3[100];
	cout << "s: " << s << endl;

	stringcopy1(s1, s);
	cout << "s1: " << s1 << endl;

	stringcopy2(s2, s1);
	cout << "s2: " << s2 << endl;

	stringcopy3(s3, s2);
	cout << "s3: " << s3 << endl;

	return 0;
}




