/*********************************************************************
��������������д����дΪָ��д��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2022-05-26
˵����
7-4. ��д���º���������д���������в��ԣ�����1����һ��double�����������
��Ԫ��ֵ��ӡ���������ԭ��ΪprtSeq(double *begin, double *end)��
��2����һ��double��������������е�ֵ�任Ϊԭֵ��ƽ����������ԭ��Ϊ
sqrtSeq(double *begin, double *end)��
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

void prtSeq(double *begin, double *end) {
    for ( ; begin < end; begin++)
        cout << *begin << "\t";
    cout << endl;
    return;
}

void sqrtSeq(double *begin, double *end) {
    for ( ; begin < end; begin++)
        *begin = sqrt(*begin);
    return;
}


int main() {
    //�������鲢��ʾ�����ݳ�ʼ��
    double array[] = {3.2, 2.1, 5.3, 1.8, 7.9, 8.2, 10.3, 6.1, 5.4 };
    int len = sizeof(array) / sizeof(array[0]);  //������鳤��

    prtSeq(array, array + len);  //��ӡ���һ��

    sqrtSeq(array, array + len); //Ԫ��ֵ�任Ϊԭֵ��ƽ����

    prtSeq(array, array + len);  //�ٴ�ӡ���һ��


    return 0;
}




