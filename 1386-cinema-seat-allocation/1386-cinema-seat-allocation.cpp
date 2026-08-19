class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> reserved;
        for(const auto& seat: reservedSeats){
            int row =seat[0];
            int col=seat[1];
            reserved[row] |=(1<<(col-1));
        }
        int leftmask =0b0111100000;
        int rightmask=0b0000011110;
        int middlemask=0b0001111000;
        int maxfamily=(n-reserved.size())*2;
        for(const auto& [row,mask]: reserved){
            bool canplaceleft=(mask & leftmask)==0;
            bool canplaceright=(mask & rightmask)==0;
            bool canplacemiddle=(mask & middlemask)==0;
            if(canplaceleft && canplaceright){
                maxfamily+=2;
            }
            else if(canplaceleft || canplaceright|| canplacemiddle){
                maxfamily+=1;
            }
        }
        return maxfamily;
    }
};