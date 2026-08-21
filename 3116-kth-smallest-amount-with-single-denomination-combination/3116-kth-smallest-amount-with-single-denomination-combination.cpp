class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n=coins.size();
        long long lo =*min_element(coins.begin(),coins.end()) *1LL;
        long long hi= *max_element(coins.begin(),coins.end()) *1LL *k;
        vector<vector<long long>> set(n+1);
        function<void(long long, int, int)> setcreation =[&](long long val,int setnumber, int idx){
            val=lcm(val,(long long)coins[idx]);
            if(val > hi) return;
            set[setnumber].push_back(val);
            for(int i=idx+1;i<n;++i)
                setcreation(val,setnumber+1,i);
            return;
        };
        for(int i=0;i<n;++i)
            setcreation(1,1,i);
        auto getrank=[&](long long value) -> long long{
            long long rank=0;
            for(int i=1;i<=n;++i){
                for(int j=0;j<set[i].size();++j){
                    if(i%2 != 0)rank+=value/set[i][j];
                    else rank -=value/set[i][j];
                }
            }
            return rank;
        };
        while(lo<hi){
            long long mid=lo+(hi-lo)/2;
            long long rank=getrank(mid);
            if(rank>=k) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};