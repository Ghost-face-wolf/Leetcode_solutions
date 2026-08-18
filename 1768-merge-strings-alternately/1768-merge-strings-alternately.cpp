class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       string merg="";
       int n=max(word1.length(),word2.length());
       for(int i=0;i<n;++i){
        if(i<word1.length()) merg+=word1[i];
        if(i<word2.length()) merg+=word2[i];
       }
       return merg;
    }
};