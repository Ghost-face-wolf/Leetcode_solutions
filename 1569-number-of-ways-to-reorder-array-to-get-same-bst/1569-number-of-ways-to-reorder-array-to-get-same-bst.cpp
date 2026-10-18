#include <vector>

class Solution {
private:
    long long MOD = 1e9 + 7;
    std::vector<std::vector<long long>> table;

    long long dfs(const std::vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        std::vector<int> left, right;
        int root = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long left_ways = dfs(left);
        long long right_ways = dfs(right);

        int m = left.size();
        int n = right.size();

        // Ways to interleave left and right subtree sequences: C(m + n, m)
        long long ways = table[m + n][m];
        
        ways = (ways * left_ways) % MOD;
        ways = (ways * right_ways) % MOD;

        return ways;
    }

public:
    int numOfWays(std::vector<int>& nums) {
        int n = nums.size();
        
        // Precomputing Pascal's Triangle for Combinations: C(n, k)
        table.resize(n + 1, std::vector<long long>(n + 1, 1));
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }

        return (dfs(nums) - 1 + MOD) % MOD;
    }
};