
class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long p = 1000; // First threshold (10^3)

        while (p <= n) {
            totalCommas += (n - p + 1);
            
            // Prevent long long overflow when multiplying by 1000
            if (p > LLONG_MAX / 1000) {
                break;
            }
            p *= 1000;
        }

        return totalCommas;
    }
};