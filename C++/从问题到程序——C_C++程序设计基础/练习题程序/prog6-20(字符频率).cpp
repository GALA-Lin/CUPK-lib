/*********************************************************************
程序名：各个英文字符的出现频率
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：6-20.写程序读入英文纯文本文件，统计各个英文字符（不区分大小写）
出现的次数，并打印输出横向的直方图，形像地显示各个字符在文件中出现的频率。

解题说明：前面部分就是练习题 6-4，后面部分是打印直方图
（类似于例6-09(多项式)）
*********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


void DrawHorizon(int len, int a[]);	//函数原型声明：绘制横向直方图
void DrawVertical(int len, int a[]);	//函数原型声明：绘制纵向直方图

int main () {
	int ch, i;
	//用一个含有 26 个元素的数组分别存储各个字符的出现次数
	int cs[26] = {0};  //第0号元素初始化为0，其它元素自动初始化为0

	char fname[100] = "prog6-20.txt";	//mytext.txt
	//用户应当事先编辑一个纯文本文件，并保存于与此程序同一文件夹下。
	ifstream infile(fname);	//!!定义输入文件流
	if (!infile) {	//如果文件不存在，则输入文件流会创建失败
		//cout << "程序出错：文件并不存在。请事先编辑并保存文件。" << endl;
		//exit(1);	//结束程序并向操作系统返回 1 ，表示程序出错结束。

		//本程序为了方便读者学习，如果文件不存在，则自动创建文件，以供后续读取。
		ofstream outfile(fname);	//定义输出文件流并绑定到文件
		//向输出文件流输出示例文字
		outfile << "One Small Step, One Giant Leap\n"
		        "On July 16, 1969, astronauts Neil Armstrong, Buzz Aldrin "
		        "and Michael Collins lifted off from Launch Pad 39A at NASA's "
		        "Kennedy Space Center in Florida on a journey to the Moon and "
		        "into history. Four days later, while Collins orbited the Moon "
		        "in the command module, Armstrong and Aldrin landed Apollo 11's "
		        "lunar module, Eagle, on the Moon's Sea of Tranquility, becoming "
		        "the first humans to set foot on the lunar surface.\n";
		outfile.close();	//关闭输出文件流
		cout << "已创建数据文件供读取。" << endl;
		infile.open(fname);	//用输入文件流打开新建的文件，这次应该肯定成功
	}
	//如果文件流创建成功，则继续执行。

	while ((ch = infile.get()) != EOF) {	//!!从输入文件流中读取字符
		putchar(ch);		//输出到屏幕以供查看
		if (isalpha(ch))   	//!!判断是英文字符
			cs[tolower(ch) - 'a']++;  //!!字符转换为小写，相应的计数器加1
	}

	for (i = 0; i < 26; ++i)
		cout << "Number of " << (char)(i + 'a') << ": " << cs[i] << endl;

	DrawHorizon(26, cs);	//绘制横向直方图
	DrawVertical(26, cs);	//绘制纵向直方图
	return 0;
}

void DrawHorizon(int len, int a[]) {
	cout << "\n字符出现频率纵向绘图（y值横向绘制）\n";
	//先求出数组元素中的最大值和最小值
	int amax = a[0], amin = a[0];	//定义用于记录最大值和最小值的变量并初始化为 a[0]
	for (int i = 0; i < len; i++) {
		amax = (a[i] > amax ? a[i] : amax);
		amin = (a[i] < amin ? a[i] : amin);
	}
	//cout << "amin = " << amin << ", amax =" << amax << endl;

	int maxlen = 60;	//字符终端窗口通常是25行80列，取一个合适的最大列数。
	int ix, jy, leny;
	for (ix = 0; ix < len; ix++) {
		cout << " " << char('a' + ix) << "|";
		leny = (int)(1.0 * a[ix] / (amax - amin) * maxlen);
		for (jy = 0; jy < leny; jy++)
			putchar('#');//输出一系列空格
		cout << "#\n";	//输出星号和回车
	}
	cout << setw(3) << amin << "-"
	     << setw(maxlen) << setfill('-') << amax << setfill(' ') << endl; //横轴标记
}

void DrawVertical(int len, int a[]) {
	cout << "\n字符出现频率纵向绘图（y值纵向绘制）\n";

	//先求出数组元素中的最大值和最小值
	int amax = a[0], amin = a[0];	//定义用于记录最大值和最小值的变量并初始化为 a[0]
	for (int i = 0; i < len; i++) {
		amax = (a[i] > amax ? a[i] : amax);
		amin = (a[i] < amin ? a[i] : amin);
	}
	//cout << "amin = " << amin << ", amax =" << amax << endl;

	//技巧：字符界面上只能逐行绘制，相当于是从曲线图形的上方往下方绘制；
	//所以在程序中是对 y 从大到小地绘制，对每个 y 值都检查一次哪个相应的 x 值与之对应。
	int maxheight = 18;	//字符终端窗口通常是25行80列，这里取一个合适的最大行数。
	for (int iy = maxheight; iy >= 0; iy--) {	//绘图 iy 值从大到小地变化
		cout << setw(6) << setprecision (2) << amin + (amax - amin) * iy / maxheight << "|";
		for (int jx = 0; jx < len; jx++) {	//检查数组中各元素的值是否与绘图 iy 值对应
			//把每个值映射到 [0, maxheight]，再与 iy 相比较
			if ((int)(1.0 * a[jx] / (amax - amin) * maxheight) >= iy) //绘柱状图，此处写为 >=
				cout << "█";	//输出方形的全角字符
			else
				cout << "  ";	//输出两个空格
		}
		cout << endl;
	}
	cout << "      +a b c d e f g h i j k l m n o p q r s t u v w x y z";//横轴标记
	return;
}
