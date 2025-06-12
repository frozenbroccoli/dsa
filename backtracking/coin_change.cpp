#include <algorithm>
#include <vector>


bool dfs(
    const std::vector<int>& coins, 
    const int& amount, 
    std::vector<int>& memo,
    int& num_coins, 
    int& sum, 
    int& result, 
    int start
) {
    if (sum == amount) {
        result = (result == -1) ? num_coins : std::min(num_coins, result);
        return true;
    } else if (sum > amount) return false;

    if (memo[sum] != -1 && memo[sum] <= num_coins) {
        return false;
    }

    memo[sum] = num_coins;

    bool ret {false};
    for (int i = start; i < coins.size(); i++) {
        sum += coins[i];
        num_coins += 1;
        if (dfs(coins, amount, memo, num_coins, sum, result, i)) {
            ret = true;
        }
        sum -= coins[i];
        num_coins -= 1;
    }
    return ret;
}


int coin_change(std::vector<int>& coins, int amount) {
    int sum {0}, num_coins {0};
    std::vector<int> memo(amount, -1);
    int result {-1};
    dfs(coins, amount, memo, num_coins, sum, result, 0);
    return result;
}

