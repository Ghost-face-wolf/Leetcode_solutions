#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        
        // Find all divisors of n
        std::vector<int> divisors;
        for (int d = 1; d * d <= n; ++d) {
            if (n % d == 0) {
                divisors.push_back(d);
                if (d * d != n) {
                    divisors.push_back(n / d);
                }
            }
        }

        auto isSortable = [&](int k) -> bool {
            int prevMax = -1;

            for (int start = 0; start < n; start += k) {
                int end = start + k;
                int currentMin = nums[start];
                int currentMax = nums[start];
                
                // Count interior drops in this block
                int drops = 0;
                for (int i = start; i < end; ++i) {
                    currentMin = std::min(currentMin, nums[i]);
                    currentMax = std::max(currentMax, nums[i]);
                    
                    if (i + 1 < end && nums[i] > nums[i + 1]) {
                        drops++;
                    }
                }

                // Check circular drop between end and start of block
                if (nums[end - 1] > nums[start]) {
                    drops++;
                }

                // A circular shift can sort the block iff total drops <= 1
                if (drops > 1) {
                    return false;
                }

                // Ensure non-decreasing transition across adjacent blocks
                if (prevMax > currentMin) {
                    return false;
                }

                prevMax = currentMax;
            }

            return true;
        };

        long long totalSum = 0;
        for (int k : divisors) {
            if (isSortable(k)) {
                totalSum += k;
            }
        }

        return totalSum;
    }
};