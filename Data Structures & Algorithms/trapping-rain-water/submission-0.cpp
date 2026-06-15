class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> suffix(height.size());
        int maxi=INT_MIN;
        for(int i=height.size()-1;i>=0;i--){
            suffix[i]=max(maxi,height[i]);
            maxi=suffix[i];
        }
        vector<int> prefix(height.size());
         maxi=INT_MIN;
        for(int i=0;i<height.size();i++){
            prefix[i]=max(maxi,height[i]);
            maxi=prefix[i];
        }
        int maxiWater=0;
        for(int i=1;i<height.size()-1;i++){
            int currWater=(min(prefix[i],suffix[i]))-height[i];
            if(currWater>0)
                maxiWater+=currWater;
            else
                continue;
        }
        return maxiWater;
    
    }
};
