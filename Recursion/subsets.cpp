/*
78. Subsets
Medium

Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/
class Solution {
public:
    void getAns(vector<int>& nums,int index, vector<vector<int>> &ans,vector<int> &temp){
        ans.push_back(temp);
        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            getAns(nums,i+1,ans,temp);
            temp.pop_back();
        }       
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        getAns(nums,index,ans,temp);
        return ans;
    }
};