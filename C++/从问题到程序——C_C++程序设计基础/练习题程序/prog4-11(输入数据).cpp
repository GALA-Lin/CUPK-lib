/*********************************************************************
程序名：输入数据中的最大值、最小值和平均值
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-20
说明：
4-11.写一个程序，从标准输入设备（键盘）读入一系列整数（第一个数是数据
的项数，其余的是数据），输出其中最大的数和最小的数，并且输出所读入数据
的平均值。
*********************************************************************/
#include <iostream>
using namespace std;

int main () {
	int n, k, t, sum, max, min;
	max = INT_MIN; //最大值赋初值为最小整数
	min = INT_MAX; //最小值赋初值为最大整数

	cout << "请输入数据项数：";
	cin >> n;

	for (k = 1, sum = 0; k <= n; k++ ) {
		cout << "请输入第 " << k << " 个整数：";
		while (!(cin >> t))	{//允许重复输入，直到接收到一个整数为止
			cin.clear();
			cin.sync();
			cout << "重新输入：";
		}
		sum += t;
		if (t > max)
			max = t;
		if (t < min)
			min = t;
	}

	cout << "最大值：" << max << "\t最小值：" << min
	     << "\t平均值：" << (double)sum / n << endl;
	//注意：sum/n 为整数整除，所以要强制转换为 double 。

	return 0;
}

