/*
1512. Number of Good Pairs
Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.
*/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j] && i<j){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        
        return ans.size()/2;
    }
};