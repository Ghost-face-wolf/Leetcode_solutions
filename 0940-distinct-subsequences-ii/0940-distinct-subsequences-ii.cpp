#include <string>
#include <numeric>

class Solution {
public:
    int distinctSubseqII(std::string s) {
        constexpr int MOD = 1e9 + 7;
        // last[i] stores the total distinct subsequences ending with character ('a' + i)
        long long last[26] = {0};

        for (char c : s) {
            int idx = c - 'a';
            long long current_total = 0;
            
            // Sum up all existing subsequences formed so far
            for (int i = 0; i < 26; ++i) {
                current_total = (current_total + last[i]) % MOD;
            }
            
            // New count for character c includes appending c to all existing subsequences + 1 (for single character 'c')
            last[idx] = (current_total + 1) % MOD;
        }

        // Sum up all subsequences ending with any character
        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + last[i]) % MOD;
        }

        return result;
    }
};