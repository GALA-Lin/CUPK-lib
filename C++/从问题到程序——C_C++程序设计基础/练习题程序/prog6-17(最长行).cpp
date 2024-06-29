/*********************************************************************
程序名：输出文件中的文字长度最长的那一行
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：6-17. 正文中例6-17的程序（求文件中最长行）有局限性，它要求文件中
各行长度都不超过 MAXLEN 个字符。请改进该程序，使之能处理每行文字长度不受
限制的文件，能正确输出最长行的长度，输出的文字长度最长的那一行（如果该行
超过数组容量，则输出该行的前面一部分）。
*********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main () {
    const int MAXLEN = 1024;
    char line[MAXLEN + 1], maxline[MAXLEN + 1];
    int ch, n, max = 0; // 记录当前行和最长行的长度

    char filename[20] = "GPL.txt";  //定义字符数组以存储文件名
    //事先应该准备一个较大的文件，里面有一些行的文字长度较大。
	//例如从如下网页复制并保存为 GPL.txt ：http://www.gnu.org/licenses/gpl-3.0.html
	//该文件的最长行的字符个数为 937。

    ifstream inFile (filename);	//定义输入文件流并绑定到文件
    if (!inFile) { //如果打开文件失败，则 infile 得到一个零值（空指针）
        cout << "错误：未找到数据文件 " << filename << " 。\n";
        cout << "请制作此文件并把它存放在本程序同一文件夹下。\n\n" ;
        exit(1);    // 打开文件失败，则显示错误信息并退出程序。
    }
    cout << "Reading from file: " << filename << endl << endl;
    //while (inFile.getline(line, MAXLEN))
	//getline函数受限于只能接收指定最大长度的字符串，所以弃用此函数，改用 get() 函数。


	int i = 0;	//每行的字符个数（存放到字符数组中时，下标为 i-1
	while ((ch = inFile.get()) != EOF){	//最外层循环是从文件中读取字符，并以 EOF 为结束；
		i++;
		if (ch != '\n') {	// 以 '\n' 作为段落结束标志
			if (i <= MAXLEN ) 	//字符个数小于 MAXLEN 时，存放到 line 数组之中
				line[i - 1] = ch;
		} else {// 遇上了 '\n'，读完了一行
			if (i <= MAXLEN)	//数组末尾添加空字符
				line[i] = '\0';
			else
				line[MAXLEN] = '\0';
		    if (i > max) {	//记录最大行。注意，此处是 i 保存着当前行的文字长度。
            	strcpy(maxline, line);	//把 line 所记录的字符串存放到 maxline
            	max = i - 1;	//本行字符个数为 i - 1，存放到 max
            	//cout << line << endl << max << endl << endl;	//debug
        	}
			i = 0; //准备读取新的一行
    	}
	}
    inFile.close(); //关闭文件

    cout << "Longest line: \n" << maxline << endl;
    cout << "\nLength: " << max << endl;

    return 0;
}


