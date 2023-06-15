/*
416. Partition Equal Subset Sum
Medium
10.6K
190
Companies
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
*/
class Solution {
public:
    bool solveUsingRecursion(int index, vector<int>& nums, int target){
        //Base case
        if(index>=nums.size()) return 0;
        if(target<0) return 0;
        if(target==0) return 1;

        bool include = solveUsingRecursion(index+1,nums,target-nums[index]);
        bool exclude = solveUsingRecursion(index+1,nums,target);

        return (include || exclude);
    }
    bool solveUsingMem(int index,vector<int>& nums, int target,vector<vector<int>> &dp){
        //Base case
        if(index>=nums.size()) return 0;
        if(target<0) return 0;
        if(target==0) return 1;
        if(dp[index][target]!=-1) return dp[index][target];
        bool include = solveUsingMem(index+1,nums,target-nums[index],dp);
        bool exclude = solveUsingMem(index+1,nums,target,dp);

        dp[index][target] = (include || exclude);
        return dp[index][target];
    }
    bool solveUsingTabulation(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<nums.size();i++){
            dp[i][0] = 1;
        }
        for(int index = n-1;index>=0;index--){
            for(int t=1;t<=target;t++){
                bool include = 0;
                if(t-nums[index]>=0)
                    include = dp[index+1][t-nums[index]];
                bool exclude = dp[index+1][t];
                dp[index][t] = (include || exclude);
            }
        }
        return dp[0][target]; // Check why dp[0][target] while revision
    }
    bool solveSO(vector<int>& nums, int target){
        int n = nums.size();
        vector<bool> curr(target+1,0);
        vector<bool> next(target+1,0);

        curr[0] = 1;
        next[0] = 1;

        for(int index = n-1;index>=0;index--){
            for(int t=1;t<=target;t++){
                bool include = 0;
                if(t-nums[index]>=0)
                    include = next[t-nums[index]];
                bool exclude = next[t];
                curr[t] = (include || exclude);
            }
            //Shift
            next = curr;
        }
        return curr[target]; // Check why dp[0][target] while revision
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        // Yaha galti kr sakte hai (If sum is odd) directly return false
        if(sum%2!=0) return false;
        int target = sum/2;
        // int index = 0;
        // bool ans = solveUsingRecursion(index, nums, target);
        // vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        // bool ans = solveUsingMem(index,nums,target,dp);
        // bool ans = solveUsingTabulation(nums,target);
        bool ans = solveSO(nums,target);
        return ans;
    }
};