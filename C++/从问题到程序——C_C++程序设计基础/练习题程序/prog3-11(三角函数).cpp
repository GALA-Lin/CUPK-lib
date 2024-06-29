/*********************************************************************
程序名：循环输出 0~90 之间的三角函数值 
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
prog3-11.分别使用 while 结构、do...while 结构和 for 结构实现如下功能：
在 0～90 度之间每隔 5 度输出一行数据，整齐地打印出来该角度数以及它所
对应的正弦、余弦、正切、余切函数值。
（提示：1、注意把角度转化为弧度；2、用 cout<< 输出时可用“fixed”和
“setprecision”控制双精度数输出为固定位数；3、注意 0 度和 90 度时的
正切与余切函数值可能输出为 inf，这是合理的输出结果。）
*********************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int deg;	//角度值。设为 int 类型，以方便控制循环 
	double rad;	//弧度值
	

	cout << "deg\t正弦值  \t余弦值  \t正切值  \t余切值\n";	//首行说明 
	deg = 0; 	//使用 while 循环之前要对变量初始化
	while (deg <= 90) {
		rad = 3.1415927 * deg/180;	//对每个 deg 值，求出相应的 rad 值。
		//注意不要写成 deg / 180 * 3.1415927 。因为先计算 deg/180 会得到 0 。 
		cout << fixed << deg << "\t"  << sin(rad) << "\t" << cos(rad) << "\t"
			<< tan(rad) << "\t" << 1/tan(rad) << endl;
		deg += 5; 
	}
	//输出结果的首行说明中，每组文字仅占 8 位，显得较拥挤。 
	//后续输出的每组数据占 16 位，最后一行的 tan 值占24位，稍有错位，可以接受。
	//需要理解 fixed 控制输出的含义：让每组数据输出时所占位数为 8 的倍数。


	cout << "\ndeg\t正弦值  \t余弦值  \t正切值  \t余切值\n";
	deg = 0; 	//使用 do...while 循环之前要 重 新 对变量初始化
	do {
		rad = 3.1415927 * deg/180;
		cout << fixed << deg << "\t"  << sin(rad) << "\t" << cos(rad) << "\t"
			<< tan(rad) << "\t" << 1/tan(rad) << endl;
		deg += 5; 
	} while  (deg <= 90);
	

	cout << "\ndeg\t正弦值  \t余弦值  \t正切值  \t余切值\n"; 
	//deg = 0; 	//for 结构中需要对变量初始化，所以不必在此处初始化 
	for (deg = 0; deg <= 90; deg += 5){
		rad = 3.1415927 * deg / 180;
		cout << fixed << deg << "\t"  << sin(rad) << "\t" << cos(rad) << "\t"
			<< tan(rad) << "\t" << 1/tan(rad) << endl;
		//deg += 5; 	//for结构中对变量进行更新，所以 不 要 在此处更新 
	} 

	return 0;
}


