/*双指针*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = 1e9;
        for (int price : prices)
        {
            max_profit = max(max_profit, price - min_price);
            min_price = min(price, min_price);
        }
        return max_profit;
    }
};