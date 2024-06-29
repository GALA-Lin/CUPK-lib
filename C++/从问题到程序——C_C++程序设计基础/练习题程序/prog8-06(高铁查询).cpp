/*********************************************************************
程序名：火车票价查询系统 
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：
8-6.先在网上检索国内一些城市（例如北京、上海、广州、深圳和武汉等）之间
的直达高铁的车站信息和车票信息（包括商务座、一等座和二等座），并以合适
的编排格式保存在一个文本文件中。然后编写一个小型信息查询系统：系统启动
时就从前面已准备好的文本文件中读取直达高铁的车站信息和票价信息，让用户
输入任意两个城市的名字，它就能给出这两个城市之间的直达高铁的车站信息和
票价信息。

编程解析：
从网上搜集几个大城市的直达数据：北京、上海、广州、深圳、武汉
搜集数据并整理很费时间。铁路车次有多个等级，座次也有多个级别。在此只取
直达高铁。数据之间用TAB键分隔，下面看似不够整齐，但读取数据时很整齐。
（若无该等级座位票价，则写作 -1.0） 

#车站1	车站2	VIP 	level1	level2
北京南	上海虹桥	1748.0	933.0	553.0
北京西	广州南	2724.0	1380.0	862.0	
北京西	深圳北	2923.5	1479.5	936.5
北京西	武汉 	1642.5	832.5	520.5
上海虹桥	广州南	2492.5	1302.5	793.0
上海虹桥	深圳北	2692.0	1402.0	867.5
上海虹桥	武汉	1031.0	548.0	336.0
广州南	深圳北	199.5 	99.5	74.5 
广州南	武汉	1458.5	738.5	463.5
深圳北	武汉 	1658.0	838.0	538.0
*********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

typedef struct ticket{
	char st1[9], st2[9];	//两个车站名，分别可容纳4个汉字 
	float vip, lv1, lv2;	//票价：商务座，一等座，二等座 
	//车票不会太贵，不需用double 类型，用float足够，可节约内存空间 
} ticket;

void PrintTicket(ticket *tk) {
	cout << tk->st1 << "\t" << tk->st2 << "    \t"
		<< tk->vip << "\t" << tk->lv1 << "\t" << tk->lv2 << endl;
}

ticket * ReadInfo(int &n) {	//参数 &n 返回数据条数，函数返回值为指针 
	const int SIZE = 100;
	char str[SIZE];
	
	char fname[100] = "prog8-06.txt";	//tickets.txt
	//用户应当把从网上查询得到的数据存储为一个纯文本文件，并保存于与此程序同一文件夹下。
	ifstream in(fname);	//!!定义输入文件流
	
	if (!in) {	//如果文件不存在，则输入文件流会创建失败
		//cout << "程序出错：文件并不存在。请事先编辑并保存文件。" << endl;
		//return NULL; 	//向调用处返回 NULL 值，表示未读取到数据。

		//本程序为了方便读者学习，如果文件不存在，则自动创建文件，以供后续读取。
		ofstream out(fname);	//定义输出文件流并绑定到文件
		//向输出文件流输出示例文字
		out << "#车站1\t车站2\tVIP\tlevel1\tlevel2\n"
			<< "北京南	上海虹桥	1748.0	933.0	553.0\n"
			<< "北京西	广州南	2724.0	1380.0	862.0\n"
			<< "北京西	深圳北	2923.5	1479.5	936.5\n"
			<< "北京西	武汉 	1642.5	832.5	520.5\n"
			<< "上海虹桥	广州南	2492.5	1302.5	793.0\n"
			<< "上海虹桥	深圳北	2692.0	1402.0	867.5\n"
			<< "上海虹桥	武汉	1031.0	548.0	336.0\n"
			<< "广州南	深圳北	199.5 	99.5	74.5\n"
			<< "广州南	武汉	1458.5	738.5	463.5\n"
			<< "深圳北	武汉 	1658.0	838.0	538.0\n";
		out.close();	//关闭输出文件流
		cout << "已创建数据文件供读取。" << endl;
		ifstream in(fname);	//再次定义输入文件流，这次应该肯定成功
	}
	//如果文件流创建成功，则继续执行。
	
	cout << "读取数据文件：" << fname <<endl;
	in.getline(str, 100);	//读入文件首行注释 
	while (in.getline(str, SIZE)) {	//逐行读入进行计数 
		if (strlen(str) !=0)
			n++;
		//cout << n <<": " << str <<endl;
	}
	in.close();	//关闭文件 
	cout << "数据总行数：" << n << endl; 
	
	in.open(fname);	//打开文件以供读取 
	in.getline(str, SIZE);	//读入文件首行注释 
	ticket *tk = new ticket[n];	//定义指针变量并申请分配空间 
	//ticket tk[n];	//定义以变量为长度的数组（C99或C++） 
	for (int i = 0; i < n; i++) {	//读取车票信息 
		in >> tk[i].st1 >> tk[i].st2 >> tk[i].vip >> tk[i].lv1 >> tk[i].lv2;  //数组写法
		//in >> (tk+i)->st1 >> (tk+i)->st2 >> (tk+i)->vip >> (tk+i)->lv1 >> (tk+i)->lv2;//指针写法 
//		cout << i << ": ";
//		PrintTicket(&tk[i]);
	}
	in.close();	//关闭文件 
	
	return tk;	
}

int QueryInfo(int len, ticket *tk) {
	char city1[9], city2[9];
	bool found = false;
	
	cout << "请输入两个城市名：" ;
	cin >> city1 >> city2;

	for (int i = 0; i < len; i++) {
		if ((strstr(tk[i].st1, city1) && strstr(tk[i].st2, city2)) 
			|| (strstr(tk[i].st1, city2) && strstr(tk[i].st2, city1)) )
		{
			PrintTicket(&tk[i]);
			found = true;
		}
	}
	if (found == false)	//没有找到任何所需信息 、
		cout << "很遗憾，没有找到这两个城市之间的高铁信息。\n"; 
}

int ShowData(int len, ticket *tk) {
	for (int i = 0; i < len; i++) {	//输出车票信息 
		cout << i << ": ";
		PrintTicket(&tk[i]);
	}
}

int main() {
    char c1, c2;	//city
    int n = 0;	//数据条数 
    int choose = 1;

	ticket * tk = ReadInfo(n);	////读入数据文件
	if (tk == NULL)  {	//预防错误处理
		cout << "数据读取错误，程序异常终止。\n" ;
		exit(1);
	}
    while(choose != 0) {
        cin.sync();
        cout << "== 城市之间火车票价查询系统 ==" << endl;
        cout << "1.查询城市直达高铁信息票价    " << endl;
        cout << "2.列出系统内部所有信息        " << endl;
        cout << "0.退出                        " << endl;
        cout << "========================" << endl;
        do {
            cout<< "请选择程序功能(1, 2, 0): ";
            cin >> choose;
        } while(choose < 0 || choose > 2);
        cin.sync();

        switch(choose) {
            case 1: { QueryInfo(n, tk); break; } 
            case 2: { ShowData(n, tk);  break; } 
            default: break;
        }
        cin.sync();
        cout << "\n按回车键继续";
		cin.get();	//等待用户按回车键 
    }

    return 0;
}

