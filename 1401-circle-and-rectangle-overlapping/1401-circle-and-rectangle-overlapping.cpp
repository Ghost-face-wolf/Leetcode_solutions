class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xclosest=clamp(xCenter,x1,x2);
        int yclosest=clamp(yCenter,y1,y2);
        int deltax=xCenter-xclosest;
        int deltay=yCenter-yclosest;
        int dist=deltax*deltax+deltay*deltay;
        return dist<=radius*radius;
    }
};