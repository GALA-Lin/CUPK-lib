/*********************************************************************
程序名：猜单词
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
7-12.写一个“猜单词”的小游戏程序，它内部存储着一些英语单词（在写程序时给定
单词集合）。程序运行中每次由这些单词中随机地选出一个，并以该单词所含字母
数量显示一系列的“*”字符，要求游戏者猜。游戏者反复猜测某些字母是否出现在
待猜单词中，程序给出应答（例如对于待猜单词“green”，当游戏者猜测字母“e”
时，程序给出“**ee*”）。直至游戏者猜出这个单词（或者放弃）。
**********************************************************************/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

int readword(int maxwords, char words[][20]) { //从现有文件中读入单词
	char ch;
	int i = 0, j = 0;
	ifstream infile("words.txt");//文件流
	if(!infile) {
		printf("程序出错：words.txt 不能打开！\n");
		return 0;
	}
	while((ch = infile.get()) != EOF && i < maxwords) {
		if(ch != ' ' && ch != '\n') {	//同一个单词中的字母
			words[i][j] = ch;
			j++;
		} else if (j > 0){	//当前单词的字母数大于 1
			i++;
			j = 0;
		}
	}
	infile.close();
	return i;//返回读入单词数
}

int main() {
	cout << "猜单词游戏\n";

	int i, j, k, n, maxlen = 0;
	char words[100][20];	//待猜单词集：最多 100 个单词，每个词最长为20

	//提供两种设置猜单词的方法。当然实际操作中只能选用其中一种。
	//设置待猜单词集合方法一：准备一些示例单词，复制到待猜单词集
	const char *examples[] = {"red", "green", "blue", "yellow", "purple", "white", "gray", "black"};
	n = sizeof(examples) / sizeof(examples[0]);	//存储单词总数，便于play随机选择单词编号
	for (i = 0; i < n; i++)
		strcpy (words[i], examples[i]);

	//设置待猜单词集合方法二：事先准备一个存储单词的文件，从该文件中读取
	//n =  readword(100, words);	//使用 readword 函数从文件中读取单词

	cout << "待猜单词集合中的单词数目：" << n << endl;
	for (i = 0; i < n; i++)		//求出单词最大长度
		if (strlen(words[i]) > maxlen)
			maxlen = strlen(words[i]);
	cout << "单词最大长度：" << maxlen << endl;

	cout << "\t欢迎进入猜单词游戏！\n";

	int chok;	//chok标记是否猜对字母
	int temp;	//存储随机单词编号
	int len;	//所猜单词长度

	char guess;	//用户猜测的字母
	char str[30];//待猜单词
	char guessword[30];//和原来单词对比

	char tt = 'Y';	//是否继续猜
	int maxtime = 15;	//允许的猜测次数
	int correct, wrong;//统计对与错的次数
	double grade;	//记录成绩

	srand((unsigned)time(NULL));	//初始化随机数种子
	while(tt == 'Y' || tt == 'y') { //重复游戏
		cout << "*************游戏开始*************\n";
		correct = 0;
		wrong = 0;//每次猜之前初始化对与错的次数

		temp = rand() % n;	//取随机数
		strcpy(str, words[temp]);
		//cout << str << endl;	//debug

		len = strlen(str);
		for (i = 0; i < len; i++) //初始化字符串全部为 '*' 字符
			guessword[i] = '*';
		guessword[len] = '\0';
		temp = rand() % len;
		guessword[temp] = str[temp];	//随机显示其中某个字符

		for(i = 1; i <= maxtime; i++) { //未达次数限制，循环猜测
			cout << "待猜单词: " << guessword << endl;
			chok = 0;
			cout << "猜字母: ";
			cin >> guess;
			guess = tolower(guess);
			for(j = 0; j < len; j++) {	//替换字符
				if(guess == str[j]) {
					guessword[j] = guess;
					chok = 1;
				}
			}
			if(chok) { //chok为1，猜测字母正确
				cout << "正确：" << endl;
				if (strchr(guessword, '*') == NULL ) {//检验字母是否全部猜出(是否还有星号)
					cout << "恭喜你猜对了: " << guessword << endl;
					break;
				}
			} else {
				cout <<"猜测错误，还可以猜 " << maxtime - i << "次\n";
				wrong++;
			}
		}
		if (strchr(guessword, '*') == NULL)
			correct = (i - wrong);//正确次数不方便直接统计，故用总数减错误次数
		else
			correct = (maxtime - wrong);
		cout << "\t本轮结束！待猜单词为 " << str << endl;
		cout << "猜测字母正确个数：" << correct << "  错误个数：" << wrong << endl;
		cout << "是否继续？(Y/N) ";
		cin >> tt;
	}

	return 0;
}




