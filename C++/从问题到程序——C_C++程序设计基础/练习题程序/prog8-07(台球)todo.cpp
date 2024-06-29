/*********************************************************************
��������̨�� 
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����
8-7.���Ƕ���һ����˹ŵ�ˣ�snooker��̨���˶��м���̨��λ�õĺ��������������һ��
����Ӧ����һ����ʾ̨��״̬�Ľṹ�壬���Ա���ٰ�����̨��뾶����ǰλ�ã�
�ٶ���������̨�����Ĵ�С��Ϊ���������������t ʱ���̨��״̬�ĺ�����
��һ�����������������غ�̨�������صĵ���ϵ�����޸�ǰ�涨��ĺ�����ʹ���ܹ�
���õط�ӳ��ʵ���������������������������һ����Ȥ�ĳ���ʵ����
*********************************************************************/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

typedef struct snookerball{
	double radius;
	double x, y;	//��Ļ������������Ϊ X �ᣬ������������Ϊ Y �� 
	double vx, vy;	
} snookerball;

const double tablelen = 3569, tablewid = 1778; 	//��׼˹ŵ��̨�����Ĵ�С
const double friction = 0.1; 	//���������ϵ�� 
const double elasticity = 0.9;	//�����صĵ���ϵ��

void ballpos (snookerball *ball, double dt) {
	double dt2 = 0.001; //Ϊ�˾�ȷ�ļ���̨��λ�ã���Ҫ��һ����С��ʱ����������̨��λ��
	int total = dt / dt2;	//ԭ��ʱ�仮��Ϊ���ٸ���Сʱ����
	double vx, vy;

	for (int i = 0; i < total; i++ ) {	̫�鷳̫�����ˣ�����д�ˣ� 
		vx = ball->vx;	//ԭ�ٶ� 
		vy = ball->vy;
		ball->vx = ball->vx * (1 - friction * dt2);	//���ٶ� 
		ball->vy = ball->vy * (1 - friction * dt2);
		
		//����ļ��㷽������׼ȷ������һЩ������д������ 
		ball->x += (vx + ball->vx) / 2 * dt2;	//��ƽ���ٶȼ�����λ�� 
		if (ball->x > tablelen)	//����������淶Χ 
			ball->x = tablelen * 2 - ball->x;
		if (ball->x < 0)
			ball->x = - ball->x;
			
		ball->y += (vy + ball->vy) / 2 * dt2;
		if (ball->y > tablewid)	//����������淶Χ 
			ball->y = tablewid * 2 - ball->y;
		if (ball->y < 0)
			ball->y = - ball->y;
	}
	 
}
int main() {
    snookerball ball;	//������� ball
	ball.radius = 52.5 / 2;	//��׼˹ŵ��̨���ֱ��Ϊ 52.5mm 
	ball.x = tablelen / 2; 	//��ʼʱ��������̨������
	ball.y = tablewid / 2; 
	ball.vx = 500.0;
	ball.vy = 200.0;
	
	double dt = 0.2;	//ʱ����
	double t = 0;	//ʱ�� 
	
	while (ball.vx > 0.1 || ball.vy > 0.1 ) {
		ballpos(&ball, dt);	//������ dt ʱ����֮���λ�� 
		t += dt;
		cout << t << ": " << ball.x << ", "  << ball.y << "\tvelocity: " << ball.vx << ", " << ball.vy << endl;
	}
    return 0;
}
/* 
�����ĸ߼����򳣳�����SDL��GTK+��Qt��ͼ�ο�ʵ���ڳ�����2D��ͼ��Ȼ������Ϊ���ӡ�
����Ҫ�û�ѧ��C++������������Ʋ��С�



�� MinGW ���ṩ�� Gdi+ ͼ�ο⡣
GDI+��һ��C++��ʵ��,�Ƕ���GDI�ļ̳�,GDI+�����Ż��˴󲿷�GDI���ܶ����ṩ�˸������ԡ�
����Ӧ�ó��򿪷��߽���Ϣ��ʾ����ʾ�����ߴ�ӡ���ϣ������迼�Ǹ���ʾ�豸����ϸ���,
GDI+��GDIһ�����������豸�޹��ԣ�ʹ��Ӧ�ó����ͼ��Ӳ�����뿪���� 



//�� Turbo C ����ͼ�ο�����д��̨����Ϸ�� 
//A Turbo C snooker��https://github.com/rickytan/Snooker
//�����˶��μ� SNOOKER.C �е� move ���� 
//���� Turbo C �Ѿ���ʱ�޷���Windowsʹ�ã�����Ǹ�������ͼ�ο⡣
������ѡ�� 
1. OpenBGI���ֽ��� Win32 BGI implementation����
	https://sourceforge.net/projects/openbgi/ 
An implementation of old BGI library(simple graphics library) (that was 
included in Turbo C++, Borland C++) for Microsoft Windows for use with 
MinGW/MSVC(6,2002,2003 2005). The main feature is good debugging support.
���������ص������Ǿ�Ȼ��֪����α�������Ŀ���ļ���
 
2. WinBGIm
	http://winbgim.codecutter.org/
	https://github.com/Duthomhas/WinBGIm-fixed-sort-of-
Borland BGI Graphics emulation for the MingW (GCC port) Compiler



 EasyX ֻ������ Visual C++ 



//�����뷨�����Բμ�������C++��д��˹ŵ����Ϸ����
// https://github.com/M3hrdadR/Snooker   ��Ҫʹ��SFMLͼ�ο�
//�����˶���https://github.com/M3hrdadR/Snooker/blob/master/Sources/Ball.cpp 
//��C++��SFMLд��Ϸ-SFML���ܣ�https://blog.csdn.net/qq_33567644/article/details/91126507
//SFML�����ŵ�������https://www.cnblogs.com/karl07/p/10285692.html

*/
