/*********************************************************************
程序名：猜单词
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
7-13.（*）修改第五章的猜数程序，通过命令行参数为它提供数的范围。

解答：对原有程序只需要简单修改两条语句即可：1、main 函数中需要相应的参数表；
2、猜数范围最大值 max 不再由 getrange 函数提供，而是改由命令行参数 argv[1] 提供。
**********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int next();
int getrange();
int getnumber(int limit);

//int main() {
int main(int argc, char *argv[]) {	//!!!主程序中需要参数表
//要测试此函数的效果，则需要把此程序进行编译以生成可执行文件，然后在命令行窗口下
//手工键入该可执行文件的文件名并附带参数。
//附注：如果编译生成的可执行文件的名称中带有括号（例如：prog7-09(猜数).exe），
//则命令行可能无法识别该文件名。因此需要在该文件名左右添加英文双引号。例如写成：
//   "prog7-09(猜数).exe"  20

    int max, unknown, guess;

    cout << "== Number-Guessing Game ==" << endl;
    if (argc == 1) { //!!!未带参数执行（argc 为 1，argv[0] 为程序名），仍使用原有的函数
    	cout << "当前是未带参数执行，仍使用原有的函数来设定猜数范围\n";
    	if ((max = getrange()) < 0) return 1;//给定猜数范围。若出错次数太多则退出
    } else	//!!!带参数执行，则命令行参数提供猜数范围
		max = atoi(argv[1]);	//!!!猜数范围最大值 max 改由命令行参数 argv[1] 提供
    	//函数 atoi （来源于英文“ascii to integer”)是把字符串转换成整型数的函数。
    cout << "range max = " << max << endl;

    srand(time(0));
    do {
        unknown = rand() % (max + 1);
        cout << "\nA new random number generated. \n";
        while (1) {
            if ((guess = getnumber(max)) < 0) {    //猜错次数太多则退出
                cout << "Too many errors. Stop!";
                return 2;
            }
            if (guess > unknown) cout <<"Too big!\n";
            else if (guess < unknown) cout <<"Too small!\n";
            else {
                cout << "Congratulation! You win!\n";
                break;
            }
        }
    } while (next());

    cout<< "Game over.\nThanks for playing!\n";
    return 0;
}

const int ERRORNUM = 5;

int getrange() {
    int i, m;
    for (i = 0; i < ERRORNUM; ++i) {
        cout << "Choose a range [0, max]. Input max: ";
        if ( !(cin >> m) || m < 2 || m > RAND_MAX) {
            cout << "Wrong number. Need a number in 2~" << RAND_MAX << endl;
            cin.clear(); //清除错误标记
            cin.sync();  //清空缓冲区
            cout << "Input again: ";
        } else
            return m;
    }
    return -1;
}

int getnumber(int m) {
    int i, n;
    for (i = 0; i < ERRORNUM; ++i) {
        cout << "Your guess: ";
        if (!(cin >> n) || n < 0 || n > m) {
            cout<< "Wrong number. Need a number in 0~ " << m << ".\n";
            cin.clear();
            cin.sync();
        } else
            return n;
    }
    return -1;
}

int next() {
    int ch;
    cout << "Next game? (y/n): ";
    while ((ch = toupper(cin.get())) != 'Y' && ch != 'N')
        ;    //空循环体
    cin.clear();
    cin.sync();
    return (ch == 'Y' ? 1 : 0);
}
