/*
From coding ninjas
Problem Statement:

Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
*/
#include <bits/stdc++.h> 
using namespace std;
int minEnergy(int n, vector<int> &heights, vector<int> &dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!= -1) return dp[n];
    int right = INT_MAX;
    int left = minEnergy(n-1,heights,dp) + abs(heights[n]-heights[n-1]);
    if(n>1)
        right = minEnergy(n-2,heights,dp) + abs(heights[n]-heights[n-2]);
    
    return dp[n] = min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1, -1);
    return minEnergy(n-1,heights, dp);
}