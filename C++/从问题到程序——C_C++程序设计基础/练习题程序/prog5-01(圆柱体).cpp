/*********************************************************************
程序名：求圆柱体的外表面积和体积
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-21
说明：
5-1.设圆柱体的底面半径为 r，高为 h，分别编写函数求圆柱体的外表面积和体积
（这两个函数分别命名为 SurfCyl 和 VolCyl ）。并编写主函数测试这两个函数。

解析：本题的目的是让读者练习编写函数的书写格式。题目本身并不难。

*********************************************************************/
#include <iostream>
using namespace std;

double SurfCyl(double r, double h) {	//计算圆柱体的表面积
	return 2 * 3.14159265 * r * r + 2 * 3.14159265 * r * h;	//两个底面积加上侧面积
}

double VolCyl(double r, double h) {
	return 3.14159265 * r * r * h;
}

int main() {
	double rad = 2.0, ht = 2.0; 	//定义表示底面半径和高度的变量并初始化

	cout << "Cylinder's radius = " << rad << "\theight = " << ht << endl;
	cout << "surface = " << SurfCyl(rad, ht) << " m^2\n";
	cout << "volume = " << VolCyl(rad, ht) << " m^3\n";
	return 0;
}


