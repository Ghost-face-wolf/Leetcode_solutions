class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> numset(nums.begin(),nums.end());
        int multiple=k;
        while(numset.count(multiple)){
            multiple+=k;
        }
        return multiple;
    }
};