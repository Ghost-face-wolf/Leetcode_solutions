#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        int zero = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }

        auto check = [&](int step) -> bool {
            for (int i = 1; i < n; ++i) {
                int prev = (zero + (i - 1) * step + n) % n;
                int curr = (zero + i * step + n) % n;
                if (nums[prev] > nums[curr]) {
                    return false;
                }
            }
            return true;
        };

        int ans = INT_MAX;

        // Case 1: Increasing to the right (step = 1)
        if (check(1)) {
            ans = std::min(ans, zero);
            ans = std::min(ans, n - zero + 2);
        }

        // Case 2: Increasing to the left (step = -1)
        if (check(-1)) {
            ans = std::min(ans, zero + 2);
            ans = std::min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};