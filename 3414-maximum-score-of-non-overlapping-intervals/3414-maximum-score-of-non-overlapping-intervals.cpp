struct Interval{
    int start;
    int end;
    long long weight;
    int id;
};
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<Interval> arr(n);
        for(int i=0; i<n;++i){
            arr[i]={intervals[i][0],intervals[i][1],intervals[i][2],i};
        }
        sort(arr.begin(),arr.end(),[](const Interval& a, const Interval& b){
            if(a.end != b.end) return a.end <b.end;
            return a.start < b.start;
        });
        vector<int> prev(n,-1);
        for(int i=0;i<n;++i){
            int low =0, high=i-1,ans=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(arr[mid].end< arr[i].start){
                    ans=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            prev[i]=ans;
        }
        using State =pair<long long,vector<int>>;
        vector<vector<State>> dp(n+1, vector<State>(5,{0,{}}));
        auto isBetter =[](const State& a, const State& b){
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        };
        for(int i=1;i<=n;++i){
            int curr_id=arr[i-1].id;
            long long weight=arr[i-1].weight;
            int p=prev[i-1];
            for(int k=1; k<=4; ++k){
                State best =dp[i-1][k];
                State take={weight, {curr_id}};
                if(p !=-1){
                    State prev_state = dp[p+1][k-1];
                    take.first +=prev_state.first;
                    take.second.insert(take.second.begin(),prev_state.second.begin(),prev_state.second.end());
                }
                sort(take.second.begin(),take.second.end());
                if(isBetter(take,best)){
                    best =take;
                }
                dp[i][k]=best;
            }
        }
        State result ={0,{}};
        for(int k=1;k<=4;++k){
            if(isBetter(dp[n][k],result)){
                result=dp[n][k];
            }
        }
        return result.second;
    }
};