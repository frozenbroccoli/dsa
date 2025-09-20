#include <iostream>
#include <algorithm>
#include <vector>


int min_path_sum(std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size()));
    std::copy(grid.begin(), grid.end(), dp.begin());

    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            if (i == 0 && j != 0) {
                dp[i][j] = dp[i][j - 1] + dp[i][j];
            } else if (i != 0 && j == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j];
            } else if (i != 0 && j != 0) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + dp[i][j];
            }
        }
    }
    return dp[dp.size() - 1][dp[0].size() - 1];
}


int main() {
    std::vector<std::vector<int>> grid {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int result = min_path_sum(grid);
    std::cout << "Result: " << result << std::endl;
}

