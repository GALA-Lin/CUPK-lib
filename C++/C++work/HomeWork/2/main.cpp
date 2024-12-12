#include "Animal.h"

int main() {
    //因为Dog是Animal的子类，Dog的构造函数会调用Animal的构造函数，所以Animal的count会加1，
    Animal *dog1 = new Dog("大黄");
    Animal *dog2 = new Dog("小白"); 
    Animal *cat1 = new Cat("小花");
    std::cout << "当前动物数量: " << Animal::getCount() << std::endl;
    // 调用Dog的sound()
    dog1->sound(); 
    dog2->sound(); 
    // 调用Cat的sound()
    cat1->sound();
    Animal *dog3 = new Dog(*dynamic_cast<Dog*>(dog1)); // 使用复制构造函数
    std::cout << "1次复制之后，动物数量: " << Animal::getCount() << std::endl;

    dog3->sound();
    //修改dog3的名字
    dog3->setName("小黑");
    dog3->sound();

    // 删除动态分配的内存，释放内存
    delete dog1;
    delete dog2;
    delete dog3;

    std::cout << "删除dog之后，动物数量: " << Animal::getCount() << std::endl;
    delete cat1;
    std::cout << "删除cat之后，动物数量: " << Animal::getCount() << std::endl;
    return 0;
}
