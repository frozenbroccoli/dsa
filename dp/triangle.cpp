#include <algorithm>
#include <vector>
#include <limits>


int minimum_total(std::vector<std::vector<int>>& triangle) {
    int h = triangle.size();
    std::vector<std::vector<int>> dp(h);
    std::copy(triangle.begin(), triangle.end(), dp.begin());

    for (int i = 1; i < h; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i][0];
        dp[i][dp[i].size() - 1] = dp[i - 1][dp[i - 1].size() - 1] + dp[i][dp[i].size() - 1];
        for (int j = 1; j < i; j++) {
            dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j]) + dp[i][j];
        }
    }

    int result = std::numeric_limits<int>::max();
    for (int j = 0; j < h; j++) {
        result = std::min(result, dp[h - 1][j]);
    }
    return result;
}


