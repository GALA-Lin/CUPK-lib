/*********************************************************************
程序名：某月有多少天（要考虑闰年）
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
3-8.输入一个年份和月份，打印输出该月份有多少天（考虑闰年），用switch语句编程。

解题分析：对例3-14 的示例程序进行相应修改
*********************************************************************/
#include <iostream>
using namespace std;

int main() {
    int year, month, days;

    cout << "请输入年份和月份：";
    cin >> year >> month;

    //是先考虑年份是否闰年，还是先用 switch 结构分析月份？要事先考虑好。
    //有些读者先考虑是否闰年，然后分别写两个 switch 结构，那样很繁琐。
    //合理的方法是直接写一个 switch 结构，仅对 2 月份专门考虑闰年。
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                days = 29;
            else
                days = 28;
            break;
        default:	//如果月份不在1～12，则输出一个特殊值表示有错误
            days = -1;
            break;
    }
    cout << year << " 年 " << month << " 月的天数：" << days << endl;

    return 0;
}
