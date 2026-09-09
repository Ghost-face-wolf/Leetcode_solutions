class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int score=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<k;++i){
            score+=nums[n-1];
            nums[n-1]+=1;
        }
        return score;
    }
};