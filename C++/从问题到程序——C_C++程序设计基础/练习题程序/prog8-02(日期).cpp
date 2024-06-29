/*********************************************************************
程序名：表示日期的结构体
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：
8-2.定义一个表示公历日期（包含年月日）的结构体类型（取名Date)，然后利用该结构体
类型定义如下函数：
（1）对于给定的三个整数，构造出以它们依次表示年份、月份和日数的日期结构体结构。
函数原型设为bool mkDate(Date &dt, int year, int month, int day)。若三个整数符合
年份、月份和日数的大小要求（年份大于0，月份介于1至12，日数处于该月的天数内，而且
要注意二月份的天数要符合平年和闰年规则），则dt返回构造的日期，函数返回true，否则
函数返回false。
（2）计算给定的某个日期是该年（要注意平年和闰年）的第几天的函数。函数原型设为
int daynum(Date dt)。
（3）计算两个日期的天数差的函数。函数原型设为int daysdiff(Date d1, Date d2)，
d1早于d2时返回值为负值，两者相等时返回0，d1迟于d2时返回正值。
*（4）定义以一个日期和一个天数为参数的函数，它能算出某日期若干天之后的日期。
函数原型设为Date dateAft(Date dt, int num)。
*（5）定义计算某日期之前若干天的日期的函数。函数原型设为Date dateBef(Date dt, int num)。
用这些函数计算：你自己已经生活了多少天，离你的下一个生日还有多少天，等等。
*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

typedef struct Date {
    int year, month, day;
} Date;

int isleapyear(int year) {	//给定的年份是否闰年
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool mkDate(Date &dt, int year, int month, int day) {
    if (year < 0  || month < 1 || month > 12 || day < 1) //年月日的不合理数值
        return false;

    int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	//各月份的天数
    mdays[1] = (isleapyear(year) ? 29 : 28);	//处理平年的闰年的二月天数
    if (day > mdays[month - 1])	//日数的不合理数值
        return false;

    //以上排除了不合理数值，下面可以构造日期结构体
    dt.year = year;
    dt.month = month;
    dt.day = day;
    return true;
}

int daynum(Date dt) {	//计算给定的某个日期是该年的第几天
    int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//各月天数
    if (isleapyear(dt.year))
        mdays[1] = 29;	//闰年的二月份有29天

    int daynum = dt.day; 	//初始化为本月的天数
    for (int i = 0; i < dt.month - 1; ++i)	//前几个月的日子累加起来
        daynum += mdays[i];

    return daynum;
}

int daysdiff(Date d1, Date d2) {//计算两个日期相差的天数
    int diff = daynum(d1) - daynum(d2);		//同一年中的天数差
    //年份不相等时，需要把从小年份到大年份之间的天数累加起来（含小年份，不含大年份）
    if (d1.year < d2.year)
        for (int year = d1.year; year < d2.year; year++ ) //累加年份为[d1.year, d2.year)
            diff += (isleapyear(year) ? -366 : -365); //累加天数为负数
    if (d1.year > d2.year)
        for (int year = d2.year; year < d1.year; year++ )//累加年份为[d2.year, d1.year)
            diff += (isleapyear(year) ? 366 : 365);  //累加天数为正数

    return diff;
}

Date dateAft(Date dt, int num) {
    int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//各月天数
    mdays[1] = (isleapyear(dt.year) ? 29 : 28);	//二月天数（考虑闰年与平年）

    //dt 是值参数，直接拿它进行计算，最后返回其值
    dt.day += num;  //把后续天数累加到 dt.day
    while (dt.day > mdays[dt.month - 1]) {
        dt.day -= mdays[dt.month - 1];
        dt.month++;
        if (dt.month > 12) {	//新的一年
            dt.month = 1;
            dt.year++;
            mdays[1] = (isleapyear(dt.year) ? 29 : 28);	//二月天数（考虑闰年与平年）
        }
    }
    return dt;
}

Date dateBef(Date dt, int num) {
    int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//各月天数
    mdays[1] = (isleapyear(dt.year) ? 29 : 28);	//二月天数（考虑闰年与平年）

    //dt 是值参数，直接拿它进行计算，最后返回其值
    //要计算以当天之前一些天数，可以改为以当月最后一天往前计数
    dt.day = (dt.day - mdays[dt.month - 1] ) - num; //当月最后一天之前多少天（以负数表示）
    while (dt.day < 0) {
        dt.day += mdays[dt.month - 1];
        dt.month--;
        if (dt.month < 1) {	//旧的一年
            dt.month = 12;
            dt.year--;
            mdays[1] = (isleapyear(dt.year) ? 29 : 28);	//二月天数（考虑闰年与平年）
        }
    }
    dt.month++;	//上面循环中的month多减了1，所以要加1
    return dt;

}

void prtDate(const char s1[], Date dt, const char s2[]) {	//依次输出s1、Date和 s2
    cout << s1 << dt.year << "年" << dt.month << "月" << dt.day << "日" << s2;
}

int main() {

    //用示例数据进行测试
    Date d1 = {2020, 2, 29};
    Date d2 = {2021, 3, 2};

    prtDate ("d1: ", d1, "\n");	//调用prtDate 函数输出日期
    prtDate ("d2: ", d1, "\n");	//调用prtDate 函数输出日期

    cout << "d1 是当年的第几天：" << daynum(d1) << endl;
    cout << "d2 是当年的第几天：" << daynum(d2) << endl;
    cout << "d1 与 d2 相差的天数：" << daysdiff(d1, d2) << endl;
    cout << "d2 与 d1 相差的天数：" << daysdiff(d2, d1) << endl << endl;

    int year, month, day;
    Date birthday, today, nextbirthday;

    year = 1999, month = 8, day = 24;	//示例数据
    //cout << "请输入你的生日（年 月 日）：";
    //cin >> year >> month >> day;	//用户输入年月日
    if (mkDate(birthday, year, month, day) == false) {
        cout << "年月日数值错误！" << endl;
        exit(1);
    }
    prtDate("生日：", birthday, "\n");

    year = 2021, month = 10, day = 16;	//示例数据
    //cout << "请输入今天的日期（年 月 日）：";
    //cin >> year >> month >> day;	//用户输入年月日
    if (mkDate(today, year, month, day) == false) {
        cout << "年月日数值错误！" << endl;
        exit(1);
    }
    prtDate("今天：", today, "\n");
    cout << "你已生活的天数：" << daysdiff(today, birthday) << endl;

    //根据上面的信息构造下一个生日的信息
    nextbirthday = birthday;	//出生日期的年月日
    nextbirthday.year = today.year;		//今年的生日年份
    if (birthday.month == 2 && birthday.day == 29 && !isleapyear(nextbirthday.year))
        nextbirthday.day = 28;	//生日为闰年2月29日，则平年取2月28为生日

    if (daysdiff(nextbirthday, today) > 0) {
        prtDate("下一个生日：", nextbirthday, "\n");
        cout << "你今年还没有过生日。\n";
        cout << "还有天数: " << daysdiff(nextbirthday, today) << endl;
    }	else if (daysdiff(nextbirthday, today) == 0)
        cout << "今天你的生日！\n";
    else { //当年生日已经过去
        cout << "今年生日已过。下一个生日是在明年。\n";
        nextbirthday.year++;
        if (birthday.month == 2 && birthday.day == 29 && !isleapyear(nextbirthday.year))
            nextbirthday.day = 28;	//生日为闰年2月29日，则平年取2月28为生日
        prtDate("下一个生日：", nextbirthday, "\n");
    }
    cout << "距离下一个生日还有天数：" << daysdiff(nextbirthday, today) << endl;

    int num = 20;
    Date dt = dateAft(today, num);
    prtDate("\n今天是：", today, "\n");
    cout << num;
    prtDate(" 天之后是", dt, "\n");

    dt = dateBef(today, num);
    prtDate("\n今天是：", today, "\n");
    cout << num;
    prtDate(" 天之前是", dt, "\n");
    return 0;
}


