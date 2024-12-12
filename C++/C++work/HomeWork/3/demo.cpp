#include <iostream>
using namespace std;

class Base {
public:
    Base(int i=0):i(i) {}
    virtual void f();
    virtual void g();
private:
    int i;
};

class Derived : public Base {
public:
    Derived(int j=100):j(j) {}
    virtual void f();
    virtual void h();
private:
    int j;
};

void Base::f() {
    i++;
    cout << "Base::f() i++=" << i << endl;
}

void Base::g() {
    i+=10;
    cout << "Base::g() i+10=" << i << endl;
}

void Derived::f() {
    j++;
    cout << "Derived::f() j++=" << j << endl;
}
void Derived::h() {
    j+=100;
    cout << "Derived::h() j+100=" << j << endl;
}
int main() {
    cout<<"virtual function object call:"<<endl;
    Base base;
    Derived derived;
    cout<<"base object call:"<<endl;
    base.f();
    base.g();
    cout<<"derived object call:"<<endl;
    derived.f();
    derived.h();
    cout<<"virtual function base pointer call:"<<endl;
    Base *bp = &base;
    Derived *dp = &derived;
    cout<<"base pointer call:"<<endl;
    bp->f();
    bp->g();
    cout<<"derived pointer call:"<<endl;
    dp->f();
    dp->h();
    cout<<"\n"<<"\n";
    return 0;
}
