class Solution {
public:
    int maxDepth(string s) {
        int left=0,right=0;
        int count=0;
        for(char c:s){
            if(c=='('){
                left++;
                count=max(count,left-right);
            } else if(c==')'){
                right++;
                count=max(count,left-right);
            }
        }
        return count;
    }
};