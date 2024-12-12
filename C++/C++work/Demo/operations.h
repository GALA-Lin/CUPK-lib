#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <limits>

class FinanceManager {
public:
    void recordIncome();
    void recordExpense();
    void queryAll() const;
    void queryIncome() const;
    void queryExpense() const;
    void saveToFile(const std::string& filename) const;

private:
    struct Entry {
        std::string type;
        float amount;
        std::string note;
    };

    std::vector<Entry> entries;

    void recordEntry(const std::string& type);
};

void FinanceManager::recordEntry(const std::string& type) {
    Entry entry;
    entry.type = type;
    std::cout << "请输入" << type << "金额: ";
    
    // 错误处理，确保用户输入的金额有效
    while (!(std::cin >> entry.amount) || entry.amount < 0) {
        std::cout << "输入无效，请输入一个有效的金额: ";
        std::cin.clear(); // 清除错误状态
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲
    }
    
    std::cin.ignore(); // 清除输入缓冲
    std::cout << "请输入备注: ";
    std::getline(std::cin, entry.note);
    
    entries.push_back(entry);
    std::cout << "完成记账。\n";
}

void FinanceManager::recordIncome() {
    recordEntry("收入");
}

void FinanceManager::recordExpense() {
    recordEntry("支出");
}

void FinanceManager::queryAll() const {
    float totalIncome = 0, totalExpense = 0;
    std::cout << "所有账目:\n";
    for (const auto& entry : entries) {
        std::cout << entry.type << " | " << entry.amount <<  "\n";
        if (entry.type == "收入") {
            totalIncome += entry.amount;
        } else {
            totalExpense += entry.amount;
        }
    }
    std::cout << "总收入: " << totalIncome << "\n";
    std::cout << "总支出: " << totalExpense << "\n";
    std::cout << "净收入: " << (totalIncome - totalExpense) << "\n";
}

void FinanceManager::queryIncome() const {
    float totalIncome = 0;
    std::cout << "所有收入:\n";
    for (const auto& entry : entries) {
        if (entry.type == "收入") {
            std::cout << entry.amount  << "\n";
            totalIncome += entry.amount;
        }
    }
    std::cout << "总收入: " << totalIncome << "\n";
}

void FinanceManager::queryExpense() const {
    float totalExpense = 0;
    std::cout << "所有支出:\n";
    for (const auto& entry : entries) {
        if (entry.type == "支出") {
            std::cout << entry.amount  << "\n";
            totalExpense += entry.amount;
        }
    }
    std::cout << "总支出: " << totalExpense << "\n";
}

void FinanceManager::saveToFile(const std::string& filename) const {
    std::ofstream ofs(filename, std::ios::app); // 使用 std::ios::app 模式，在文件末尾追加内容
    if (!ofs.is_open()) {
        std::cerr << "无法打开文件 " << filename << " 进行写入。\n";
        return;
    }
    ofs << "类型 金额 备注\n";
    for (const auto& entry : entries) {
        ofs << entry.type << " " << entry.amount << " " << entry.note << "\n";
    }
    ofs.close();
    std::cout << "保存成功。\n";
}

#endif
