/*
2348. Number of Zero-Filled Subarrays
Medium
993
38
Companies
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.
*/
class Solution {
public:
   
    long long zeroFilledSubarray(vector<int>& nums) {
        int temp=0;
        vector<long long> sizes;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                temp++;
            }
            else{
                sizes.push_back(temp);
                temp=0;
            }
        }
        if(temp!=0) {
            sizes.push_back(temp);
            temp = 0;
            }

        for(auto i:sizes){
            cout<<i<<" ";
        }
        cout<<endl;
        long long ans = 0;
        for(long long i=0;i<sizes.size();i++){
            long long temp =(sizes[i]*(sizes[i]+1)/2);
            ans+=temp;
        }
        return ans;
    }
};