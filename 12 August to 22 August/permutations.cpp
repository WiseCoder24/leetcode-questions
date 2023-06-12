/*
46. Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/
class Solution {
public:
    vector<vector<int>> ans;
    void allPermutations(vector<int> &nums, int idx){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            allPermutations(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        allPermutations(nums,0);
        return ans;
    }
};