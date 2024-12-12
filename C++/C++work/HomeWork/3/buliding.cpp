#include <iostream>
#include <string>

class Structure {
public:
    virtual void info() = 0; // 纯虚函数，输出结构信息
    virtual ~Structure() {} // 虚析构函数
};

class Building : public Structure {
public:
    // 纯虚函数，计算建筑物的面积
    virtual double area() = 0; // 纯虚函数
    virtual void display() = 0; // 纯虚函数
};

// 派生类 House，继承自 Building
class House : public Building {
private:
    double length;    // 房屋长度
    double width;     // 房屋宽度

public:
    // 构造函数
    House(double l, double w) : length(l), width(w) {}

    // 计算面积
    double area() override {
        return length * width;
    }

    // 打印输出函数
    void display() override {
        std::cout << "房屋，长度为：" << length << "，宽度为：" << width 
                  << "，面积为：" << area() << "平方米。" << std::endl;
    }

    // 输出结构信息
    void info() override {
        std::cout << "这是一个房屋结构。" << std::endl;
    }
};

// 派生类 Skyscraper，继承自 Building
class Skyscraper : public Building {
private:
    double baseArea;    // 底面积
    double floors;      // 摩天楼层数

public:
    // 构造函数
    Skyscraper(double area, double f) : baseArea(area), floors(f) {}

    // 计算面积
    double area() override {
        return baseArea * floors;
    }

    // 打印输出函数
    void display() override {
        std::cout << "摩天大楼，底面积为：" << baseArea << "平方米，层数为：" 
                  << floors << "，总面积为：" << area() << "平方米。" << std::endl;
    }

    // 输出结构信息
    void info() override {
        std::cout << "这是一个摩天大楼结构。" << std::endl;
    }
};

// 主函数
int main() {
    std::cout << "创建对象" << std::endl;
    
    // 创建对象
    House myHouse(10.0, 8.0); // 创建房屋对象
    Skyscraper mySkyscraper(500.0, 30.0); // 创建摩天大楼对象

    // 调用接口方法
    myHouse.display();
    mySkyscraper.display();

    std::cout << "\n创建对象，并使用指针指向不同的对象" << std::endl;
    Building* building1 = new House(10.0, 8.0); // 创建房屋对象
    Building* building2 = new Skyscraper(500.0, 30.0); // 创建摩天大楼对象

    std::cout << "\n使用指针调用接口方法" << std::endl;
    building1->display();
    building2->display();

    // 释放内存
    delete building1;
    delete building2;

    return 0;
}
