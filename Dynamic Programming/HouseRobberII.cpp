/*
213. House Robber II
Medium

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

/*---------Time Limit Exceeded---------*/
class Solution {
public:
    int maxMoney(int n, vector<int> nums, vector<int> dp){
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
        if(n==1) return nums[0];
        vector<int> num1;
        vector<int> num2;
        for(int i=0;i<n;i++){
            if(i!=0) num1.push_back(nums[i]);
            if(i!=n-1) num2.push_back(nums[i]);
        }
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        return max(maxMoney(n-2,num1,dp1),maxMoney(n-2,num2,dp2));
    }
};