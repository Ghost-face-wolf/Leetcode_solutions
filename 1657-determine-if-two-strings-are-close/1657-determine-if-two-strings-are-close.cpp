class Solution {
public:
    bool closeStrings(string word1, string word2) {
       int n=word1.length();
       int m=word2.length();
       if(m!=n) return false;
       
       vector<int> count(26,0);
       vector<int> count2(26,0);
       for(char c: word1){
        count[c-'a']++;
       }
       
       for(char c: word2){
        count2[c-'a']++;
       }
       for(int i=0;i<26;++i){
        if((count[i]==0 && count2[i]!=0)||(count[i]!=0 && count2[i]==0)) return false;
       }
       sort(count.begin(),count.end());
       sort(count2.begin(),count2.end());
       return count==count2;
    }
};