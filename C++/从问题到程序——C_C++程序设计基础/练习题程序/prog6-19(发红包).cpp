/*********************************************************************
程序名：拼手气发红包，避免红包金额为 0
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：6-19.在例6-18（拼手气发红包）的讨论中留下了一个任务：在 allocate
函数中还应该进行额外调整以避免红包的金额为0值。请设想一种方法并编程解决
这个问题（请测试：发放 0.1 元给 10 人，每人都能得到 0.01 元）。

解题说明：下面程序的主体就是例6-18中的内容，在 allocata 函数的末尾写有
“额外调整避免 0 值”的程序片段就是本题所需的功能。
*********************************************************************/
#include <iostream>
#include <cstdlib>        //使用随机数函数所需的库文件
#include <ctime>        //使用 time() 函数所需的库文件
using namespace std;

int setpara(int &t, int &n, int MAX); //设置红包总金额t和人数 n（<=MAX）
int allocate(int t, int n, int money[]);//总金额t分配到长为n的数组money中
void printout(int t, int n, int money[]);//输出money数组中的红包金额

int main() {
    const int MAX = 100;    //最大人数
    int t, n, money[MAX];

    cout << "== 拼手气发红包 ==" << endl;
    if (!setpara(t, n, MAX)) {    //设置参数，若失败则退出
        cout << "参数设置失败，程序结束。" ;
        exit(1);
    }

    allocate (t, n, money);    //分配红包金额
    printout (t, n, money);    //打印输出
    return 0;
}

int setpara(int &t, int &n, int MAX){ //设置红包总金额t和人数 n（<=MAX）
    double total; //红包总金额（元）
    int errs = 0, ERRNUM = 3;
    do {
        cout << "请输入红包总金额(元)：";
        cin >> total;
        cout << "请输入红包个数：" ;
        cin >> n;
        if (n > MAX) {
            cout << "错误：总人数超过了 "<< MAX << endl;
            errs++;
        }

        t = total * 100;    //货币单位由元转换为分
        if (t < n) { //如果红包总金额分数小于人数
            cout << "错误：红包总金额分数小于人数！请重新输入。" << endl;
            errs++;
        }
    } while ((n > MAX || t < n) && errs <= ERRNUM);
    return (errs <= ERRNUM ? 1 : 0);
}

int allocate(int t, int n, int money[]){//总金额t分配到长为n的数组money中
    int i, total = 0;
    int min = 0.5 * t / n, max = 1.5 * t / n;

    srand(time(0));
    for (i = 0; i < n; i++) {    //产生 n 个随机数
        money[i] = rand() % (max - min +1) + min;
        total += money[i];
    }

    //对红包金额进行归一化。
    //为了防止数值误差，只对前n-1个进行归一化，最后一个以减法赋值
    int sum = 0;
    for (i = 0; i < n-1; i++) {    //前 n-1 个进行归一化
        money[i] = double(money[i]) / total * t;
        sum += money[i];
    }
    money[n-1] = t - sum;

    //额外调整避免 0 值
	//策略：每找到一个 0 值，则从数组中找出最大值，与 0 值平分。
    for (i = 0; i < n; i++) {    //查找 0 值并处理
    	if (money[i] == 0) {	//找到一个 0 值
    		int k = 0;	//用 k 标记最大值的下标
    		for (int j = 0; j < n; j++)	//找出最大值
    			if (money[j] > money[k])
    				k = j;
	   		//两者近似地平分
			money[i] = money[k] /2;
    		money[k] = money[k] - money[i];
    	}
    }

    return 0;
}

void printout(int t, int n, int money[]){ //输出money数组中的红包金额
    for (int i = 0; i < n; i++)
        cout << 0.01 * money[i]  << (i % 5 == 4? '\n':'\t');  //单位为"元"。
}

