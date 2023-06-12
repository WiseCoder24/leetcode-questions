/*
532. K-diff Pairs in an Array
Medium

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
nums[i] - nums[j] == k
Notice that |val| denotes the absolute value of val.
*/
//Using two pointer approach
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j = 1;
        int ans = 0;
        set<pair<int,int>> s;
        while(j<nums.size()){
            int diff= nums[j]-nums[i];
            if(diff==k){
                s.insert(make_pair(nums[i],nums[j]));
                i++;
                j++;
            }
            else if(diff>k){
                i++;
            }
            else if(diff<k){
                j++;
            }
            if(i==j) j++;
        }
        return s.size();
    }
};
// Using binary search
class Solution {
public:
    int bs(vector<int> &nums, int start,int x){
        int end = nums.size()-1;
        while(start<=end){
            int mid = start +(end-start)/2;
            if(nums[mid]==x) return mid;
            else if(nums[mid]>x) end = mid-1;
            else
            start = mid+1;
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        set<pair<int,int>> ans;
        for(int i =0;i<nums.size();i++){
            if(bs(nums,i+1, nums[i]+k)!=-1){
                ans.insert(make_pair(nums[i],nums[i]+k));
            }
        }
        return ans.size();
    }
};