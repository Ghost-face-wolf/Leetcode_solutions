class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitcount(31,0);
        for(int x:nums){
            for(int i=0;i<30;++i){
                if((x>>i)&1){
                    bitcount[i]++;
                }
            }
        }
        long long totalsum=0;
        long long MOD=1e9+7;
        for(int step=0;step<k;++step){
            long long currentnum=0;
            for(int i=30;i>=0;--i){
                if(bitcount[i]>0){
                    currentnum|=(1LL<<i);
                    bitcount[i]--;
                }
            }
            totalsum=(totalsum+(currentnum*currentnum)%MOD)%MOD;
        }
        return totalsum;
    }
};