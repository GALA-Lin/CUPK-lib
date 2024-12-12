#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "operations.h"

class Menu {
public:
    Menu(FinanceManager& manager) : financeManager(manager) {}

    void showMainMenu();
    void showAccountingMenu();
    void showQueryMenu();

private:
    FinanceManager& financeManager; // 引用 FinanceManager 对象
};

void Menu::showMainMenu() {
    int choice;
    std::cout << "==================== 主菜单 ====================\n";
    std::cout << "|----------------1. 记账-----------------------|\n";
    std::cout << "|----------------2. 查询-----------------------|\n";
    std::cout << "|----------------3. 保存-----------------------|\n";
    std::cout << "|----------------4. 退出-----------------------|\n";
    std::cout << "================================================\n";
    std::cout << "请输入选择 (1-4): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            showAccountingMenu();
            break;
        case 2:
            showQueryMenu();
            break;
        case 3:
            financeManager.saveToFile("D:\\C++work\\Demo\\data.txt"); // 通过 FinanceManager 保存文件
            break; 
        case 4:
            char confirm;
            std::cout << "确认退出吗？(Y/N): ";
            std::cin >> confirm;
            if (confirm == 'Y' || confirm == 'y') {
                exit(0);
            }
            break;
        default:
            std::cout << "无效选择，请重新输入。\n";
    }
}

void Menu::showAccountingMenu() {
    int choice;
    std::cout << "==================== 记账菜单 ====================\n";
    std::cout << "|-----------------1. 收入------------------------|\n";
    std::cout << "|-----------------2. 支出------------------------|\n";
    std::cout << "|-----------------3. 返回------------------------|\n";
    std::cout << "=================================================\n";
    std::cout << "请输入选择 (1-3): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            financeManager.recordIncome(); // 调用 FinanceManager 中的方法
            break;
        case 2:
            financeManager.recordExpense(); // 调用 FinanceManager 中的方法
            break;
        case 3:
            return;
        default:
            std::cout << "无效选择，请重新输入。\n";
    }
}

void Menu::showQueryMenu() {
    int choice;
    std::cout << "==================== 查询菜单 ====================\n";
    std::cout << "|------------------1. 统计所有--------------------|\n";
    std::cout << "|------------------2. 统计收入--------------------|\n";
    std::cout << "|------------------3. 统计支出--------------------|\n";
    std::cout << "|------------------4. 返回菜单--------------------|\n";
    std::cout << "=================================================\n";
    std::cout << "请输入选择 (1-4): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            financeManager.queryAll(); // 调用 FinanceManager 中的方法
            break;
        case 2:
            financeManager.queryIncome(); // 调用 FinanceManager 中的方法
            break;
        case 3:
            financeManager.queryExpense(); // 调用 FinanceManager 中的方法
            break;
        case 4:
            return;
        default:
            std::cout << "无效选择，请重新输入。\n";
    }
}

#endif
