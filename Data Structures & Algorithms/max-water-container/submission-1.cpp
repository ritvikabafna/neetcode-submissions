class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea=INT_MIN;
        int i=0;int j=heights.size()-1; 
        while(i<j){
            int width=j-i;
            int height=min(heights[i],heights[j]);
            int area=width*height;
            maxArea=max(area,maxArea);
            if(heights[i]<heights[j])
                i++;
            else 
                j--;
        }
        return maxArea;
    }
};
