/*
349. Intersection of Two Arrays
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> ans;
        vector<int> ansArr;
        for(int i =0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.insert(nums1[i]);
                }
            }
        }
        for(auto& num: ans)
  {
    ansArr.push_back(num);
  }
        return ansArr;
    }
};