class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastseen(256,0);
        int left=0;
        int maxlength=0;
        for(int right=0;right<s.length();++right){
            unsigned char currentchar = static_cast<unsigned char>(s[right]);
            if(lastseen[currentchar]>left){
                left=lastseen[currentchar];
            }
            lastseen[currentchar]=right+1;
            maxlength=max(maxlength,right-left+1);

        }
        return maxlength;

    }
};