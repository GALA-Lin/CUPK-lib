
//Hanoi塔问题在高程或数据结构教材上都有介绍，
//程序也很简单，但是不能直观显示当前各柱上的圆盘数。 
//改进：用一个二维数组分别存储三柱上的当前圆盘，并添加打印输出函数，直观形象。 
 
#include<stdio.h>
#include<process.h> //进程函数。如 exit() */

int c=0; /* 全局变量，搬动次数 */
int np=0;	/* 全局变量，盘子数 */
#define NMAX 20
int h[3][NMAX],num[3];	// h 数组存储当前圆盘编号，num 数组存储三柱的个数。 

void printall(){ 	//打印 
	int i, j;
	for (i=0; i<3; i++){  
		printf("%c ",'a'+i);//柱名称 a b c
		for (j=0; j<np; j++){
			if (h[i][j] >0 ) 
				printf("%1d", h[i][j]);
			else 
				printf(" ");
		}
		printf("  ");
	}
	printf("\n");
}

void move(char x, int n, char z) {	
	/* 第n个圆盘从塔座 x 搬到塔座 z */
	printf("%i:   %c %i --> %c    ", ++c, x, n, z);
	
	//更新盘子存放情况。
	//来源柱减小1个 
	//编程小技巧：把三柱的编号由字母 a、b、c 转换为整数0、1、2： x-'a' 
	h[x-'a'][num[x-'a']-1]=0;
	num[x-'a']--;
	//目标柱增加1个 
	num[z-'a']++;
	h[z-'a'][num[z-'a']-1] = n;
	
	printall();	//打印 

}

void hanoi(int n,char x,char y,char z) { /* 算法3.5 */
	/* 将塔座x上按直径由小到大且自上而下编号为1至n的n个圆盘 */
	/* 按规则搬到塔座z上。y可用作辅助塔座 */
	if(n==1) 
		move(x,1,z); /* 将编号为1的圆盘从x移到z */
	else {
		if(n==np) printf("请把 %d 个盘从 %c 柱借助 %c 柱移到 %c 柱\n",n-1, x, z, y);
		hanoi(n-1,x,z,y); /* 将x上编号为1至n-1的圆盘移到y，z作辅助塔 */

		if(n==np) printf("哈哈，我只要把 %d 号盘从 %c 柱移到 %c 柱\n",n, x, z);
		move(x,n,z); /* 将编号为n的圆盘从x移到z */
		
		if(n==np) printf("请把 %d 个盘从 %c 柱借助 %c 柱移到 %c 柱\n",n-1, y, x, z);
		hanoi(n-1,y,x,z); /* 将y上编号为1至n-1的圆盘移到z，x作辅助塔 */
	}
}

int main() {
	int i;
	
	printf("以递归方式求解 Hanoi 塔问题\n");
	printf("3 个塔座为a、b、c，圆盘最初在 a 座，借助 b 座移到 c 座。\n");
	np=4;	//可以在程序内部设置盘子数，或者以下面两行允许用户输入盘子数。 
	printf("请输入圆盘数(1-%d)：", NMAX);
	scanf("%d%*c",&np);	  //小技巧：在 scanf 函数的格式串中添加 %*c，吞掉最后的回车符。 
	//提示：由于打印函数是在一行内输出所有数字，因此当 np>= 14 时就会换行，不够美观。	
	printf("\n");
	if (np<=0) {
		printf("错误：圆盘数 %d <= 0!", np); 
		exit(1);
	}
	
	for (i=0; i<np; i++){
		h[0][i]=np-i;
		h[1][i]=0;
		h[2][i]=0;
	}
	num[0]=np;
	num[1]=0;
	num[2]=0;
	
	printf("初始状态：        ");
	printall();	//打印
	
	hanoi(np,'a','b','c');
	
	return 0;
}
