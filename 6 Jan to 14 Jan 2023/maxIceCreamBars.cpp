/*
1833. Maximum Ice Cream Bars
Medium

It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Return the maximum number of ice cream bars the boy can buy with coins coins.

Note: The boy can buy the ice cream bars in any order.
*/
class Solution {
public:
    
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int coins2 = coins;
        int ans = 0;
        int i=0;
        while(i<costs.size()){
            if(coins2<=0){
                break;
            }
            if(coins2-costs[i]>=0){
                coins2 = coins2 - costs[i];
                ans++;
            }
            i++;
        }
        
        return ans;
    }
};