class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       ;
        int n=nums.size();
        int write=0;
        for(int read=0;read<n;++read){
            if(nums[read]!= 0){
                swap(nums[write],nums[read]);
                write++;
            }
        }

    }
};