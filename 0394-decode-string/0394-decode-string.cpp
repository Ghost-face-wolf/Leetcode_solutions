class Solution {
public:
    string decodeString(string s) {
        int i=0; 
        return decode(s,i);
    }
    string decode(const string& s, int& i){
        string result="";
        int num=0;
        while(i<s.size()){
            char c=s[i];
            if(isdigit(c)){
                num=num*10+(c-'0');
                i++;
            }else if(c=='['){
                i++;
                string inner=decode(s,i);
                for(int k=0;k<num;k++) result +=inner;
                num=0;
            } else if(c==']'){
                i++;
                return result;
            }else{
                result+=c;
                i++;
            }
        }
        return result;
    }
};