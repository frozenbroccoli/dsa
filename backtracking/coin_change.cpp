#include <vector>
#include <algorithm>
#include <functional>
#include <climits>


bool dfs(std::vector<int>& sorted_coins, int& amount, int start, int current_amount, int& result) {
    if (current_amount == amount) return true;
    if (current_amount > amount) return false;
    if (start >= sorted_coins.size()) return false;

    for (int greedy_amount, index = start; index < sorted_coins.size(); index++) {
        for (int multiplier = (amount - current_amount) / sorted_coins[index]; multiplier >= 0; multiplier--) {
            greedy_amount = current_amount + multiplier * sorted_coins[index];
            result += multiplier;
            if (dfs(sorted_coins, amount, index + 1, greedy_amount, result)) return true;
            result -= multiplier;
        }
    }

    return false;
}


int coin_change(std::vector<int>& coins, int amount) {
    std::sort(coins.begin(), coins.end(), std::greater<>());
    int result {0};
    if (dfs(coins, amount, 0, 0, result)) return result;
    return -1;
}

