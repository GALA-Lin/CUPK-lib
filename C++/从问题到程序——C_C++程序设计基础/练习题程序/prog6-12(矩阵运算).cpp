/*********************************************************************
程序名：多维数组的函数
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-22
说明：6-12.按照文中有关定义处理多维数组的函数的规定，写出求 4 × 4 的
矩阵相加、相减和相乘的函数。
*********************************************************************/
#include <iostream>
using namespace std;

const int N = 4;	//全局常变量

void MatPlus(int n, double a[][N], double b[][N], double c[][N]) {//矩阵加法
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < N; j++)
			c[i][j] = a[i][j] + b[i][j];
	return;
}

void MatMinus(int n, double a[][N], double b[][N], double c[][N]) {//矩阵减法
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < N; j++)
			c[i][j] = a[i][j] - b[i][j];
	return;
}


void MatMulti(int n, double a[][N], double b[][N], double c[][N]) {//矩阵乘法
	int i, j, k;
	double x;

	for (i = 0; i < n; ++i)
		for (j = 0; j < N; ++j) {
			for (x = 0.0, k = 0; k < N; ++k)
				x += a[i][k] * b[k][j];
			c[i][j] = x;
		}
	return;
}

void MatInit0(int n, double mat[][N]) {	//矩阵全部元素初始化为 0
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < N; j++)
			cout << mat[i][j] << (j != N-1 ? "\t" : "\n");
}

void PrintMat(int n, double mat[][N]) {	//打印 n * N 的矩阵
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < N; j++)
			cout << mat[i][j] << (j != N-1 ? "\t" : "\n");
}

int main() {
	// 定义数组 matA 和 matB，并用示例数据初始化
	double matA[N][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	double matB[N][N] = {0.1, 0.2, 0.3, 0.4, 1.1, 1.2, 1.3, 1.4,
	                     2.1, 2.2, 2.3, 2.4, 3.1, 3.2, 3.3, 3.4
	                    };
	double matC[N][N] = {0}; //定义数组C并初始化（所有元素初始化为0）

	cout << "\n矩阵相加：\n";
	MatPlus(N, matA, matB, matC);
	PrintMat(N, matC);

	cout << "\n矩阵相减：\n";
	MatMinus(N, matA, matB, matC);
	PrintMat(N, matC);

	cout << "\n矩阵相乘：\n";
	MatMulti(N, matA, matB, matC);
	PrintMat(N, matC);

	return 0;
}

