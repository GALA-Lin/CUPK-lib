/*********************************************************************
程序名：移除C/C++源程序中的注释
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-04-16
说明：

4-16.现有一个含有注释的源程序文件“test.cpp”，其主函数如下：
//int main() {    //test program
//    cout << "Hello, world!" << endl;    /* output */
//    cout << "// He said:\"this is not a comment.\" \n";
//    cout << '\"' << "/* That\'s OK. */" << '\"' << "\n";
//    return 0;
//}

//写一个程序读入该源程序文件，删除该源程序中的注释，并输出保存为
//“testout.cpp”。（提示：1、不仅要考虑“/*”、“*/”和“//”
//构成的注释，而且要考虑不要误判含有仿如注释的字符串或字符。
//2、分析问题，可以发现文件中可以划分出五种状态：普通源代码、
//块注释、行注释、字符串和字符；3、画出状态转换图；4、编程实现
//状态转换时，注意有多处需要用连续的两个字符进行判断。）
//（这个示例源程序是精心设计的，很容易出现误判）

//分析：以有限状态自动机模型来解答此题。
//分析可知有四种状态：普通源代码、块注释、行注释、字符串。
//相应的状态转换路径也可以写出来（图形说明见 prog4-14解析.ppt）：
//	在源代码状态遇到 /* ，转换为块注释；
//	在块注释状态遇到 */ ，转换为源代码；
//	在源代码状态遇到 // ，转换为行注释；
//	在行注释状态遇到 \n ，转换为源代码；
//	在源代码状态遇到 " 而且不是转义字符 \"，则转换为字符串；
//	在字符串状态遇到 " 而且不是转义字符 \"，则转换为源代码；
//单个字符不需要额外处理
//*********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	enum {SOURCE = 0, LINE = 1, BLOCK = 2, STRING = 3};
	//SOURCE code, LINE comment, BLOCK Comment, STRING
	int state = SOURCE; //STate
	int ch1, ch2;	//读入的字符（要根据连续的两个字符来判断）

	ifstream in("prog4-15-test.cpp");	//此处文件名与题目中的文件名不同，内容相同。
	if (!in) {	//检查输入文件流是否正常
		cout << "建立输入文件流出错。程序终止。\n";
		cout << "请编辑题目所需的源文件并保存在同一文件夹下。\n" ;
		exit (1);
	}
	ofstream out("prog4-testout.cpp");

	ch1 = ch2 = in.get();
	while ((ch2 = in.get()) != EOF) {	//每次从文件中读取一个字符存于 ch2 中
		//cout << (char)ch1 << " " << (char)ch2 << endl;	//debug
		if (state == SOURCE && ch1 == '/' && ch2 == '*') //在源代码状态遇到 /*，转换为块注释状态
			state = BLOCK;
		else if (state == BLOCK && ch1 == '*' && ch2 == '/') { //块注释 ->源代码
			state = SOURCE;
			ch1 = ch2 = in.get();//根据这两个字符判断并进行了一次状态转换。往后读取一个字符
			continue;	//块注释末尾字符不需打印
		} else if (state == SOURCE && ch1 == '/' && ch2 == '/') //源代码->行注释
			state = LINE;
		else if (state == LINE && ch2 == '\n') {	//行注释 ->源代码
			state = SOURCE;
			ch1 = ch2;	//当前的 ch1 不需要打印，而需要打印当前的 ch2
			ch2 = in.get();	//往后多读取一个字符
		} else if (state == SOURCE && ch1 != '\\' && ch2 == '"') //源代码 -> 字符串，要排除 \"
			state = STRING;
		else if (state == STRING && ch1 != '\\' && ch2 == '"') //字符串 ->源代码，要排除 \"
			state = SOURCE;

		//状态为 SOURCE 或 STRING时，则把读得的字符输出到屏幕和文件
		if (state == SOURCE || state == STRING ) {
			cout.put(ch1);
			out.put(ch1);
		}
		ch1 = ch2;
	}
	in.close();
	out.close();
	cout << "\n\n去除注释后的源代码保存在文件中：prog4-teout.cpp" << endl;
	return 0;
}
