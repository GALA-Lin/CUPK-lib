/*********************************************************************
程序名：查找元素在数组中的出现次数
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-20
说明：6-10.写一个函数，它统计出一个整数在一个数组（都通过参数提供）里出现的次数。
*********************************************************************/

#include <iostream>
using namespace std;

int occurrence(int len, int array[], int target) {
//函数功能：计算整数 target 在一个长度为 len 的整型数组 array[]中的出现次数
	int i, k = 0;
	//拿 target 与数组中的元素逐个进行比较
	for (i = 0; i< len; i++)
		if ( target == array[i])
			k ++ ;
	return k;
}

int main() {
	int a[] = {1, 2, 3, 4, 5, 6, 2, 3, 4, 3, 4,3}; //定义数组 a 并初始化
	int len = sizeof(a)/sizeof(a[0]);

	int t = 3;
	cout << t << " 在数组中的出现次数: " << occurrence(len, a, t) << endl;

	return 0;
}
