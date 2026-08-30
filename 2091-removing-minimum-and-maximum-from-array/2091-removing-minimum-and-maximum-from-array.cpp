#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumDeletions(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int min_idx = 0;
        int max_idx = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[min_idx]) {
                min_idx = i;
            }
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }

        int left = std::min(min_idx, max_idx);
        int right = std::max(min_idx, max_idx);

        // Option 1: Remove both from the front
        int option1 = right + 1;

        // Option 2: Remove both from the back
        int option2 = n - left;

        // Option 3: Remove left from front, right from back
        int option3 = (left + 1) + (n - right);

        return std::min({option1, option2, option3});
    }
};