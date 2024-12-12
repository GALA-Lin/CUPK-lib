#include <iostream>
#include <cassert>
using namespace std;
class Point {
public:
	Point() : x(0), y(0) {
		cout<<"默认构造函数被调用。" << endl;
	}
	Point(int x, int y) : x(x), y(y) {
		cout<< "构造函数被调用。" << endl;
	}
	~Point() { cout<<"析构函数被调用。" << endl; }
	int getX() const { return x; }
	int getY() const { return y; }
	void move(int newX, int newY) {
		x = newX;
		y = newY;
	}
private:
	int x, y;
};


class ArrayOfPoints { // 动态数组类
public:
	ArrayOfPoints(int size) : size(size) {
		points = new Point[size];
	}
	~ArrayOfPoints() {
		cout << "正在删除..." << endl;
		delete[] points;     
	}
	Point& element(int index) {
		assert(index >= 0 && index < size);	
		return points[index];
	}
private:
	Point *points; // 指向动态数组首地址
	int size;     // 数组大小
};

int main() {
	int count;
	cout << "请输入点的数量: ";
	cin >> count;
	ArrayOfPoints points(count);	// 创建数组对象
	points.element(0).move(5, 0);   // 访问数组元素的成员
	points.element(1).move(15, 20);  // 访问数组元素的成员
	return 0;
}
