/*********************************************************************
程序名：字符串比较
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：
7-7. 写一个谓词函数 bool issame(char *s, char *t, bool strict)，对两个都由 ASCII
字符（取值为0~127）构成的字符串进行判断：
（1）当参数 strict 为 true 时，检查这两个字符串是否为换位字符串（组成字符串的字符
及各个字符出现的次数都相同，但字符在字符串里出现的位置可能不同，例如 dare 和 read、
dear）；
（2）当参数 strict 为 false 时，检查这两个字符串是否由同样一批字符组成（各字符的
出现次数可能不同，例如 “abcabcabc” 与 “cba” ）。
（提示：设立两个 int 类型的辅助数组，分别记录这两个字符串中各个 ASCII 字符的出现
次数，然后对这两个数组的元素值进行比较：当 strict 为 true 时，比较它们的值是否相等；
而当 strict 为 false 时，只比较它们是否同时不为零）

（当参数 strict 为 true 时，还有另一种解法：对两个字符串分别进行排序，然后逐字符
比较。这留给有兴趣的读者去做）。
*********************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

bool issame(char *s, char *t, bool strict) {	//检查两个字符串是否相同
	//定义两个数组并初始化为 0，以分别记录两个字符串中各个字符的出现情况
	int a[128] = {0}, b[128] = {0};

	//分别记录两个字符串中各个字符的出现情况
	for (char *p = s; *p != '\0'; p++)	//处理字符串 s
		a[*p]++;	//把 p 所指的字符当作整数，作为下标。相应字符出现则增 1
	for (char *p = t; *p != '\0'; p++)	//处理字符串 t
		b[*p]++;	//把 p 所指的字符当作整数，作为下标，相应字符出现则增 1

	for (int i = 0; i < 128; i++ ) {	//比较数组 a 和 b
		if (strict) {	//此处必须加花括号构成复合语句，才能使 else 与这个 if 配对。
			if (a[i] != b[i] ) //!!! 在严格情况下，比较字符的出现次数
				return 0;	//只要找到一个字符的“出现次数”不同，则可判断为否
		} else if ((a[i] > 0)	!= (b[i] > 0) )	//宽松情况下，只比较字符“是否出现”
			return 0;	//只要找到一个字符的“是否出现”不同，则可判断为否
	}
	return 1;	//上面的循环完全结束，则所有字符的出现情况都相同

}

int main() {
	cout << "检查两个字符串是否相同" << endl;

	char str1[100], str2[100];

	//提供多组示例字符串进行测试


//	strcpy(str1, "read");
//	strcpy(str2, "dear");

//	strcpy(str1, "read");
//	strcpy(str2, "dead");

	strcpy(str1, "cba123");
	strcpy(str2, "abc1abc2abc3");

//	strcpy(str1, "abc123, abcd456. abcdefg789!");
//	strcpy(str2, "efg123. bcda789, dcbaaba456!");

//	strcpy(str1, "cba123aaabbbcccdef");
//	strcpy(str2, "abc1abc2abc3aabbccaabbccddff");

	cout << str1 << "\t" << str2 << endl;
	cout << (issame(str1, str2, true) ? "是换位字符串" : "不是换位字符串") << endl;
	cout << (issame(str1, str2, false) ? "相同字符构成" : "不同字符构成" ) << endl;

	return 0;
}


