/*
2357. Make Array Zero by Subtracting Equal Amounts
Easy

You are given a non-negative integer array nums. In one operation, you must:

Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
Subtract x from every positive element in nums.
Return the minimum number of operations to make every element in nums equal to 0.
*/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int ans = 0;
       int s = nums.size();
       for(int i=0;i<s;i++){
           if(nums[i]>0){
               int temp = nums[i];
               ans++;
               for(int j=0;j<s;j++){
                   nums[j] = nums[j] - temp;
               }
           }
       } 
       return ans;
    }
};