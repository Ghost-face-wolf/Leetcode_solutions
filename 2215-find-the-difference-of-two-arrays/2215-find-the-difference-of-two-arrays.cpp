class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> set2(nums2.begin(),nums2.end());
        vector<int> distinct1;
        vector<int> distinct2;
        for(int num: set1){
            if(set2.find(num)==set2.end()){
                distinct1.push_back(num);
            }
        }
        for(int num: set2){
            if(set1.find(num)==set1.end()){
                distinct2.push_back(num);
            }
        }
        return {distinct1, distinct2};
    }
};