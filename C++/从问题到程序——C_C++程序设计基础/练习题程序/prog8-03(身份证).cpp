/*********************************************************************
程序名：表示身份证的结构体
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：
8-3. 定义表示身份证（包含身份证号、姓名、性别、出生年月日和住址等信息）的
结构体（取名IDcard，注意身份证号需要用字符数组表示），并定义几个对两个身份证
进行比较的函数（相同时返回true，不相同时返回false）：
（1）身份证号是否相同（函数取名eqID）；（2）姓名是否相同（eqName），
（3）出生年月日是否相同（eqBirth）；（4）身份证所有信息是否相同（eqIDcard）。
考虑应该使用结构体参数，还是使用结构体指针参数。最后写一个主函数，测试这些函数。
*********************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

typedef struct IDcard {
    char id[19];	//身份证编号为18位，而且可能有字符，只能用字符数组存储。（不要用long long!）
    char name[20];
    char sex;
    int year, month, day;
    char address[100];
} IDcard;

//身份证信息比较多，使用结构体指针参数为好

bool eqID(IDcard *a, IDcard *b) {
    int i, len = 18;
    for (int i = 0; i < len; i++)	//逐字符比较
        if (a->id[i] != b->id[i])	//只要有一个字符不相等即可判断不相等
            return false;
    return true;	//所有字符都相等
}

bool eqName(IDcard *a, IDcard *b) {
    //对两个姓名逐字符比较
    int i;
    for (i = 0; a->name[i] != '\0' && a->name[i] != '\0'; i++)
        if (a->name[i] != b->name[i])	//中间有字符不相等，直接判定为不相同
            return false;
    if (a->name[i] != '\0' || b->name[i] != '\0' )	//有一个姓名没有到末尾，不相同。
        return false;
    else
        return true;

    //也可以使用标准库函数 strcmp。（请注意两个字符串相同时，strcmp 的返回值为 0）
    //return (strcmp(a->name, b->name) == 0);
}

bool eqBirth(IDcard *a, IDcard *b) {
    return (a->year == a->year && a->month == b->month && a->day == b->day);
}


bool eqIDcard(IDcard *a, IDcard *b) {
    return (eqID(a, b) && eqName(a, b) && a->sex == b->sex
            && eqBirth(a, b) && strcmp(a->address, b->address) == 0);
}

void printID(IDcard *a) {
    cout << "编号：" << a->id << endl;
    cout << "姓名：" << a->name << "\t"
         << "性别：" << (a->sex == 'M' ? "男" : "女") << endl;
    cout << "出生日期：" << a->year << " 年 " << a->month << " 月 "
         << a->day << " 日 " << endl;
    cout << "地址：" << a->address << endl;
}

int main() {
    //用示例数据进行测试
    IDcard id1 = {"430224198905120057", "张三", 'M', 1989, 5, 12,
                  "湖北省武汉市洪山区珞瑜路152号"
                 };

    IDcard id2 = {"432522200110030269", "李四", 'F', 2001, 10, 3,
                  "湖南省长沙市长沙市天心区杉木冲西路9号"
                 };//与 id1 不同

    IDcard id3 = {"430224198905120057", "张三", 'M', 1989, 5, 12,
                  "湖北省武汉市洪山区珞瑜路152号"
                 }; //与 id1 相同

    cout << "\nid1 信息：\n";
    printID(&id1);

    cout << "\nid2 信息：\n";
    printID(&id2);

    cout << "\nid3 信息：\n";
    printID(&id3);

    cout << "\n身份证比较\n";
    cout << "id1 与 id2 比较（编号、姓名、出生日期、整个身份证）：\n"
         << eqID(&id1, &id2) << "\t" << eqName(&id1, &id2) << "\t"
         << eqBirth(&id1, &id2) << "\t" << eqIDcard(&id1, &id2) << endl;

    cout << "id1 与 id3 比较：\n"
         << eqID(&id1, &id3) << "\t" << eqName(&id1, &id3) << "\t"
         << eqBirth(&id1, &id3) << "\t" << eqIDcard(&id1, &id3) << endl;

    return 0;
}


