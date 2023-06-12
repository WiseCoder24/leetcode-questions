/*
974. Subarray Sums Divisible by K
Medium

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.
*/
class Solution {
public:
    
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k);
        count[0] = 1;
        int prefix=0;int res=0;
        for(auto i: nums){
            prefix = (prefix+i%k+k)%k;
            res+= count[prefix]++;
        }
        return res;
    }
};