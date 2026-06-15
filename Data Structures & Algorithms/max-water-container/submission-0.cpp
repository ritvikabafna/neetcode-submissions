class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea=INT_MIN;
        for(int i=0;i<heights.size()-1;i++){
         for(int j=i+1;j<heights.size();j++){
                int width=j-i;
                int height=min(heights[i],heights[j]);
               int  area=width*height;
                maxArea=max(area,maxArea);
            }   
        }
        return maxArea;
    }
};
