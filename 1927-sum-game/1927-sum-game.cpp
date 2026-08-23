class Solution {
public:
    bool sumGame(string s) {
        int n=s.length();
        int leftsum=0, rightsum=0;
        int leftq=0,rightq=0;
        for(int i=0;i<n/2;++i){
            if(s[i] =='?'){
                leftq++;
            }else{
                leftsum+=s[i] -'0';
            }
        }
        for(int i=n/2;i<n;++i){
            if(s[i] =='?'){
                rightq++;
            }else{
                rightsum+=s[i] - '0';
            }
        }
        int sumdiff= leftsum -rightsum;
        int qdiff= rightq-leftq;
        if(qdiff%2 != 0 || sumdiff*2 != qdiff*9){
            return true;
        }
        return false;
    }
};