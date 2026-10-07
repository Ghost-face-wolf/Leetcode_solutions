#include <string>
#include <vector>
#include <algorithm>

class Solution {
private:
    void removeHelper(std::string s, std::vector<std::string>& result, 
                      int last_i, int last_j, const std::vector<char>& parens) {
        int balance = 0;

        for (int i = last_i; i < s.length(); ++i) {
            if (s[i] == parens[0]) balance++;
            if (s[i] == parens[1]) balance--;

            // Balanced or still positive; keep going
            if (balance >= 0) continue;

            // balance < 0: Excess closing character found at index i
            for (int j = last_j; j <= i; ++j) {
                // Remove s[j] if it matches closing character and avoids duplicates
                if (s[j] == parens[1] && (j == last_j || s[j - 1] != parens[1])) {
                    // Recursively process suffix
                    removeHelper(s.substr(0, j) + s.substr(j + 1), result, i, j, parens);
                }
            }
            return; // Stop exploring current invalid path
        }

        // If left-to-right pass completed, reverse and scan for unmatched opening brackets
        std::string reversedStr = s;
        std::reverse(reversedStr.begin(), reversedStr.end());

        if (parens[0] == '(') { // Finished left-to-right, start right-to-left
            removeHelper(reversedStr, result, 0, 0, {')', '('});
        } else { // Finished both passes; append valid result
            result.push_back(reversedStr);
        }
    }

public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> result;
        removeHelper(s, result, 0, 0, {'(', ')'});
        return result;
    }
};