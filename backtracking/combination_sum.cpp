#include <vector>
#include <algorithm>
#include <numeric>


void dfs(
    std::vector<int>& candidates, 
    int target, 
    int start, 
    std::vector<int>& tuple, 
    std::vector<std::vector<int>>& result
) {
    int sum = std::accumulate(tuple.begin(), tuple.end(), 0);

    if (sum == target) {
        result.emplace_back(tuple);
        return;
    }

    if (sum > target) return;

    for (int i = start; i < candidates.size(); i++) {
        tuple.emplace_back(candidates[i]);
        dfs(candidates, target, i, tuple, result);
        tuple.pop_back();
    }
}


std::vector<std::vector<int>> combination_sum(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<int> tuple {};
    std::vector<std::vector<int>> result {};
    dfs(candidates, target, 0, tuple, result);
    return result;
}

