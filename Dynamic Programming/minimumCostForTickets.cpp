/*
983. Minimum Cost For Tickets
Medium
7.2K
126
Companies
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.
*/
class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i,vector<int> &dp){
        if(i>=days.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        // For 1 day pass
        int cost1 = costs[0] + solve(days,costs,i+1,dp);
        
        //For 7 day pass
        int daysAllowed = days[i] + 7 - 1;
        int j=i;
        while(j<days.size() && days[j]<=daysAllowed){
            j++;
        }
        int cost7 = costs[1] + solve(days,costs,j,dp);

        // For 30 day pass
        daysAllowed = days[i] + 30 - 1;
        j=i;
        while(j<days.size() && days[j]<=daysAllowed){
            j++;
        }
        int cost30 = costs[2] + solve(days,costs,j,dp);

        dp[i] = min(cost1,min(cost7,cost30));
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = 0;
        for(auto i:costs){
            n += i;
        }
        vector<int> dp(365,-1);
        int ans = solve(days,costs,0,dp);
        return ans;
    }
};