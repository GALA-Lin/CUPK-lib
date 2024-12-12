#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author, int year,  bool valid = true); // 构造函数
    Book(const Book& other); // 复制构造函数
    Book& operator=(const Book& other); // 赋值操作符重载
    ~Book(); // 析构函数
    void display() const; // 显示书籍信息
    static int getBookCount(); // 获取书籍数量
    friend void borrowBook(Book& book); // 借阅书籍
    friend void returnBook(Book& book); // 归还书籍
    friend void isBorrowable(const Book& book); // 是否可借阅

private:
    static int bookCount; // 静态数据成员，记录书籍数量
    std::string title; // 书名
    std::string author; // 作者
    int year; // 出版年份
    bool valid; // 有效性
};

// 静态数据成员初始化
int Book::bookCount = 0;

// 构造函数
Book::Book(const std::string& title, const std::string& author, int year ,bool valid) 
    : title(title), author(author), year(year) , valid(valid) {
    bookCount++;
}

// 复制构造函数
Book::Book(const Book& other) 
    : title(other.title), author(other.author), year(other.year) , valid(true) {
    bookCount++;
}

// 赋值操作符重载
Book& Book::operator=(const Book& other) {
    if (this != &other) { // 防止自我赋值
        title = other.title;
        author = other.author;
        year = other.year;
        valid = true;
    }
    return *this;
}

// 显示书籍信息
void Book::display() const {
    std::cout << "书名: " << title << ", 作者: " << author << ", 出版年份: " << year  << ", 状态: " << (valid ? "可借" : "不可借") << std::endl;
}

// 获取书籍数量
int Book::getBookCount() {
    return bookCount;
}
// 析构函数
Book::~Book() {
    bookCount--;
}

//借阅书籍
void borrowBook(Book& book) {
    if (book.valid) {
        book.valid = false;
        std::cout << book.title <<"借阅成功！" << std::endl;
    } else {
        std::cout << book.title << "已被借阅！" << std::endl;
    }
}

//归还书籍
void returnBook(Book& book) {
    if (!book.valid) {
        book.valid = true;
        std::cout << book.title << "归还成功！" << std::endl;
    } else {
        std::cout <<book.title << "未被借阅！" << std::endl;
    }
}
//是否可借
void isBorrowable(const Book& book) {
    if (book.valid) {
        std::cout << book.title << "可借阅！" << std::endl;
    } else {
        std::cout << book.title << "不可借阅！" << std::endl;
    }
}
#endif // BOOK_H
