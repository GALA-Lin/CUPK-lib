/*********************************************************************
程序名：长度分别为1 ~ 20的单词的出现频率
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：6-21.写程序读入英文纯文本文件，并统计其中长度分别为1 ~ 20的单词
（更长的单词丢弃不管）的出现次数。设法打印输出纵向的直方图），形像地
显示各种长度的单词在文件中的出现频率。

解题说明：参考例题 6-16“找出文件中最长的词”实现读取单词，参考练习题
6-18实现对不同长度的单词分别计数。
（如下源代码中，带有 !!! 注释的语句是关键语句。另有一些冗余语句没有删除）
*********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

void DrawVertical(int len, int a[]);	//函数原型声明：绘制纵向直方图

int main () {

	//用一个含有 20 个元素的数组分别存储长度为 1 ~ 20 的单词的出现次数
	int cs[20] = {0};  //第0号元素初始化为0，其它元素自动初始化为0

	char filename[20] = "GPL.txt";  //定义字符数组以存储文件名
	//事先应该准备一个较大的文件，里面有一些行的文字长度较大。
	//例如从如下网页复制并保存为 GPL.txt ：http://www.gnu.org/licenses/gpl-3.0.html
	ifstream infile(filename);  //定义文件输入流并关联到文件
	if (infile)
		cout << "Reading from file: " << filename << endl;
	else {
		cout << "ERROR: can't open input file " << filename << endl;
		exit(1);
	}

	const int MAXLEN = 256;//假设英文单词最大长度为 256)
	char word[MAXLEN], maxword[MAXLEN];	//当前读入的单词，最长的单词；
	int len, maxlen = 0;	//当前单词长度，最大单词长度

	//此处选取【例4-18】中读取单词的第三种写法，其中并不需要作状态转换。
	int ch = ' ', counter = 0;
	while (ch != EOF) {
		while ((ch = infile.get()) != EOF && !isalnum(ch))
			//从文件中读取字符，当ch是分隔字符时重复读取
			;    //空循环体
		if (ch == EOF) break;
		++counter;	//单词计算

		//上面循环结束时已读得一个非空隔字符
		len = 1;	//单词长度
		word[len - 1] = ch;
		while ((ch = infile.get()) != EOF && isalnum(ch)) {
			//从文件中读取字符，当 ch 是字母或数字字符重复读取
			//把原有的空循环体改写为对单词长度计算
			len++;
			word[len-1] = ch;
		}
		//读完一个单词，添加相应的处理
		word[len] = '\0';	//字符数组末尾添加空字符
		if (len <= 20) 	//!!! 不同长度的单词计数
			cs[len - 1] ++; 	//!!!

	}
	infile.close(); //关闭文件

	for (int i = 1; i <= 20; ++i)	//!!!
		cout << "words with length of " << i << ": " << cs[i-1] << endl;

	DrawVertical(20, cs);	//!!!绘制纵向直方图

	return 0;
}

void DrawVertical(int len, int a[]) {
	cout << "\n不同长度的单词出现频率纵向绘图（y值纵向绘制）\n";

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
			if ((int)(1.0 * a[jx]/(amax - amin) * maxheight) >= iy)//绘柱状图，此处写为 >=
				cout << "█";	//输出方形的全角字符
			else
				cout << "  ";	//输出两个空格
		}
		cout << endl;
	}
	cout << "      + 1 2 3 4 5 6 7 8 91011121314151617181920";//横轴标记
	return;
}
