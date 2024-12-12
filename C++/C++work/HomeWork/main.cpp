#include "Book.h"

int main() {
    Book book1("西游记", "吴承恩", 1592,true); // 创建书籍1
    book1.display(); // 显示书籍1信息

    Book book2("红楼梦", "曹雪芹", 1791,false); // 创建书籍2
    book2.display(); // 显示书籍2信息

    Book book3 = book1; // 使用复制构造函数创建书籍3
    book3.display(); // 显示书籍3信息
    std::cout << "书籍3借阅状态: ";
    isBorrowable(book3); 
    //借阅书籍1
    borrowBook(book1);
    //借阅书籍2
    borrowBook(book2);
    //显示书籍1、书籍2的借阅状态
    std::cout << "书籍1借阅状态: " ;
    isBorrowable(book1);
    std::cout << "书籍2借阅状态: " ;
    isBorrowable(book2);
    //归还书籍1
    returnBook(book1);
    //归还书籍2
    returnBook(book2);
    //显示书籍1、书籍2的借阅状态
    std::cout << "书籍1借阅状态: " ;
     isBorrowable(book1) ;
    std::cout << "书籍2借阅状态: " ;
    isBorrowable(book2) ;

    // 输出当前书籍数量
    std::cout << "当前书籍总数: " << Book::getBookCount() << std::endl;
    // 销毁书籍1
    book1.~Book();
    std::cout << "销毁书籍1成功" << std::endl;
    //输出当前书籍数量
    std::cout << "当前书籍总数: " << Book::getBookCount() << std::endl;

    return 0;
}
