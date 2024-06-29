/*********************************************************************
程序名: 指针数组拆分字符串
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期: 2021-06-03 08:58
说明:
7-11. 一个长度不超过100的字符串，其中只含英文字母和空格，空格用于分隔单词，单词数量
不超过20个。请用一个指针数组中的指针指向字符串中每个单词的开始位置，并把字符串
中单词结束后的空格改为'\0’，然后用指针数组将每个单词输出。
*********************************************************************/
#include <iostream>
using namespace std;

int main() {
    const int N = 100;
    char str1[N] = "The first step is as good as half over";	//字符串
    char *pch = str1;
    char *a[N];		//指针数组
    int n = 0, inword = 0;	//n为单词计数，inword表示是否在单词内部
    //连续读取时需要区分两种状态：单词内部，空格；
    //单词内部实际上不需要处理，重点是要注意“从空格转变到单词”
    while (*pch != '\0') {
        if (*pch != ' ' && !inword) {	//从空格转变到单词
            a[n++] = pch;
            inword = 1;
        } else if (*pch == ' ') {	//空格
            *pch = '\0';
            inword = 0;
        }
        ++pch;
    }

    for (int i = 0; i < n; ++i)
        cout << a[i] << endl;
    return 0;
}
















//
//#include <stdio.h>
//
//
//void split(char *str, char **a) {
//	char *p=str;
////处理第一个单词
//	if(*p && *p!=' ') {
//		*a++=str;
//		p++;
//	}
//	while(*p) {
////处理单词
//		if(*p!=' ' && *(p-1)=='\0') *a++ = p;
////处理空格
//		else if(*p==' ') *p='\0';
//		p++;
//	}
//}
//
//int main() {
//	char in[10000]= {0};
//	char *a[10000]= {NULL};
//	int i=0;
//	printf("Please input a string:\n");
////输入字符串
//	gets(in);
////处理抄
//	split(in, a);
////输出单词袭zhidao
//	printf("Words:\n");
//	for(; a[i]; i++) printf("%s\n", a[i]);
//}




