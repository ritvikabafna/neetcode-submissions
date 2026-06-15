class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;vector<int> zeroIdx;
        int i=0;
        vector<int> ans;
        while(i<nums.size()){
            if(nums[i]==0){
                zeroIdx.push_back(i);
            }
            else
                prod*=nums[i];
            i++;
        }
        if(zeroIdx.size()==0){
            for(int i=0;i<nums.size();i++){
                ans.push_back(prod/nums[i]);
            }
            return ans;
        }
        else if(zeroIdx.size()==1){
            for(int i=0;i<nums.size();i++){
                if(i==zeroIdx[0]){
                    ans.push_back(prod);
                }
                else
                    ans.push_back(0);
            }
            return ans;
        }
        else{
         vector<int> ans2(nums.size(),0);
         return ans2;
        }
        return ans;
        
    }
};
