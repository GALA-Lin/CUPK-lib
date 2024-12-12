#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <cstring>

class Animal
{
private:
    char *name;
    static int count; // 静态数据成员，用于记录动物的数量

public:
    Animal(const char *name);
    Animal(const Animal &other);            // 复制构造函数
    Animal &operator=(const Animal &other); // 拷贝赋值运算符重载
    virtual ~Animal();

    static int getCount();                       // 获取动物数量
    virtual void sound() const = 0;              // 纯虚函数，虚函数是一种接口，用于子类实现
    void setName(const char *name);              // 设置名字
    const char *getName() const { return name; } // 数据保护，Animal类是抽象类，不允许直接访问name成员
    // 第一个const表示方法不能修改成员变量，第二个const表示方法不能修改this指针
};
// 继承关系：Animal -> Dog
class Dog : public Animal
{
public:
    Dog(const char *name);
    void sound() const override; // 重写虚函数
};
class Cat : public Animal
{
public:
    Cat(const char *name) : Animal(name) {}
    void sound() const override
    {
        std::cout << getName() << ": \"喵喵喵\"" << std::endl;
    }
};

//以下是方法实现

int Animal::count = 0; // 初始化静态数据成员

Animal::Animal(const char *name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    count++;
}

Animal::Animal(const Animal &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    count++;
}
// 拷贝赋值运算符重载
Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        delete[] name; // 防止内存泄漏
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
    return *this;
}

// 修改名字
void Animal::setName(const char *name)
{
    std::cout<<"修改"<<this->name;
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    std::cout<<"为"<<this->name<<"修改成功"<<std::endl;
}

Animal::~Animal()
{
    delete[] name;
    count--;
}

int Animal::getCount()
{
    return count;
}

Dog::Dog(const char *name) : Animal(name) {}

void Dog::sound() const
{
    std::cout << getName() << ": \"汪汪汪\""<< std::endl;
}



#endif // ANIMAL_H