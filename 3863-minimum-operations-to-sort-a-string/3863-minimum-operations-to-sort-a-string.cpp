#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.size();
        
        // Case 1: Already sorted
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        // Case 2: Length 2 cannot be sorted with proper substrings
        if (n == 2) {
            return -1;
        }
        
        // Find the first occurrence of the minimum character 
        // and the last occurrence of the maximum character
        int min_c = 0, max_c = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] < s[min_c]) min_c = i;
            if (s[i] >= s[max_c]) max_c = i;
        }
        
        // Case 3: Min is at the beginning or Max is at the end
        if (min_c == 0 || max_c == n - 1) {
            return 1;
        }
        
        // Case 4: Min is at the very end and Max is at the very beginning
        if (min_c == n - 1 && max_c == 0) {
            return 3;
        }
        
        // Case 5: Everything else takes 2 operations
        return 2;
    }
};