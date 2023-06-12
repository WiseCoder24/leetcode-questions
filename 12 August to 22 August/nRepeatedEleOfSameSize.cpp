/*
961. N-Repeated Element in Size 2N Array
You are given an integer array nums with the following properties:

nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.
*/
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;
        map<int,int> freq;
        int ans;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        map<int, int>::iterator itr;
        for (itr = freq.begin(); itr != freq.end(); ++itr) {
        if(itr->second == n){
            ans = itr->first;
        }
    }
        return ans;
    }
};