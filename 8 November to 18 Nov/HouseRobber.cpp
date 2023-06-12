/*
198. House Robber
Medium

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/
class Solution {
public:
    int maxMoney(int n, vector<int> &nums, vector<int> &dp){
        if(n==0){
            return nums[n];
        }
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int rob = nums[n] + maxMoney(n-2,nums,dp);
        int Nrob = 0 + maxMoney(n-1,nums,dp);
        return dp[n] = max(rob,Nrob);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1,-1);
        return maxMoney(n-1,nums,dp);
    }
};