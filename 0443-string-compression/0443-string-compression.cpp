class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int read=0;
        int write=0;
        while(read<n){
            char currentchar=chars[read];
            int count=0;
            while(read<n && chars[read]==currentchar){
                read++;
                count++;
            }
            chars[write++]=currentchar;
            if(count>1){
                string str= to_string(count);
                for(char digit: str){
                    chars[write++]=digit;
                }
            }

        }
        return write;
    }
};