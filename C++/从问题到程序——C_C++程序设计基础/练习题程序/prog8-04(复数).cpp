/*********************************************************************
程序名：复数 
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：
8-4.完成正文中设计实现的复数结构体及其相关函数，再为它增加一些有用的函数。
设计一个交互式的复数计算系统界面主函数。
*********************************************************************/

#include <iostream>
using namespace std;

typedef struct Complex { 
    double re, im;    //real part, image part
} Complex;

//复数结构体中所含数据很少，使用值参（形参值是通过复制传递进来，返回值是复制传递出去） 
Complex createcx(double re, double im){
    Complex c;
    c.re = re;
    c.im = im;
    return c;
}

Complex addcx(Complex x, Complex y) {
    Complex c;
    c.re = x.re + y.re;
    c.im = x.im + y.im;
    return c;
}

Complex subcx(Complex x, Complex y) {
    Complex c;
    c.re = x.re - y.re;
    c.im = x.im - y.im;
    return c;
}

Complex tmscx(Complex x, Complex y) {   //乘法
    Complex c;
    c.re = x.re * y.re - x.im * y.im;
    c.im = x.re * y.im + x.im * y.re;
    return c;
}

Complex divcx(Complex x, Complex y) {
    Complex c;
    double den = y.re * y.re + y.im * y.im;

    if (den == 0.0) {
        cout << "Complex error: divid 0.\n";
        c.re = 1;
        c.im = 0;
    } else {
        c.re = (x.re * y.re + x.im * y.im) / den;
        c.im = (x.im * y.re - x.re * y.im) / den;
    }
    return c;
}

void prtcx(Complex x) { 
    cout << "(" << x.re << ", " << x.im << "i)";
}

void prtcx2(const char *str1, Complex x, const char *str2) { 
    cout << str1;
    prtcx (x);
    cout << str2;
}

int readcx(const char *prompt, Complex *pcx) {
    cout << prompt;
    if (cin >> pcx->re && cin >> pcx->im )
        return 1;
    else
        return 0;
};

int main() {
    Complex c1, c2, c3, c4;
    double re, im;
    
    //输入两个实数以创建c1 
    cout << "Please input two double to create c1: ";
    if (!(cin >> re >> im)) { //!! 
        cout << "Error in inputting real number! \nExit abnormally.\n";
        exit(1);
    }
        
    c1 = createcx (re, im);    //!!
    prtcx2("c1 = ", c1, "\n");
    
    //使用输入函数创建c2 
    if (!readcx ("Please input c2 (re, im): ", &c2)) { //!! 
        cout << "Error in read complex c2! \nExit abnormally.\n";
        exit(1);
    }
    prtcx2("c2 = ", c2, "\n\n");
    
    //复数加法
    c3 = addcx(c1, c2) ;
    prtcx2("c1 + c2 = ", c3, "\n");
    
    //复数减法
    c3 = subcx(c1, c2) ;
    prtcx2("c1 - c2 = ", c3, "\n");

    //复数乘法
    c3 = tmscx(c1, c2) ;
    prtcx2("c1 * c2 = ", c3, "\n");

    //复数除法 
    c4 = divcx(c1, c2) ;
    prtcx2("c1 / c2 = ", c4, "\n");
    
    return 0;
}

