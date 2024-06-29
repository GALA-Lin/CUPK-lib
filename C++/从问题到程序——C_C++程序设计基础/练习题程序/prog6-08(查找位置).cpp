/*********************************************************************
程序名：查找元素在数组中的出现位置
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-20
说明：6-9.写一个函数，它判断一个整数（或浮点数）是否在一个数组中出现。
如果出现，给出第一次出现位置的下标；不出现时给出值 -1。
*********************************************************************/

#include <iostream>
using namespace std;

int find(int len, int array[], int target) {	//在长度为 len 的数组 array 中查找 target
	int i;
	for (i = 0; i < len; i++)
		if (array[i] == target)	//找到 k 则直接返回位置为 i
			return i;
	//循环结束都未找到 k
	return -1;
}

int main() {
	int a[] = {3, 2, 5, 8, 10, -4, 9, 1, 15};	//定义数组并初始化为示例数据
	int len = sizeof(a) / sizeof(a[0]);	//求出数组的长度

	cout << "在数组中查找  2 ：" << find(len, a, 3) << endl;
	cout << "在数组中查找 -4 ：" << find(len, a, -4) << endl;
	cout << "在数组中查找 15 ：" << find(len, a, 15) << endl;
	cout << "在数组中查找 11 ：" << find(len, a, 11) << endl;

	return 0;
}

