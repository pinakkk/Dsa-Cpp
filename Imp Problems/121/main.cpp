class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], maxProfit = 0;
        
        for(int i = 1; i<prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            } else{
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }
        return maxProfit;
    }
};