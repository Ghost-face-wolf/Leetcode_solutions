class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentalt=0;
        int maxalt=0;
        for(int netgain: gain){
            currentalt+=netgain;
            maxalt=max(maxalt,currentalt);
        }
        return maxalt;
    }
};