class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=1;int maxCnt=0;
        if(nums.size()==1)
            return 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-1==nums[i-1]){
                cnt++;
                maxCnt=max(cnt,maxCnt); 
            }
            else if(nums[i]==nums[i-1]){
                maxCnt=max(cnt,maxCnt);
                continue;
            }
            else{
                maxCnt=max(cnt,maxCnt);  
                cnt=1; 
            }
        }
        return maxCnt;
    }
};
