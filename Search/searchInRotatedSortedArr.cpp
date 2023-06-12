/*
33. Search in Rotated Sorted Array
Medium
20K
1.2K
Companies
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/
class Solution {
public:
    
int binarySearch(vector<int> &nums,int target,int s, int e){
    
    int mid = s+(e-s)/2;
    while(s<=e){
        
        if(nums[mid]==target){
            return mid;
        }
        if(target>nums[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}
    int pivot(vector<int> &nums){
    int s=0;
    int e = nums.size()-1;
    int mid = s+(e-s)/2;
    while(s<e){
        
        if(mid+1<nums.size() && nums[mid]>nums[mid+1]){
            return mid;
        }
        else if(mid-1>=0 && nums[mid-1]>nums[mid]){
            return mid-1;
        }
        if(nums[s]>=nums[mid]){
            e = mid-1;
        }
        else{
            s = mid;
        }
        mid = s+(e-s)/2;
    }
    return s;
}
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivotIndex = pivot(nums);
        
        if(target>=nums[0] && target<=nums[pivotIndex]){
            int ans = binarySearch(nums, target, 0, pivotIndex);
            return ans;
        }
        if(pivotIndex+1<n && target>=nums[pivotIndex+1] && target<=nums[n-1]){
            int ans = binarySearch(nums, target, pivotIndex+1, n-1);
            return ans;
        }
        // cout<<pivotIndex;
        return -1;
    }
};