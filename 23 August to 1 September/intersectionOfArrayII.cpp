/*
350. Intersection of Two Arrays II
Easy

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         vector<int> ans;
       if(nums1.size()>nums2.size()){
           swap(nums1,nums2);
       }
        unordered_map<int,int> m;
        for(auto i:nums1){
            m[i]++;
        }
        int j=0;
        for(auto i: nums2){
            if(m[i]>0){
                ans.push_back(i);
                j++;
                m[i]--;
            }
        }
        return ans;
    }
    
};