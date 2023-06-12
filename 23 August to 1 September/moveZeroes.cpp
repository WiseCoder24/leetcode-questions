/*
283. Move Zeroes
Easy
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int i =0; int j=0;
        while(j<nums.size()){
            if(nums[j]==0)
                j++;
            else{
                swap(nums[i],nums[j]);
                j++;
                i++;
            }
        }
    }
};
