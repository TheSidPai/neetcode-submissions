class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        int currMax = prices[n-1];
        for(int i = n-2; i >= 0; i--){
            if(currMax < prices[i]) currMax = prices[i];
            else res = max(res, currMax - prices[i]);
        }

        return res;
    }
};
