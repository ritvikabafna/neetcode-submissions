#include<cmath>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end(), greater<int>());
        int maxi=piles[0];
        if(h==piles.size())
            return maxi;
  
        int st=1,end=maxi;
        int ans=maxi;
        while(st<=end){
            int mid=st+(end-st)/2;
            int i=0;long long totalTime=0;
            while(i<piles.size()){
                totalTime+=ceil((1.0*piles[i])/mid);
                i++;
            }

            if(totalTime<=h){
                ans=mid;
                end=mid-1;
            }
            else{
                st=mid+1;
            }

            
        } 
        return ans;


    }
};
