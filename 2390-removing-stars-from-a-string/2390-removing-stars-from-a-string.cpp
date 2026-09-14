class Solution {
public:
    string removeStars(string s) {
        int traversePtr=0;
        int writePtr=0;
        for(;traversePtr<s.size();traversePtr++){
            if(s[traversePtr]=='*'){
                writePtr--;
            }
            else{
                s[writePtr]=s[traversePtr];
                writePtr++;
            }
        }
        return s.substr(0,writePtr);
    }
};