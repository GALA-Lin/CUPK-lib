/*********************************************************************
程序名：求行列式的值
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
7-9. （*）如果 A 是一个 n * n 的方形矩阵，则 det(A) 或 |A| 表示与 A 对应的
n 阶行列式（具体计算方法参见线性代数教科书），是一个标量。请按照本章提出的
处理两维数组的通用函数的技术，写出实现行列式求值的函数。
函数原型为：double determinant(int n, double *A)
提示：实现矩阵行列式的求值可采用高斯消去法，将矩阵变换为上三角矩阵，则
行列式的值等于位于其对角线上的所有元素的乘积。
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

double determinant(int n, double *A){
	//求行列式的值基本方法：
	//将原有的行列式转化为上三角行列式（对角线下面的所有元素都转化为零），
	//则行列式的值等于位于其对角线上的所有元素的乘积。
	//参见：https://blog.csdn.net/xuejianbest/article/details/85051344
	//https://blog.csdn.net/u013834836/article/details/41073627
	int t;          //标记最大的数所在的行
	double max;     //比较每列时暂时存放最大的数
	double tmp;     //临时变量
	int sign = 0;   //标记行交换的次数
	int i, j, k;
	double det = 1;	//行列式的值

	for(i = 0; i < n-1; i++) {
		t = i;
		max = *(A + i * n + i);	//A[i][i];
		for(j = i + 1; j < n; j++) {//找出每列的最大数
		//当某一行大于k时将其赋值给k，并将其所在行标记下来
			if(fabs(max) < fabs(*(A + j * n + i))) {	//fabs(A[j][i])) {
				max = *(A + j * n + i);	//A[j][i];
				t = j;
			}
		}
		//cout << "t = " << t << "\tMax = " << max << endl;	//debug
		if(fabs(max) < 0.000001) { //判断矩阵是否为奇异矩阵（某列的数字最大值等于0，则整个行列式等于0）
			det = 0;
			return det;	//对于奇异矩阵，函数在此处结束循环并返回行列式的值 0
		}

		if(t != i) {   //当 t 不等于 i 时互换这两行的所有元素，该列的最大值放置到主对角线上
			sign++;	//互换两行的元素时，行列式的值变号。此处记录互换次数
			for(j = i; j < n; j++) {
				tmp = *(A + i * n + j);	//tmp = A[i][j];
				*(A + i * n + j) = *(A + t * n + j);	//A[i][j] = A[t][j];
				*(A + t * n + j) = tmp;					//A[t][j] = tmp;
			}
		}
		//prtMatrix(n, n, A);  cout << "互换完成" << endl;//debug

		for(j=i+1; j<n; j++) { //消去过程，化为上三角的形式
			tmp = *(A + j * n + i) / *(A + i * n + i);	// tmp = A[j][i] / A[i][i];  //避免了k每次变化时都要计算
			for(k = i; k < n; k++)      //请注意初始时 k = i
				*(A + j * n + k) = *(A + j * n + k) - *(A + i * n +k) * tmp;	//A[j][k] = A[j][k] - A[i][k] * tmp;
		}
		prtMatrix(n, n, A);
		cout << endl;
	}
	//非奇异矩阵在结束循环时变换为上三角形，行列式的值等于位于其对角线上的所有元素的乘积。
	det = (sign %2 == 0 ? 1 : -1);	//两行元素互换次数为偶数，则为正号；奇数为负号。
	for(i = 0; i < n; i++)    //求化简后行列式的值
		det *= *(A + i * n + i);	//det *= A[i][i];

	return det;
}

int main() {
	cout << "求行列式的值\n\n";
	int n = 4;	//矩阵的阶数

	double A[n][n] = {	//定义以变量为长度的矩阵（符合 C99 和 C++标准）以示例数据初始化
		{3.2, 2.5, 1.8, 2.2},
		{2.2, 2.4, 4.3, 2.5},
		{3.1, 3.5, 6.2, 2.4},
		//{4.3, 8.7, 9.2, 2.7}
		{0  , 0  , 0  , 0  }	//此行全为0，奇异矩阵（行列式等于0）。
	};

	//上面是定义示例矩阵以供测试，用户也可以手工输入矩阵阶数和数据。
//	cout<<"请输入行列式 A 的阶数：" << n << endl;
//	cin >> n;
//	double A[n][n];	//定义以变量为长度的矩阵（符合 C99 和 C++标准）
//	for(i = 1; i<= n; i++) {
//		cout << "请输入A的第 " << i << " 行元素,各元素间以空格间隔:\n";
//		for(j = 1; j <= n; j++)
//			cin >> A[i-1][j-1];
//	}


	prtMatrix(n, n, &A[0][0]);
	cout << endl;

	//用函数计算行列式的值
	cout << "行列式的值是："<< determinant(n, &A[0][0]) << "\n";	//!!!

	//下面是写在主程序中（可以使用数组写法）的解法

//	int t;          //标记最大的数所在的行
//	double max;     //比较每列时暂时存放最大的数
//	double tmp;     //临时变量
//	int sign = 0;   //行交换的次数
//	int i, j, k;
//	double det = 1;	//行列式的值（此处要求把它初始化为 1，以便能方便地处理奇异矩阵）
//	for(i = 0; i < n-1; i++) {
//		t = i;
//		max = A[i][i];
//		for(j = i + 1; j < n; j++) {//找出每列的最大数
//			if(fabs(max) < fabs(A[j][i])) {	//当某一行大于 max 时将其赋值给 max，并将其所在行标记下来
//				max = A[j][i];
//				t = j;
//			}
//		}
//		if(fabs(max) < 0.000001) { //判断矩阵是否为奇异矩阵（某列的数字最大值等于0，则整个行列式等于0）
//			det = 0;	//奇异矩阵的行列式值为 0
//			break;
//		}
//
//		if(t != i) {  //当 t 不等于 i 时互换这两行的所有元素，该列的最大值放置到主对角线上
//			sign++;	//互换两行的元素时，行列式的值变号。此处记录互换次数
//			for(j = i; j < n; j++) {
//				tmp = A[i][j];
//				A[i][j] = A[t][j];
//				A[t][j] = tmp;
//			}
//		}
//
//		for(j = i+1; j< n; j++) { //消去过程，化为上三角的形式
//			tmp = A[j][i] / A[i][i];    //避免了 k 每次变化时都要计算这个
//			for(k = i; k < n; k++)      //请注意初始时 k = i
//				A[j][k] = A[j][k] - A[i][k] * tmp;
//		}
//		prtMatrix(n, n, &A[0][0]);
//		cout << endl;
//	}
//	//可能是奇异矩阵中途跳出循环，也可能是非奇异矩阵变换为上三角形而正常结束循环。
//	//变换为上三角形之后，行列式的值等于位于其对角线上的所有元素的乘积。
//	if (det !=0) { //非奇异矩阵
//		det = (sign %2 == 0 ? 1 : -1);	//两行元素互换次数为偶数，则为正号；奇数为负号。
//		for(i = 0; i < n; i++)    //求化简后行列式的值
//			det *= A[i][i];
//	}
//	cout << "行列式的值是："<< det << "\n";

	return 0;
}
