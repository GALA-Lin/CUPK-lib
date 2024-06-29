/*********************************************************************
程序名：读取文本文件并对字符作分类统计
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-21
说明：
4-13.事先准备一个内容较多的英文纯文本文件（例如，从一个英文网页上复制
所有文字，粘贴到记事本中，然后保存为“mytext.txt”)，写程序读取该文件
中的全部字符，分别统计其中的英文字符、数字字符、标点符号和分隔符（空格、
制表符和回车符）的个数，把统计结果输出显示在屏幕上，并同时输出保存到
纯文本文件“output.txt”。
解析：参照教材上读取纯文本文件的示例程序，并使用字符分类函数。
*********************************************************************/
#include <iostream>
#include <sstream>	//字符串流
#include <fstream>	//文件流
using namespace std;

int main () {

    //用户应当事先编辑纯文本文件 mytext.txt ，并保存于与此程序同一文件夹下。
    ifstream infile("mytext.txt");	//!!定义输入文件流
    if (!infile) {	//如果文件不存在，则输入文件流会创建失败
        //cout << "程序出错：文件并不存在。请事先编辑并保存文件。" << endl;
        //exit(1);	//结束程序并向操作系统返回 1 ，表示程序出错结束。

        //本程序为了方便读者学习，如果文件不存在，则自动创建文件，以供后续读取。
        ofstream outfile("mytext.txt");	//定义输出文件流并绑定到文件
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
        ifstream infile("mytext.txt");	//再次定义输入文件流，这次应该肯定成功
    }
    //如果文件流创建成功，则继续执行。

    ofstream outfile("output.txt");
    if (!outfile) {
        cout << "创建输出文件 output.txt 失败！程序出错退出。";
        exit(1);
    }

    cout << "从文件读取字符并对英文字符、数字字符、标点符号和分隔符分类计数\n";
    int ch, alphas = 0, digits = 0, puncts = 0, spaces = 0;
    while ((ch = infile.get()) != EOF) {
        if (isalpha(ch))
            ++alphas;	//英文字符
        if (isdigit(ch))
            ++digits;	//数字字符
        if (ispunct(ch))
            ++puncts;	//标点符号
        if (isspace(ch))
            ++spaces;	//分隔字符(空格、制表符和回车符）
    }
    cout << "英文字符个数: " << alphas << endl;
    cout << "数字字符个数: " << digits << endl;
    cout << "标点符号个数: " << puncts << endl;
    cout << "分 隔 符个数: " << spaces << endl;

    outfile << "英文字符个数: " << alphas << endl;
    outfile << "数字字符个数: " << digits << endl;
    outfile << "标点符号个数: " << puncts << endl;
    outfile << "分 隔 符个数: " << spaces << endl;

    infile.close();
    outfile.close();
    return 0;

}

