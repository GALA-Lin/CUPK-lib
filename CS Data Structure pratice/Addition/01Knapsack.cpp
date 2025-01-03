#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

int knapsack(int W, const std::vector<Item>& items) {
    int n = items.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (items[i-1].weight <= w)
                dp[i][w] = std::max(dp[i-1][w], dp[i-1][w - items[i-1].weight] + items[i-1].value);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int W, n;

    // 输入背包容量和物品数量
    std::cout << "请输入背包的容量: ";
    std::cin >> W;
    std::cout << "请输入物品的数量: ";
    std::cin >> n;

    std::vector<Item> items(n);

    // 输入每个物品的重量和价值
    for (int i = 0; i < n; ++i) {
        std::cout << "请输入物品 " << i + 1 << " 的重量和价值: ";
        std::cin >> items[i].weight >> items[i].value;
    }

    int max_value = knapsack(W, items);
    std::cout << "背包可以包含的最大价值是: " << max_value << std::endl;

    return 0;
}
