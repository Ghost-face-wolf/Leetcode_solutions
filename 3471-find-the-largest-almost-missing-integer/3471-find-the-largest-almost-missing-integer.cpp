class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int> totalfreq;
        for(int num : nums){
            totalfreq[num]++;
        }
        if(k==n){
            int maxval=-1;
            for(int num:nums){
                maxval=max(maxval,num);
            }
            return maxval;
        }
        if(k==1){
            int maxval=-1;
            for(auto& [num,count]: totalfreq){
                if(count==1){
                    maxval= max(maxval, num);
                }
            }
            return maxval;
        }
        int ans=-1;
        if(totalfreq[nums[0]]==1){
            ans=max(ans, nums[0]);
        }
        if(totalfreq[nums[n-1]]==1){
            ans=max(ans,nums[n-1]);
        }
        return ans;
    }
};