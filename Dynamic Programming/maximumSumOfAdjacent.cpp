/*
Maximum sum of non-adjacent elements
Problem Statement

*/
#include <bits/stdc++.h> 
using namespace std;
int maxSum(int n, vector<int> &nums, vector<int>&dp){
    if(n==0) return nums[n];
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int pick = nums[n] + maxSum(n-2,nums,dp);
    int notPick = 0 + maxSum(n-1,nums,dp);
    
    return dp[n] = max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n+1,-1);
    return maxSum(n-1,nums,dp);
}