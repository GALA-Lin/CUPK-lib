#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
    int quantity; // 可用的数量
};

int multipleKnapsack(int W, const std::vector<Item>& items) {
    int n = items.size();
    std::vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; ++i) {
        if (items[i].quantity * items[i].weight >= W) {
            for (int w = items[i].weight; w <= W; ++w) {
                dp[w] = std::max(dp[w], dp[w - items[i].weight] + items[i].value);
            }
        } else {
            for (int k = 1; k <= items[i].quantity; ++k) {
                for (int w = W; w >= k * items[i].weight; --w) {
                    dp[w] = std::max(dp[w], dp[w - k * items[i].weight] + k * items[i].value);
                }
            }
        }
    }

    return dp[W];
}

int main() {
    int W, n;

    // 输入背包容量和物品数量
    std::cout << "请输入背包的容量: ";
    std::cin >> W;
    std::cout << "请输入物品的数量: ";
    std::cin >> n;

    std::vector<Item> items(n);

    // 输入每个物品的重量, 价值和数量
    for (int i = 0; i < n; ++i) {
        std::cout << "请输入物品 " << i + 1 << " 的重量, 价值和数量: ";
        std::cin >> items[i].weight >> items[i].value >> items[i].quantity;
    }

    int max_value = multipleKnapsack(W, items);
    std::cout << "多重背包问题中，背包可以包含的最大价值是: " << max_value << std::endl;

    return 0;
}
