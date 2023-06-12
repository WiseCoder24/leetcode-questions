/*
189. Rotate Array
Medium
13.7K
1.6K
Companies
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

// Solution 1 (Some testcases not solved)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size()) return;
        int n = nums.size()-k;
        stack<int> s1;
        vector<int> temp;
        for(int i=0;i<k;i++){
            s1.push(nums[nums.size()-1]);
            nums.pop_back();
        }
        queue<int> q2;
        for(int i=0;i<n;i++){
            q2.push(nums[i]);
        }
        while(!s1.empty()){
            temp.push_back(s1.top());
            s1.pop();
        }
        while(!q2.empty()){
            temp.push_back(q2.front());
            q2.pop();
        }
        nums = temp;
    }
};