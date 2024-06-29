/*********************************************************************
程序名：字符指针数组
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
7-16.准备一个只含英文字符的纯文本文件，其中包含至多100个长度不超过80个
字符的行。写一个程序，它逐行读取文件内容，将各行文字依次保存到动态分配
的存储块中，并用一个字符指针数组依次指向这些存储块。读取完毕之后，先
输出其中长度不超过40个字符的行，而后输出其它行。（本题也可以用两维字符
数组解答）
*********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main () {
	ifstream infile;	//定义输入文件流（尚未绑定到文本文件）
	int ch, i, j, num;

	//用户应当事先编辑纯文本文件，并保存于与此程序同一文件夹下。
	char fname[] = "prog7-16.txt";
	infile.open(fname);	//用输入文件流打开文件并与之绑定。
	if (!infile) {	//如果文件不存在，则输入文件流会创建失败
		//cout << "程序出错：文件并不存在。请事先编辑并保存文件。" << endl;
		//exit(1);	//结束程序并向操作系统返回 1 ，表示程序出错结束。

		//本程序为了方便读者学习，如果文件不存在，则自动创建文件，以供后续读取。
		ofstream outfile(fname);	//定义输出文件流并绑定到文件
		//向输出文件流输出示例文字
		outfile << "One Small Step, One Giant Leap\n"
		        "On July 16, 1969, \n "
		        "astronauts Neil Armstrong, Buzz Aldrin and Michael Collins \n"
		        "lifted off from Launch Pad 39A \n"
		        "at NASA's Kennedy Space Center in Florida \n"
		        "on a journey to the Moon and into history.\n"
		        "Four days later, while Collins orbited the Moon in the command module, \n"
		        "Armstrong and Aldrin landed Apollo 11's lunar module, Eagle, \n"
		        "on the Moon's Sea of Tranquility, \n"
		        "becoming the first humans to set foot on the lunar surface.";
		outfile.close();	//关闭输出文件流
		cout << "已创建数据文件 " << fname << " 供读取。" << endl;
		infile.open(fname);	//再次定义输入文件流，这次应该肯定成功
	}
	//如果文件流创建成功，则继续执行。

	cout << "（1）用一个字符指针数组，将字符行保存在通过动态分配的存储块里\n";
	char *ps[100] = {NULL};	//定义100个字符指针，并全部初始化为 NULL。
	char str[80];	//临时性的字符数组
	i = j = num = 0;
	while (i < 100) {	//最多处理 100 行，内部遇到 EOF 时使用 break 结束循环）
		ch = infile.get();
		//putchar(ch);	//debug
		if (ch != '\n' && ch != EOF && j < 80)	//同一行
			str[j++] = ch;
		else {	//行尾或文件末尾
			str[j] = '\0';	//字符串末尾添加空字符
			ps[i] =  new char[j + 1]; 	//!!! 动态申请分配内存
			strcpy(ps[i], str);
			//cout << ps[i] << endl; 	//!!! 注意输出 ps[i] 的写法
			i++;
			j = 0;
		}
		if (ch == EOF)
			break;
	}
	infile.close();

	num = i;
	cout << "总行数：" << num << endl;
	cout << "字符数不超过 40 的行：\n";
	for (i = 0; i < num; i++) {
		if (strlen(ps[i]) <= 40)
			cout << ps[i] << endl;
	}
	cout << "其它行：\n";
	for (i = 0; i < num; i++) {
		if (strlen(ps[i]) > 40)
			cout << ps[i] << endl;
	}

	for (i = 0; i < num; i++)
		delete []ps[i];	//!!!释放动态申请的内存

	cout << "\n（2）用两维字符数组保存字符行\n";
	char line[100][80];	//题目中已说明，文件中至多 100 行，每行的长度不超过 80 个字符
	i = 0, j = 0, num = 0;
	infile.open(fname);	//打开文件
	while (i < 100) {	//最多处理 100 行，内部遇到 EOF 时使用 break 结束循环）
		ch = infile.get();
		//putchar(ch);	//debug
		if (ch != '\n' && ch != EOF && j < 80)	//同一行
			line[i][j++] = ch;
		else {	//行尾或 EOF
			line[i][j] = '\0';	//字符串末尾添加空字符
			i++;
			j = 0;
		}
		if (ch == EOF)
			break;
	}
	infile.close();	//读取完毕，关闭文件

	num = i;	//总行数
	cout << "总行数：" << num << endl;
	cout << "字符数不超过 40 的行：\n";
	for (i = 0; i < num; i++) {
		if (strlen(line[i]) <= 40)
			cout << line[i] << endl;
	}
	cout << "其它行：\n";
	for (i = 0; i < num; i++) {
		if (strlen(line[i]) > 40)
			cout << line[i] << endl;
	}

	return 0;
}
