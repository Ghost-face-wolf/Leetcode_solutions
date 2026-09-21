class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k,0);
        vector<long long> dp(k,0);
        for(int num: nums){
            vector<long long> nextdp(k,0);
            int curr_rem=num%k;
            nextdp[curr_rem]++;
            for(int r=0;r<k;++r){
                if(dp[r]>0){
                    int new_rem=(1LL*r*curr_rem)%k;
                    nextdp[new_rem]+=dp[r];
                }
            }
            for(int r=0;r<k;++r){
                result[r]+=nextdp[r];

            }
            dp=move(nextdp);
        }
        return result;
    }
};