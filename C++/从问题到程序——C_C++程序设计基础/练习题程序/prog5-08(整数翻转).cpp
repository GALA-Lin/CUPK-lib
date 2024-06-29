/*********************************************************************
程序名：整数翻转
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-21
说明：
5-8.请分别用循环方式和递归方式编写函数，将一个整数 n 从低位到高位翻转成
另一个整数（例如输入1523变成3251）。（本题用循环方式容易，用递归方式较难）
*********************************************************************/
#include <iostream>
using namespace std;

int RevIntCycle (int n) {	//用循环方式翻转整数 n
	int t = 0;
	while(n != 0) {
		t = 10 * t + (n % 10);
		n = n / 10;
	}
	return t;
}

int RevIntRecur (int n, int t) {	//用递归方式翻转整数 n
	if(n == 0)
		return t;
	else
		return RevIntRecur(n / 10, t * 10 + n % 10);
}

//int RevIntRecur0 (int n, int t) {	//用递归方式翻转整数 n，外层函数 
//		return RevIntRecur(n, 0);
//}


int main() {

	cout << "翻转整数" << endl;
	// 要使用各种参数对两个函数分别进行测试

	int n;
	//cout << "请输入整数 n : ";
	//cin >> n;
	n = -982776;	//直接给出示例数据 
	
	cout << n << " 翻转为：" << RevIntCycle(n) << endl;	//循环方式 
	
	cout << n << " 翻转为：" << RevIntRecur(n, 0) << endl;	//递归方式
	//注意，在调用 RevIntRecur 时，第2个参数必须指定为 0 。
	//如果不想这样调用，就需要添加一个外层函数 RevIntRecur0，它只需1个参数。 
	//实际上是在其内部给 RevIntRecur 添加第2个参数。 
	//cout << n << " 翻转为：" << RevIntRecur0(n) << endl;
	
	return 0;
}

