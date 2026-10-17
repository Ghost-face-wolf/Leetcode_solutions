class Solution {
private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Store pairs of {digit_sum, original_value} along with their original indices
        vector<pair<pair<int, int>, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {{getDigitSum(nums[i]), nums[i]}, i};
        }
        
        // Sort based on digit sum first, then by value
        sort(arr.begin(), arr.end());
        
        vector<bool> visited(n, false);
        int cycles = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] || arr[i].second == i) {
                continue;
            }
            
            // Traverse the cycle
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycleSize++;
            }
            
            if (cycleSize > 1) {
                cycles += (cycleSize - 1);
            }
        }
        
        return cycles;
    }
};