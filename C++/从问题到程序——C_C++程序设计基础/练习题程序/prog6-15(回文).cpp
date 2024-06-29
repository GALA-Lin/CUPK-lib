/*********************************************************************
程序名：判断字符串是否为回文
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：6-15.回文(palindrome)是从前向后和从后向前读起来都一样的词语或句子。
例如英文中的“madamimadam”，其原文是：“Madam, I'm Adam”。
（1）写一个函数，判断“madamimadam”这样不含标点符号的纯英文小写字母字符串
是否回文；（2）写一个函数判断“Madam, I'm Adam.”这样含有英文标点符号的
纯英文大小写混和字符串是否回文。
*********************************************************************/

#include <iostream>
#include <cstring> 	//需要使用标准库中与字符串相关的函数
using namespace std;

int palindrome(char str[]) {
//函数功能：判断 全 英 文 的字符数组 str[] 是否回文
//说明：形参为一个字符数组（不需要长度参数）
    int len = strlen(str);	//使用标准库函数 strlen 获得字符数组长度
    //逐个比较字符数组的头部元素和相应的尾部元素
    for (int i = 0; i < len / 2; i++)
        if (str[i] != str[len - 1 - i])
            return 0; //只要发现一对字符不相等，则可判断不是回文
    return 1; //循环结束，所有相应元素都相等，从而判断是回文
}


int palindrome2(char str[]) {
//函数功能：含有英文标点符号的纯英文大小写混和字符串str[] 是否回文
//说明：形参为一个字符数组（不需要长度参数）
    int len = strlen(str);	//使用标准库函数 strlen 获得字符数组长度
    //逐个比较字符数组的头部元素和相应的尾部元素
    for (int i = 0, j = len - 1; i < j; i++, j--) {	//i 和 j 分别指向字符串头尾的元素
        while (!isalpha(str[i]) && i < j)	//左边跳过非英文字符
            i++;
        while (!isalpha(str[j]) && i < j)	//右边跳过非英文字符
            j--;
        cout << i << " " << str[i] << "\t" << j << " " << str[j] << endl;
        if (tolower(str[i]) != tolower(str[j]))
            return 0; //只要发现一对字符不相等，则可判断不是回文
    }
    return 1; //循环结束，所有相应元素都相等，从而判断是回文
}

int main() {

    char s[100];	//定义字符数组 s

    strcpy(s, "madamimadam");	//用 strcpy 把常量字符串复制到字符数组
    if (palindrome(s)) //调用第1个函数对 s 进行判断
        cout << s << " 是回文" << endl;
    else
        cout << s << " 不是回文" << endl;

    strcpy(s, "Madam, I'm Adam.");
    //调用第2个函数对 s 进行判断并输出（使用条件表达式，语句更简洁紧凑）
    cout << s << (palindrome2(s) ? " 是回文" : " 不是回文") << endl;

    return 0;
}

/*
据说，法国皇帝拿破仑在对俄战争失败后被放逐地中海上的厄尔巴岛，他讲了这句用回文表达
的名言: Able was I ere I saw Elba.
(我见到厄尔巴之前，曾经不可一世。ere是古英语，意即 before。)

美国前总统尼克松的支持者用一句回文称赞他: No X in Nixon.(尼克松心里没有谜。)

再看这句: Aman, a plan, a canal- Panama ! (一个人，一个计划，一条运河——巴拿马!)
Aman指美国前总统西奥多·罗斯福，他在任内美国取得巴拿马运河开凿权。

还有一句回文佳句是在美国《时代》杂志的一封读者来信中发现的：
Live on, Time,emit no evil. (《时代》杂志，愿你永生，可别恶语伤人。>
再举几例以字母为单位的回文句。
Rise to vote, sir.(先生，站起来投票吧!)
Was it a rat I saw?(我看到的是一只老鼠吗?这句用cat或 bat亦可)
Live on no evil.(生活的不错。)
*/

/*
额外的讨论：判断 中 英 文 混 和 字符串是否回文
int palindrome3(char str[]) {
//函数功能：判断 中 英 文 混 和 的字符串数组 str[] 是否回文
//说明：形参为一个字符数组（不需要长度参数）
    int len = strlen(str);	//使用标准库函数 strlen 获得字符数组长度
    //逐个比较字符数组的头部元素和相应的尾部元素
    for (int i = 0; i < len / 2; i++) {
        if (str[i] >= 0 && str[i] <= 127) { //英文字符只占一个字节，大小介于 0-127
            if (str[i] != str[len - 1 - i])
                return 0; //只要发现一对英文字符不相等，则可判断不是回文
        } else {//每个中文字符占两个字节，其中的每个字节的大小都不在 0-127 之间
            if (str[i] != str[len - 1 - i - 1] && str[i + 1] != str[len - 1 - i] )
                return 0;
            i++; // 对于 for 的头部指定的 i，此处比较了两个字符，所以让 i 额外增1
        }
    }
    return 1; //循环结束，所有相应元素都相等，从而判断是回文
}

//测试：
    strcpy(s,  "上海自来水来自海上"); //纯中文字符串
    strcpy(s, "上a海b自c来d水d来c自b海a上"); //中英文混和字符串
    if (palindrome3(s)) //调用函数对 s 进行判断
        cout << s << " 是回文" << endl;
    else
        cout << s << " 不是回文" << endl;


//附加注释  在windows 10 的控制台窗口输出中文字符串时，容易出现乱码。原因未知。
//可以在该控制台窗口标题行点击鼠标右键，点击弹出菜单中的“默认值”，
//然后在弹出窗口的“选项”选项卡下勾选“使用旧版控制台”，以后就可以正常显示中文。
*/
