/*********************************************************************
程序名：矩阵转置
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
7-8.（*）矩阵是数值计算中最常用的结构之一，在程序里可以很自然地采用两维
数组表示。请按照本章提出的处理两维数组的通用函数的技术，写出实现矩阵转置
的函数。函数原型为：TransMatrix (int m, int n, double *mat, double *trans)，
实现把 m 行 n 列的二维数组 mat 转置为 n 行 m 列的二维数组 trans。
*********************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//教材上提供的矩阵打印函数，输出格式中添加了 fixed 和 setprecision，以便整齐打印。
void prtMatrix (int m, int n, double *mat) {
    int i, j;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j)
            cout << fixed << setprecision(2) << *(mat + i * n + j) << "\t";
        putchar('\n');
    }
}

void TransMatrix (int m, int n, double *mat, double *trans) {
//把 m 行 n 列的矩阵 mat 转置为 n 行 m 列的矩阵 trans
    int i, j;
    for (i = 0; i < m; ++i) 	// 把 mat 转置的结果存放于 t 中
        for (j = 0; j < n; ++j)
            *(trans + j * m + i) = *(mat + i * n + j);
    //转置操作实际是希望进行如下赋值：trans[j][i] = mat[i][j]。但此函数中不能用这种写法。
    //对于 m 行 n 列的数组 mat，其 i 行 j 列的元素的地址是 &mat[0][0] + i * n + j。
    //对于 n 行 m 列的数组 trans，其 j 行 i 列的元素的地址是 &trans[0][0] + j * m + i。
}

int main() {
    const int ROW = 2, COL = 3;
    double a1[ROW][COL] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}}; //定义二维数组并初始化为示例数据
    double a2[COL][ROW] = {0};

    cout << "原数组 a1 = " << endl;
    prtMatrix (ROW, COL, &a1[0][0]);	//打印原矩阵。请注意第三参数的写法

    TransMatrix (ROW, COL, &a1[0][0], &a2[0][0]);	//!!! 把 a1 转置为 a2

    cout << "\n转置后的数组 a2 = " << endl;
    prtMatrix (COL, ROW, &a2[0][0]);	//打印转置后的矩阵。请注意行与列的参数。

    return 0;
}

