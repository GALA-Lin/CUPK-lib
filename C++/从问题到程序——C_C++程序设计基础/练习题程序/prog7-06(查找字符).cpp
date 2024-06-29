/*********************************************************************
程序名: 在字符串中查找字符
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期: 2021-06-02 11:19
说明:
prog7-6. 使用两种不同实现方式编写函数用于在查找字符串 s 中首次出现字符 ch 的位置：
（1）函数原型为 int strchar1(char s[], int ch); ，成功时返回字符 ch 在字符串 s 中
首次出现的位置序号（即下标值加 1），找不到时返回值 0；
（2）函数原型为 char *strchar2(char *s int ch);，查找成功时返回指向该位置的指针，
如果 s 中不存在 ch 则返回 NULL。
*********************************************************************/

#include <iostream>
using namespace std;

int strchar1(char s[], int ch) {
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == ch)
            break;
//另一种紧凑的写法：
//	for (i = 0; s[i] != '\0' && s[i] != ch; i++)	//循环条件中比较空字符和字符ch
//		;	//空循环体
    return (s[i] == '\0' ? 0 : i + 1);
}

char *strchar2(char *s, int ch) {
    char *p;
    for (p = s; *p != '\0'; p++)
        if (*p == ch)
            break;
    return (*p == '\0' ? NULL : p);
}

int main() {
    char str[100] = "hello, world!";
    char ch = 'o';
    int k = strchar1(str, ch);
    cout << "k= " << k << "  " << str[k - 1] << endl;

    char *p1 = strchar2(str, ch);
    cout << "p1= " << p1 << endl;
    cout << "*p1= " << *p1 << endl;
    return 0;
}
