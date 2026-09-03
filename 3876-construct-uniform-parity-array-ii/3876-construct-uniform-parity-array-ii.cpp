class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd=INT_MAX;
        for(int& i:nums1){
            if(i & 1){
                minodd=min(minodd,i);
            }
        }
        auto helper=[&](int parity){
            for(int& i: nums1){
                if((i&1)!= parity && i<=minodd){
                    return false;
                }
            }
            return true;
        };
        return helper(0) || helper(1);
    }
};