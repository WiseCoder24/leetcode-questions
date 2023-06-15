/*
1155. Number of Dice Rolls With Target Sum
Medium
3.9K
122
Companies
You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

*/
class Solution {
public:
    long long int MOD = 1000000007;
    int solveUsingRec(int n,int k, int target){
        if(n<0) return 0;
        if(n==0 && target==0) return 1;
        if(n==0 && target!=0) return 0;
        if(n!=0 && target==0) return 0;
        
        int ans = 0;
        for(int i=1;i<=k;i++){
            ans += solveUsingRec(n-1,k,target-i);
        }
        return ans;
    }
    long long int solveUsingMem(int n,int k, int target,vector<vector<long long int>> &dp){
        if(n<0) return 0;
        if(n==0 && target==0) return 1;
        if(n==0 && target!=0) return 0;
        if(n!=0 && target==0) return 0;
        if(dp[n][target]!=-1) 
            return dp[n][target];
        long long int ans = 0;
        for(int i=1;i<=k;i++){
            long long int recAns = 0;
            if(target-i>=0)
            recAns = solveUsingMem(n-1,k,target-i,dp);
            ans = (ans%MOD + recAns%MOD)%MOD;
        }
        dp[n][target] = ans;
        return dp[n][target];
    }
    int solveUsingTabulation(int n,int k, int target){
        vector<vector<long long int>> dp(n+1,vector<long long int>(target+1,0));
        dp[0][0] = 1;
        for(int index = 1;index<=n;index++){
            for(int t = 1;t<=target;t++){
                long long int ans = 0;
                for(int i=1;i<=k;i++){
                    long long int recAns = 0;
                    if(t-i>=0)
                        recAns = dp[index-1][t-i];
                    ans = (ans%MOD + recAns%MOD)%MOD;
                }
                dp[index][t] = ans;
            }
        }
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        // int ans = solveUsingRec(n,k,target);
        // vector<vector<long long int>> dp(n+1,vector<long long int>(target+1,-1));
        // int ans = solveUsingMem(n,k,target,dp);
        int ans = solveUsingTabulation(n,k,target);
        return ans;
    }
};