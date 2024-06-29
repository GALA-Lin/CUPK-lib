/*********************************************************************
������������ 
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����
8-4.������������ʵ�ֵĸ����ṹ�弰����غ�������Ϊ������һЩ���õĺ�����
���һ������ʽ�ĸ�������ϵͳ������������
*********************************************************************/

#include <iostream>
using namespace std;

typedef struct Complex { 
    double re, im;    //real part, image part
} Complex;

//�����ṹ�����������ݺ��٣�ʹ��ֵ�Σ��β�ֵ��ͨ�����ƴ��ݽ���������ֵ�Ǹ��ƴ��ݳ�ȥ�� 
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

Complex tmscx(Complex x, Complex y) {   //�˷�
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
    
    //��������ʵ���Դ���c1 
    cout << "Please input two double to create c1: ";
    if (!(cin >> re >> im)) { //!! 
        cout << "Error in inputting real number! \nExit abnormally.\n";
        exit(1);
    }
        
    c1 = createcx (re, im);    //!!
    prtcx2("c1 = ", c1, "\n");
    
    //ʹ�����뺯������c2 
    if (!readcx ("Please input c2 (re, im): ", &c2)) { //!! 
        cout << "Error in read complex c2! \nExit abnormally.\n";
        exit(1);
    }
    prtcx2("c2 = ", c2, "\n\n");
    
    //�����ӷ�
    c3 = addcx(c1, c2) ;
    prtcx2("c1 + c2 = ", c3, "\n");
    
    //��������
    c3 = subcx(c1, c2) ;
    prtcx2("c1 - c2 = ", c3, "\n");

    //�����˷�
    c3 = tmscx(c1, c2) ;
    prtcx2("c1 * c2 = ", c3, "\n");

    //�������� 
    c4 = divcx(c1, c2) ;
    prtcx2("c1 / c2 = ", c4, "\n");
    
    return 0;
}

