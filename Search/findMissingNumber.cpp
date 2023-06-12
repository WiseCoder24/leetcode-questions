/*
268. Missing Number
Easy

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
*/

// All testcases solved solution
class Solution {
public:
    
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s=0;
        int e = n;
        int mid;
        sort(nums.begin(),nums.end());
        while(s<e){
            mid = s+ (e-s)/2;
            if(nums[mid]>mid) e = mid;
            else s = mid+1;
        }
        return s;
    }
};

// Some testcases unsolved (My solution)
class Solution {
public:
    int ans = -1;
    void binarySearch(vector<int> &nums,int s,int e){
        int mid = s+(e-s)/2;
        if(s>e) {
            return;
        }
        if(nums[mid]!=mid) ans = s;
        if(mid==nums.size()-1 && ans == -1) ans = s+1;
        binarySearch(nums,s,mid-1);
        binarySearch(nums,mid+1,e);
        // return s;
    }
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s=0;
        int e = n-1;
        sort(nums.begin(),nums.end());
        if(nums[0]!=0) return 0;
        // if(nums[n-1]!=n-1) return (n-1);
        binarySearch(nums,s,e);
        return ans;
    }
};