class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int num: arr){
            freq[num]++;
        }
        unordered_set<int>unique_freqs;
        for(const auto &entry: freq){
            if(!unique_freqs.insert(entry.second).second) return false;
        }
        return true;
    }
};