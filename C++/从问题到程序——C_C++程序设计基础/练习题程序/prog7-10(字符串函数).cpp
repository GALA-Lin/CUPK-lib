/*********************************************************************
程序名: 字符串相关函数
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期: 2021-06-03 08:46
说明:
7-10. 练习使用标准库中的字符串相关函数：（1）把本节中测试使用自编函数 stringlen 和
stringcopy 的代码片段合并写在一个程序中，并把调用这两个自编函数的语句都改为调用标
准库函数 strlen 和 strcpy；（2）把测试标准库函数 strchr 和 strstr 的代码片段也合
并在这个程序中；（3）自行编写一些语句，练习使用 strcat 和 strcmp。
*********************************************************************/

#include <iostream>
using namespace std;

int main() {
//（1）把本节中测试使用自编函数 stringlen 和 stringcopy 的代码片段合并写在一个程序中，
//并把调用这两个自编函数的语句都改为调用标准库函数 strlen 和 strcpy；
    cout << strlen("Hello, world!") << endl;  //以常量字符串作为参数
    char line[] = "Hello, my friends!" ;  //定义字符数组并初始化为字符串
    cout << strlen(line) << endl;  //以存储了字符串的字符数组作为参数

    const int NUM = 100;
    char str[NUM] = "", dest[NUM] = "";  //定义字符数组并初始化为空串
    strcpy(str, "Welcome to China!");  //把常量字符串复制到字符数组src
    cout << "str: " << str << endl;
    strcpy(dest, str);  //从字符数组str中复制字符串到字符数组dest
    cout << "dest: " << dest << endl;

//（2）把测试标准库函数 strchr 和 strstr 的代码片段也合并在这个程序中；
    char *pch = str;  //定义字符指针并初始化为指向字符串头部
    cout << "pch: " << pch << endl;  //打印输出整个字符串
    cout << strlen(pch) << endl; //以字符指针为参数，传递整个字符串给函数
    pch = str + 11;   //字符指针指向字符数组中部的元素
    cout << "pch: " << pch << endl;  //打印输出子字符串
    cout << "pch: " << str + 11 << endl;  //直接利用字符运算的写法
    cout << strlen(pch) << endl; //以字符指针为参数，传递子字符串给函数
    cout << strlen(str + 11) << endl; //直接利用指针运算的写法
    strcpy(dest, pch);  //以字符指针为参数，传递子字符串给函数
    cout << "dest: " << dest << endl << endl;

    strcpy(str, "Almost#all#programmers#love#programming");
    cout << "str: " << str << endl;
    char ch = '#';
    pch = strchr(str, ch);  //返回首次出现字符ch的位置
    if (pch != NULL) {
        cout << "pch: " << pch << endl;
        cout << ch << " 首次出现位置: " << pch - str << endl;
    } else
        cout << ch << " 未出现在 " << str << endl;
    //下面用一个循环统计字符串中 # 出现的次数并将其都修改为' '
    pch = str;  //pch 指向str头部
    int cnt = 0;
    while (pch != NULL && *pch != '\0') { //注意这两个条件的次序不能颠倒
        if (pch = strchr(pch, ch)) {  //查找并把返回值当作逻辑值使用
            cout << "pch: " << pch << endl;
            cnt++;  //出现次数加1
            *pch = ' ';
            pch++;  //字符指针后移1位
        }
    }
    cout << ch << " 字符共出现次数: " << cnt << endl;
    cout << "修改后的字符串：" << str << endl << endl;

    char ss[] = "program";  //定义字符数组并初始化为字符串
    if (pch = strstr(str, ss)) {  //检查字符串ss是否出现在str中
        cout << "pch: " << pch << endl;
        cout << ss << " 首次出现位置: " << pch - str << endl;
    } else
        cout << ss << " 未出现在 " << str << endl;

    const char *ps = "program";  //定义常量字符指针，初始化指向一个字符串常量
    if (pch = strstr(str, ps)) {  //检查字符串ps是否出现在str中
        cout << "pch: " << pch << endl;
        cout << ps << " 首次出现位置: " << pch - str << endl;
    } else
        cout << ps << " 未出现在 " << str << endl;

//（3）自行编写一些语句，练习使用 strcat 和 strcmp。
    strcat(str, ". At least it is true for me.");
    cout << str << endl;

    cout << "compare read and real: " << strcmp("read", "real") << endl;
    cout << "compare really and real: " << strcmp("really", "real") << endl;


    return 0;
}
