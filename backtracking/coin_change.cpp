#include <algorithm>
#include <vector>


void dfs(
    const std::vector<int>& coins, 
    const int& amount, 
    int& num_coins, 
    int& sum, 
    int& result, 
    int start
) {
    if (sum == amount) {
        result = (result == -1) ? num_coins : std::min(num_coins, result);
        return;
    } else if (sum > amount) return;

    for (int i = start; i < coins.size(); i++) {
        sum += coins[i];
        num_coins += 1;
        dfs(coins, amount, num_coins, sum, result, i);
        sum -= coins[i];
        num_coins -= 1;
    }
}


int coin_change(std::vector<int>& coins, int amount) {
    int sum {0}, num_coins {0};
    int result {-1};
    dfs(coins, amount, num_coins, sum, result, 0);
    return result;
}

