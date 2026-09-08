class Solution {
public:
    int countCommas(int n) {
        int tcomma=0;
     if(n<1000) return 0;
     
        if(n>=1000) {
            tcomma++;
            n-=999;
            
        }
      
     return n;
    }
};