/*********************************************************************
程序名：台球 
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：
8-7.考虑定义一个在斯诺克（snooker）台球运动中计算台球位置的函数，这个函数的一个
参数应当是一个表示台球状态的结构体，其成员至少包括：台球半径、当前位置，
速度向量。把台球桌的大小作为程序常量，定义计算t 时间后台球状态的函数。
进一步考虑桌面阻力因素和台球桌边沿的弹性系数，修改前面定义的函数，使其能够
更好地反映现实世界的情况。考虑利用这个函数做一个有趣的程序实例。
*********************************************************************/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

typedef struct snookerball{
	double radius;
	double x, y;	//屏幕横向自左向右为 X 轴，纵向自上向下为 Y 轴 
	double vx, vy;	
} snookerball;

const double tablelen = 3569, tablewid = 1778; 	//标准斯诺克台球桌的大小
const double friction = 0.1; 	//桌面的阻力系数 
const double elasticity = 0.9;	//桌边沿的弹性系数

void ballpos (snookerball *ball, double dt) {
	double dt2 = 0.001; //为了精确的计算台球位置，需要按一个更小的时间间隔来计算台球位置
	int total = dt / dt2;	//原有时间划分为多少个更小时间间隔
	double vx, vy;

	for (int i = 0; i < total; i++ ) {	太麻烦太琐碎了，不想写了！ 
		vx = ball->vx;	//原速度 
		vy = ball->vy;
		ball->vx = ball->vx * (1 - friction * dt2);	//新速度 
		ball->vy = ball->vy * (1 - friction * dt2);
		
		//下面的计算方法不甚准确，会有一些误差。暂且写成这样 
		ball->x += (vx + ball->vx) / 2 * dt2;	//用平均速度计算新位置 
		if (ball->x > tablelen)	//如果超出桌面范围 
			ball->x = tablelen * 2 - ball->x;
		if (ball->x < 0)
			ball->x = - ball->x;
			
		ball->y += (vy + ball->vy) / 2 * dt2;
		if (ball->y > tablewid)	//如果超出桌面范围 
			ball->y = tablewid * 2 - ball->y;
		if (ball->y < 0)
			ball->y = - ball->y;
	}
	 
}
int main() {
    snookerball ball;	//定义变量 ball
	ball.radius = 52.5 / 2;	//标准斯诺克台球的直径为 52.5mm 
	ball.x = tablelen / 2; 	//初始时将球置于台球中心
	ball.y = tablewid / 2; 
	ball.vx = 500.0;
	ball.vy = 200.0;
	
	double dt = 0.2;	//时间间隔
	double t = 0;	//时间 
	
	while (ball.vx > 0.1 || ball.vy > 0.1 ) {
		ballpos(&ball, dt);	//计算在 dt 时间间隔之后的位置 
		t += dt;
		cout << t << ": " << ball.x << ", "  << ball.y << "\tvelocity: " << ball.vx << ", " << ball.vy << endl;
	}
    return 0;
}
/* 
当代的高级程序常常建议SDL、GTK+、Qt等图形库实现在程序中2D绘图，然而都颇为复杂。
都需要用户学好C++面向对象程序设计才行。



在 MinGW 中提供了 Gdi+ 图形库。
GDI+由一组C++类实现,是对于GDI的继承,GDI+不仅优化了大部分GDI性能而且提供了更多特性。
允许应用程序开发者将信息显示在显示器或者打印机上，而无需考虑该显示设备的详细情况,
GDI+与GDI一样，都具有设备无关性，使得应用程序和图形硬件隔离开来。 



//用 Turbo C 及其图形库所编写的台球游戏： 
//A Turbo C snooker，https://github.com/rickytan/Snooker
//球体运动参见 SNOOKER.C 中的 move 函数 
//由于 Turbo C 已经过时无法在Windows使用，最好是改用其它图形库。
有两个选择： 
1. OpenBGI（又叫做 Win32 BGI implementation）：
	https://sourceforge.net/projects/openbgi/ 
An implementation of old BGI library(simple graphics library) (that was 
included in Turbo C++, Borland C++) for Microsoft Windows for use with 
MinGW/MSVC(6,2002,2003 2005). The main feature is good debugging support.
很容易下载到，但是居然不知道如何编译生成目标文件。
 
2. WinBGIm
	http://winbgim.codecutter.org/
	https://github.com/Duthomhas/WinBGIm-fixed-sort-of-
Borland BGI Graphics emulation for the MingW (GCC port) Compiler



 EasyX 只适用于 Visual C++ 



//更多想法，可以参见如下用C++编写的斯诺克游戏程序：
// https://github.com/M3hrdadR/Snooker   需要使用SFML图形库
//球体运动：https://github.com/M3hrdadR/Snooker/blob/master/Sources/Ball.cpp 
//用C++和SFML写游戏-SFML介绍：https://blog.csdn.net/qq_33567644/article/details/91126507
//SFML从入门到放弃：https://www.cnblogs.com/karl07/p/10285692.html

*/
