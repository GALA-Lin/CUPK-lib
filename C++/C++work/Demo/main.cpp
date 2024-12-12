#include <iostream>
#include "menu.h"
#include "operations.h"

int main() {
    std::cout << "\t   欢迎使用记账小程序" << std::endl;

    FinanceManager financeManager; // 创建 FinanceManager 实例
    Menu menu(financeManager); // 将 FinanceManager 实例传递给 Menu

    while (true) {
        menu.showMainMenu(); // 调用 Menu 的主菜单方法
    }

    return 0;
}
