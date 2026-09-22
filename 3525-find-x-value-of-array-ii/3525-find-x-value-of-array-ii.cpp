struct Node{
    int remain[5]={0};
    int prod=1;
};
class segmenttree{
public:
    int n,k;
    vector<Node>tree;
    segmenttree(const vector<int>&nums,int k): n(nums.size()),k(k),tree(4*n){
        build(nums,0,0,n-1);
    }
    void update(int idx, int val){
        update(0,0,n-1,idx,val);
    }
    Node query(int i,int j) const{
        return query(0,0,n-1,i,j);
    }
private:
    Node merge(const Node& left, const Node& right)const{
        Node res;
        res.prod=(left.prod*right.prod)%k;
        for(int i=0;i<k;++i){
            res.remain[i]=left.remain[i];
        }
        for(int i=0;i<k;++i){
            res.remain[(i*left.prod)%k]+=right.remain[i];
        }
        return res;
    }
    void build(const vector<int>& nums, int cur,int left,int right){
        if(left==right){
            tree[cur].remain[nums[left]%k]=1;
            tree[cur].prod=nums[left]%k;
            return;
        }
        int mid=left+(right-left)/2;
        build(nums,2*cur+1,left,mid);
        build(nums,2*cur+2,mid+1,right);
        tree[cur]=merge(tree[2*cur+1],tree[2*cur+2]);
    }
    void update(int cur, int lo, int hi, int idx, int val){
        if(lo==hi){
            for(int j=0;j<k;++j){
                tree[cur].remain[j]=0;
            }
            tree[cur].remain[val%k]=1;
            tree[cur].prod=val%k;
            return;
        }
        int mid=lo+(hi-lo)/2;
        if(idx<=mid){
            update(2*cur+1,lo,mid,idx,val);
        } else{
            update(2*cur+2,mid+1,hi,idx,val);
        }
        tree[cur]=merge(tree[2*cur+1],tree[2*cur+2]);
    }
    Node query(int cur, int lo, int hi, int i,int j)const{
        if(i<=lo&&hi<=j){
            return tree[cur];
        }
        int mid=lo+(hi-lo)/2;
        if(j<=mid) return query(2*cur+1,lo,mid,i,j);
        if(i>mid) return query(2*cur+2,mid+1,hi,i,j);
        Node leftres=query(2*cur+1,lo,mid,i,j);
        Node rightres=query(2*cur+2,mid+1,hi,i,j);
        return merge(leftres,rightres);
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();
        segmenttree tree(nums,k);
        vector<int> ans;
        ans.reserve(queries.size());
        for(const auto& q:queries){
            int index=q[0];
            int value=q[1];
            int start=q[2];
            int x=q[3];
            tree.update(index,value);
            Node res=tree.query(start, n-1);
            ans.push_back(res.remain[x]);
        }
        return ans;
    }
};