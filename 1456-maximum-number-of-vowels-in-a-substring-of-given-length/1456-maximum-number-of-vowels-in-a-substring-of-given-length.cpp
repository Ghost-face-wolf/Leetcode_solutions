class Solution {
private:
    inline bool isvowel(char c){
        return c=='a'|| c=='e'|| c=='i'|| c=='o'|| c=='u';
    }
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int vcount=0;
        
        for(int i=0;i<k;++i){
            if(isvowel(s[i])){
                vcount++;
            }
        }
        int maxvowel=vcount;
        if(maxvowel==k) return k;
        for(int i=k;i<n;++i){
            if(isvowel(s[i])){
                vcount++;
            }
            if(isvowel(s[i-k])){
                vcount--;
            }
            maxvowel=max(maxvowel, vcount);
            if(maxvowel==k) return k;
        }
        return maxvowel;
    }
};