#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        // Square each element
        int n = nums.size();
        std::vector<long long> squares(n);
        for (int i = 0; i < n; ++i) {
            squares[i] = 1LL * nums[i] * nums[i];
        }
        
        // Sort the squared values
        std::sort(squares.begin(), squares.end());
        
        long long ans = 0;
        int m = n / 2;
        
        // Subtract the smaller half and add the larger half
        for (int i = 0; i < m; ++i) {
            ans -= squares[i];
        }
        for (int i = m; i < n; ++i) {
            ans += squares[i];
        }
        
        return ans;
    }
};