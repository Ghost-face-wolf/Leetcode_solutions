class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();
        int startx=0,starty=0;
        unordered_map<int,int> littermap;
        int littercount=0;
        for(int r=0;r<m;++r){
            for(int c=0;c<n;++c){
                if(classroom[r][c]=='S'){
                    startx=r;
                    starty=c;
                }
                else if(classroom[r][c]=='L'){
                    littermap[r*n+c]=littercount++;
                }
            }
        }
        if(littercount==0) return 0;
        int targetmask=(1<<littercount)-1;
        int startmask=0;
        if(littermap.count(startx*n+starty)){
            startmask|=(1<<littermap[startx*n+starty]);
        }
        if(startmask==targetmask) return 0;
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy+1, vector<bool>(1<<littercount, false)
                )
            )
        );
        queue<tuple<int,int,int,int,int>> q;
        q.push({startx,starty,energy, startmask,0});
        visited[startx][starty][energy][startmask]=true;
        int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto[r,c,curE,mask,moves]=q.front();
            q.pop();
            if(curE==0)continue;
            for(auto& dir:dirs){
                int nr=r+dir[0];
                int nc=c+dir[1];
                if(nr>=0&& nr<m && nc>=0 && nc<n &&classroom[nr][nc] !='X'){
                    char cell=classroom[nr][nc];
                    int nexte=(cell=='R') ? energy :curE-1;
                    int nextmask=mask;
                    int cellkey=nr*n+nc;
                    if(littermap.count(cellkey)){
                        nextmask |=(1<< littermap[cellkey]);
                    }
                    if(nextmask==targetmask){
                        return moves+1;
                    }
                    if(!visited[nr][nc][nexte][nextmask]){
                        visited[nr][nc][nexte][nextmask]=true;
                        q.push({nr,nc,nexte,nextmask,moves+1});
                    }
                }
            }
        }
        return -1;
    }
};