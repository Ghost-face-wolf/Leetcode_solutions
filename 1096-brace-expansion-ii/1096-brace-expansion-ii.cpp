#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> braceExpansionII(std::string expression) {
        std::set<std::string> resultSet = parse(expression, 0, expression.length() - 1);
        return std::vector<std::string>(resultSet.begin(), resultSet.end());
    }

private:
    std::set<std::string> parse(const std::string& expr, int start, int end) {
        std::set<std::string> res;
        std::set<std::string> curr = {""};

        int i = start;
        while (i <= end) {
            if (expr[i] == '{') {
                // Find the matching closing brace '}'
                int braceCount = 1;
                int j = i + 1;
                while (j <= end && braceCount > 0) {
                    if (expr[j] == '{') braceCount++;
                    if (expr[j] == '}') braceCount--;
                    j++;
                }
                
                // Recursively evaluate the nested expression
                std::set<std::string> inner = parse(expr, i + 1, j - 2);
                
                // Cartesian product: curr = curr * inner
                curr = multiplySets(curr, inner);
                i = j;
            } 
            else if (expr[i] == ',') {
                // Union current set into overall result set, then reset curr
                res.insert(curr.begin(), curr.end());
                curr = {""};
                i++;
            } 
            else {
                // Read continuous lowercase letters
                int j = i;
                while (j <= end && std::isalpha(expr[j])) {
                    j++;
                }
                std::string s = expr.substr(i, j - i);
                std::set<std::string> inner = {s};
                
                // Cartesian product: curr = curr * s
                curr = multiplySets(curr, inner);
                i = j;
            }
        }

        // Insert whatever is left in curr
        res.insert(curr.begin(), curr.end());
        return res;
    }

    std::set<std::string> multiplySets(const std::set<std::string>& set1, const std::set<std::string>& set2) {
        std::set<std::string> res;
        for (const std::string& s1 : set1) {
            for (const std::string& s2 : set2) {
                res.insert(s1 + s2);
            }
        }
        return res;
    }
};