#include <iostream>
#include <vector>


int unique_paths(int m, int n) {
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 1));

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    int result = unique_paths(5, 3);
    std::cout << "Result: " << result << std::endl;
}

