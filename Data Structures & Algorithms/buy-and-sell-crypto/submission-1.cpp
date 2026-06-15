class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int minPrice=prices[0];
        for(int j=1;j<prices.size();j++){
           minPrice=min(minPrice,prices[j]);
           int profit=prices[j]-minPrice;
           maxProfit=max(profit,maxProfit);
        }
        return maxProfit;
    }
};
