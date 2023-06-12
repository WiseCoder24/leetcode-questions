// 34. Find First and Last Position of Element in Sorted Array
// Medium

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        //For first occurence
        int mid = s+(e-s)/2;
        int ans1 = -1;
        int ans2 = -1;
        vector<int> res(2,-1);
        while(s<=e){
            if(nums[mid]==target){
                ans1 = mid;
                e = mid-1;
            }
            else if(target<nums[mid]){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        
        res[0] = ans1;
        //For last occurence
        s = 0; e=n-1; mid = s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                ans2 = mid;
                s = mid+1;
            }
            else if(target<nums[mid]){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
    
        res[1] = ans2;

        return res;
    }
};