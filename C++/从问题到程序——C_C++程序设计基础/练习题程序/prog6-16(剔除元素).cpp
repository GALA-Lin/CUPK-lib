/*********************************************************************
程序名：字符串 s1 中删除串 s2 里包含的所有字符
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：6-16.写函数squeeze(char s1[], char s2[])，它从字符串 s1 中删除串 s2 里
包含的所有字符（而且保证剩下的字符仍然按照原来顺序连续排列，形成字符串）。
例如，取s1为"hello world!"，s2为"ol"，调用此函数之后，s1变为"he wrd!"。
*********************************************************************/
#include <iostream>
using namespace std;

void squeeze(char s1[], char s2[]) { //从字符串s1 中删除所有在s2里出现的字符
    int i, j, k;
    for (i = 0; s2[i] != '\0'; ++i) //对S2中每个字符，在S1中搜索一遍
        for (j = 0; s1[j] != '\0'; ++j)
            if (s1[j] == s2[i]) {	//如果找到相等的字符
                //S1中当前位置的后面字符都向前移动一位，即删除当前相等元素。
                for (k = j; s1[k] != '\0'; ++k)
                    s1[k] = s1[k + 1];
                --j;//移动之后，当前 j 要左移一位（以便下一次循环再次判断此位置）
            }
}

int main() {
    char s1[] = "hello world!";
    char s2[] = "ol";	//或用 "look"，其中的 l 和 o 在s1出现，而 k 在s1中不出现

    cout << "before squeeze:\ns1=" << s1 << "\ns2=" << s2 << endl;
    squeeze(s1, s2);

    cout << "after squeeze, s1=" << s1;

    return 0;
}
