/*********************************************************************
程序名：读入一个英文纯文本文件，输出其中最长的词
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：6-18.写一个程序，它读入一个英文纯文本文件，输出其中最长的词（参考
前面章节对“词”的定义，你也可以自己规定，例如规定词是由字母开头的字母
数字序列）。

解题说明：1、参考教材第 4 章中【例4-18】“单词计数和有穷自动机的使用”
示例程序，实现从文件中读取单词；该例题中提供了三种读取单词的写法，应当
选择其中一种方便于改写以对单词计算长度的写法。2、然后参考第6章【例6-17】
“读取纯文本文件，输出其中最长的一行”，实现求出最长单词。
*********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main () {
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

	const int MAXLEN = 256;		//假设最大可达 256
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
		//cout << word << "\t" ;	//debug
		if (len > maxlen) {
			strcpy(maxword, word);
			maxlen = len;
			cout << word << endl;	//debug
		}
	}
	infile.close(); //关闭文件

	cout << "\nLongest word: " << maxword << endl;
	cout << "\nLength: " << maxlen << endl;
	//cout << "\ntotal words: " << counter << endl;
	return 0;
}

