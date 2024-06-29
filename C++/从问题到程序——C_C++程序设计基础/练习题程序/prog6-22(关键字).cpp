/*********************************************************************
程序名：统计源程序中的 ANSI C 语言关键字
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：
6-22.按照本章最后的讨论实现一个 ANSI C 语言关键字的统计程序。回答讨论中
所提出的问题。修改你的程序，使它能够正确处理任何 ANSI C 程序。

1.应该用多大的数组存标识符？语言对标识符长度没有限制，而前面考虑 getident
定义时加了长度限制参数。请考虑该参数的作用，如果遇到超长标识符，你的程序
（或其它书上的程序）能正确统计吗？什么时候会出问题？出什么问题？
2.遇到标识符超长时应该采取什么处理原则？怎样保证统计结果正确？你的程序
（或你读到的程序）正确处理了这一问题吗？
3.考虑ANSI C语言关键字，你注意到它们的长度都不超过 8 个字符这一重要特性了吗？
你的程序利用了这个特性吗？利用它能否使统计的工作更简单？能否及早发现某标识符
不可能是关键字？（提示：把getident实现为“取得下一长度不超过8的标识符”）。
4.最后，要使你的程序完善，还必须考虑C/C++ 程序中的各种成分。如注释、字符常量、
字符串常量等。
仔细分析这些问题，修改你的程序，使它在任何情况下都能够立于不败之地。这绝不是
很容易的事，但是在努力做到这一点的过程中，你会学到许多东西。

解题思路：
要解答这个题目，首先需要自己准备一个合适的测试文件。该测试文件中应该有
一些正常的含有关键词的语句，以供本程序识别并统计，同时该文件的块注释、
行注释和字符串中也要故意包含一些关键词，要让本程序把它们排除不作统计。
例如这样的语句：
const int LEN = 100;	//const
char str[LEN] = "keywords such as \"goto\" and \"register\" are seldom used\n";
//"union" and "volatile" are also seldom used.
还要包含一些特殊的容易引起误判的语句，例如：
double doublexyz = 200 / LEN;
double registerregister = doublexyz/LEN;
*********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream inFile;    //全局的输入文件流

int getident(int limit, char id[]) {	//教材上的版本，不能识别注释和字符串
	int ch = ' ', i = 0;
	while (ch != EOF) {
		i = 0;
		while ((ch = inFile.get()) != EOF && !isalnum(ch) && ch != '_')
			;    //ch不是字母或数字字符或下划线，跳过
		if (ch == EOF) break;

		id[i] = ch;    //首字符
		while ((ch = inFile.get()) != EOF && (isalnum(ch) || ch == '_') )
			id[++i] = ch;    //ch是字母或数字字符或下划线，添加进字符串
		id[++i] = '\0';    //添加空字符作为结束标志
		break;
	}
	return i;
}

int getident2(int limit, char id[]) {	//改进版本，能识别注释和字符串
	int ch = ' ', ch2 = ' ', i = 0;
	while (ch != EOF) {
		i = 0;
		while ((ch=inFile.get()) != EOF && !isalnum(ch) && ch!='_' && ch!='/' && ch!='\"')
			;    //ch不是如下字符则跳过：字母、数字、下划线、正斜杠、双引号
		if (ch == EOF)
			break;
		cout << (char)ch << "\n";	//!!!debug

		if (ch == '\"'){ //如果读得是一个双引号（字符串开始），需要跳过
			ch2 = ch;	//用ch2 保存 ch
			//读到下一个单独的双引号（且前一个不是斜杠）则为字符串结束。
			while (((ch = inFile.get()) != EOF) && !(ch2 != '\\' && ch =='\"') )
				ch2 = ch;
			continue;	//结束此次循环，开始下一次循环
		}

		if (ch == '/')	{//如果读得的是一个正斜杠，则多读一个字符，用于判断是行注释或块注释
			ch2 = ch;
			if ((ch = inFile.get()) == EOF )	//则多读一个字符（顺便要判断它是否EOF）
				break;
			if (ch2 == '/' && ch == '/') {	//行注释，则一直读到行尾
				while ((ch = inFile.get()) != EOF && ch != '\n' )	//
					;    //跳过字符，直到行尾
				continue;//结束此次循环，开始下一次循环
			}else if  (ch2 == '/' && ch == '*') {	//块注释，则一直读到有星号和斜杠
				while ((ch = inFile.get()) != EOF && !(ch2 == '*' && ch == '/')) {
					ch2 = ch;
				}
				continue;	//结束此次循环，开始下一次循环
			}
			if (!isalnum(ch) && ch != '_')   //如果不是字母、数字或下划线，则结束此次循环
				continue;
			//否则只是结束当前 if 语句，而继续此次循环
		}

		id[i] = ch;    //首字符
		//首字母合法，则读入一个最长8个字符的标识符
		while (i < 7 && (ch = inFile.get()) != EOF && (isalnum(ch) || ch == '_') )
			id[++i] = ch;    //ch是字母或数字字符或下划线，添加进字符串
		id[++i] = '\0';    //添加空字符作为结束标志
		if (i >= 8) {	//如果读入的标识符长度刚好为 8 字符，则应该额外处理
			//多读一个字符，如果是字母、数字或下划线，则为超长标识符。
			if ((ch = inFile.get()) != EOF && (isalnum(ch) || ch == '_') ) {
				i = 0;
				id[0] = '\0';	//这不可能是关键词，所以把它改为空串
				while ((ch=inFile.get()) != EOF && (isalnum(ch) || ch =='_') )
					;    //读入并丢弃能构成标识符的后续字符
				continue;	//结束此次循环，开始下一次循环
			}
		}
		break;	//读得一个合法标识符，结束循环
	}
    return i;
}

int main() {
	//打开文件
	char filename[56] = "prog6-22test.cpp";    //自行准备一个示例源程序
	//cout << "请输入文件名: ";    //或在运行时输入一个源程序文件名
	//cin >> filename;
	inFile.open (filename); //打开文件输入流
	if (!inFile) { //如果打开文件失败，则 infile 得到一个零值
		cout << "错误：无法打开文件 " << filename << "。程序终止。\n";
		exit(1);    // 显示错误信息并退出程序。
	} else
		cout << "已打开文件并读取：" << filename << endl;

	char keywords[32][9] = {
		"auto",  "break",  "case",  "char",  "const",  "continue",  "default",
		"do",  "double",  "else",  "enum",  "extern",  "float",  "for",
		"goto",  "if",  "int",  "long",  "register",  "return",  "short",
		"signed",  "sizeof",  "static",  "struct",  "switch",  "typedef",
		"union", "unsigned",  "void",  "volatile",  "while"
	};

	int counters[32] = {0};
	int MAXLEN = 20;
	char str[MAXLEN];
	int n;
	//while (getident(MAXLEN, str) > 0) {	//读得标识符（教材上的版本）
	while (getident2(MAXLEN, str) > 0) {	//读得标识符（改进后的完善版本）
		for (n = 0; n < 32; ++n)
			if (strcmp(str, keywords[n]) == 0) {
				counters[n]++;
				break;
			}
	}


	for (n = 0; n < 32; ++n)
		cout << keywords[n] << "\t" << counters[n] << endl;

	inFile.close();

	return 0;
}


