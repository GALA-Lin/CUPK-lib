/*********************************************************************
����������ʾ���ڵĽṹ��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����
8-2.����һ����ʾ�������ڣ����������գ��Ľṹ�����ͣ�ȡ��Date)��Ȼ�����øýṹ��
���Ͷ������º�����
��1�����ڸ�����������������������������α�ʾ��ݡ��·ݺ����������ڽṹ��ṹ��
����ԭ����Ϊbool mkDate(Date &dt, int year, int month, int day)����������������
��ݡ��·ݺ������Ĵ�СҪ����ݴ���0���·ݽ���1��12���������ڸ��µ������ڣ�����
Ҫע����·ݵ�����Ҫ����ƽ���������򣩣���dt���ع�������ڣ���������true������
��������false��
��2�����������ĳ�������Ǹ��꣨Ҫע��ƽ������꣩�ĵڼ���ĺ���������ԭ����Ϊ
int daynum(Date dt)��
��3�������������ڵ�������ĺ���������ԭ����Ϊint daysdiff(Date d1, Date d2)��
d1����d2ʱ����ֵΪ��ֵ���������ʱ����0��d1����d2ʱ������ֵ��
*��4��������һ�����ں�һ������Ϊ�����ĺ������������ĳ����������֮������ڡ�
����ԭ����ΪDate dateAft(Date dt, int num)��
*��5���������ĳ����֮ǰ����������ڵĺ���������ԭ����ΪDate dateBef(Date dt, int num)��
����Щ�������㣺���Լ��Ѿ������˶����죬�������һ�����ջ��ж����죬�ȵȡ�
*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

typedef struct Date {
    int year, month, day;
} Date;

int isleapyear(int year) {	//����������Ƿ�����
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool mkDate(Date &dt, int year, int month, int day) {
    if (year < 0  || month < 1 || month > 12 || day < 1) //�����յĲ�������ֵ
        return false;

    int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	//���·ݵ�����
    mdays[1] = (isleapyear(year) ? 29 : 28);	//����ƽ�������Ķ�������
    if (day > mdays[month - 1])	//�����Ĳ�������ֵ
        return false;

    //�����ų��˲�������ֵ��������Թ������ڽṹ��
    dt.year = year;
    dt.month = month;
    dt.day = day;
    return true;
}

int daynum(Date dt) {	//���������ĳ�������Ǹ���ĵڼ���
    int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//��������
    if (isleapyear(dt.year))
        mdays[1] = 29;	//����Ķ��·���29��

    int daynum = dt.day; 	//��ʼ��Ϊ���µ�����
    for (int i = 0; i < dt.month - 1; ++i)	//ǰ�����µ������ۼ�����
        daynum += mdays[i];

    return daynum;
}

int daysdiff(Date d1, Date d2) {//��������������������
    int diff = daynum(d1) - daynum(d2);		//ͬһ���е�������
    //��ݲ����ʱ����Ҫ�Ѵ�С��ݵ������֮��������ۼ���������С��ݣ���������ݣ�
    if (d1.year < d2.year)
        for (int year = d1.year; year < d2.year; year++ ) //�ۼ����Ϊ[d1.year, d2.year)
            diff += (isleapyear(year) ? -366 : -365); //�ۼ�����Ϊ����
    if (d1.year > d2.year)
        for (int year = d2.year; year < d1.year; year++ )//�ۼ����Ϊ[d2.year, d1.year)
            diff += (isleapyear(year) ? 366 : 365);  //�ۼ�����Ϊ����

    return diff;
}

Date dateAft(Date dt, int num) {
    int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//��������
    mdays[1] = (isleapyear(dt.year) ? 29 : 28);	//��������������������ƽ�꣩

    //dt ��ֵ������ֱ���������м��㣬��󷵻���ֵ
    dt.day += num;  //�Ѻ��������ۼӵ� dt.day
    while (dt.day > mdays[dt.month - 1]) {
        dt.day -= mdays[dt.month - 1];
        dt.month++;
        if (dt.month > 12) {	//�µ�һ��
            dt.month = 1;
            dt.year++;
            mdays[1] = (isleapyear(dt.year) ? 29 : 28);	//��������������������ƽ�꣩
        }
    }
    return dt;
}

Date dateBef(Date dt, int num) {
    int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//��������
    mdays[1] = (isleapyear(dt.year) ? 29 : 28);	//��������������������ƽ�꣩

    //dt ��ֵ������ֱ���������м��㣬��󷵻���ֵ
    //Ҫ�����Ե���֮ǰһЩ���������Ը�Ϊ�Ե������һ����ǰ����
    dt.day = (dt.day - mdays[dt.month - 1] ) - num; //�������һ��֮ǰ�����죨�Ը�����ʾ��
    while (dt.day < 0) {
        dt.day += mdays[dt.month - 1];
        dt.month--;
        if (dt.month < 1) {	//�ɵ�һ��
            dt.month = 12;
            dt.year--;
            mdays[1] = (isleapyear(dt.year) ? 29 : 28);	//��������������������ƽ�꣩
        }
    }
    dt.month++;	//����ѭ���е�month�����1������Ҫ��1
    return dt;

}

void prtDate(const char s1[], Date dt, const char s2[]) {	//�������s1��Date�� s2
    cout << s1 << dt.year << "��" << dt.month << "��" << dt.day << "��" << s2;
}

int main() {

    //��ʾ�����ݽ��в���
    Date d1 = {2020, 2, 29};
    Date d2 = {2021, 3, 2};

    prtDate ("d1: ", d1, "\n");	//����prtDate �����������
    prtDate ("d2: ", d1, "\n");	//����prtDate �����������

    cout << "d1 �ǵ���ĵڼ��죺" << daynum(d1) << endl;
    cout << "d2 �ǵ���ĵڼ��죺" << daynum(d2) << endl;
    cout << "d1 �� d2 ����������" << daysdiff(d1, d2) << endl;
    cout << "d2 �� d1 ����������" << daysdiff(d2, d1) << endl << endl;

    int year, month, day;
    Date birthday, today, nextbirthday;

    year = 1999, month = 8, day = 24;	//ʾ������
    //cout << "������������գ��� �� �գ���";
    //cin >> year >> month >> day;	//�û�����������
    if (mkDate(birthday, year, month, day) == false) {
        cout << "��������ֵ����" << endl;
        exit(1);
    }
    prtDate("���գ�", birthday, "\n");

    year = 2021, month = 10, day = 16;	//ʾ������
    //cout << "�������������ڣ��� �� �գ���";
    //cin >> year >> month >> day;	//�û�����������
    if (mkDate(today, year, month, day) == false) {
        cout << "��������ֵ����" << endl;
        exit(1);
    }
    prtDate("���죺", today, "\n");
    cout << "���������������" << daysdiff(today, birthday) << endl;

    //�����������Ϣ������һ�����յ���Ϣ
    nextbirthday = birthday;	//�������ڵ�������
    nextbirthday.year = today.year;		//������������
    if (birthday.month == 2 && birthday.day == 29 && !isleapyear(nextbirthday.year))
        nextbirthday.day = 28;	//����Ϊ����2��29�գ���ƽ��ȡ2��28Ϊ����

    if (daysdiff(nextbirthday, today) > 0) {
        prtDate("��һ�����գ�", nextbirthday, "\n");
        cout << "����껹û�й����ա�\n";
        cout << "��������: " << daysdiff(nextbirthday, today) << endl;
    }	else if (daysdiff(nextbirthday, today) == 0)
        cout << "����������գ�\n";
    else { //���������Ѿ���ȥ
        cout << "���������ѹ�����һ�������������ꡣ\n";
        nextbirthday.year++;
        if (birthday.month == 2 && birthday.day == 29 && !isleapyear(nextbirthday.year))
            nextbirthday.day = 28;	//����Ϊ����2��29�գ���ƽ��ȡ2��28Ϊ����
        prtDate("��һ�����գ�", nextbirthday, "\n");
    }
    cout << "������һ�����ջ���������" << daysdiff(nextbirthday, today) << endl;

    int num = 20;
    Date dt = dateAft(today, num);
    prtDate("\n�����ǣ�", today, "\n");
    cout << num;
    prtDate(" ��֮����", dt, "\n");

    dt = dateBef(today, num);
    prtDate("\n�����ǣ�", today, "\n");
    cout << num;
    prtDate(" ��֮ǰ��", dt, "\n");
    return 0;
}


