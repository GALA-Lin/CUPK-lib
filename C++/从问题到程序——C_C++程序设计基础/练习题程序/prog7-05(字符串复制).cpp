/*********************************************************************
��������������д����дΪָ��д��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2022-05-26
˵����
7-5.�ѵ�6���������鷽ʽ����ĺ�����6-16���ַ������ƣ���дΪ��ָ������ķ�ʽ���塣
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

void stringcopy1(char *s, const char *t) {  //�ַ������ƣ��汾1
	int i = 0;
	while (*(t + i) != '\0') {
		*(s + i) = *(t + i);
		++i;
	}
	*(s + i) = '\0';
}

void stringcopy2(char *s, const char *t) {  //�ַ������ƣ��汾2
	int i = 0;
	while ((*(s + i) = *(t + i)) != '\0')
		++i;
}

void stringcopy3(char *s, const char *t) {  //�ַ������ƣ��汾3
	int i = 0;
	while (*(s + i) = *(t + i)) // ���ø�ֵ���ʽ��ֵ��Ϊ�߼�ֵ
		++i;
}


int main() {
	//�������鲢��ʾ�����ݳ�ʼ��
	char s[100] = "Hello, world!";
	char s1[100], s2[100], s3[100];
	cout << "s: " << s << endl;

	stringcopy1(s1, s);
	cout << "s1: " << s1 << endl;

	stringcopy2(s2, s1);
	cout << "s2: " << s2 << endl;

	stringcopy3(s3, s2);
	cout << "s3: " << s3 << endl;

	return 0;
}




