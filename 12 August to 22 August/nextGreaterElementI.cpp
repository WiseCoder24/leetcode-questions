/*
496. Next Greater Element I
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            bool flag=false;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j])flag=true;
                if(flag && nums1[i]<nums2[j]){
                    ans.push_back(nums2[j]);flag=false;break;
                }
            }
            if(flag)ans.push_back(-1);
            
        }
        return ans;
    }
};

/*
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>stack;
        map<int,int>map;
        vector<int>ans;
        for(int i=0;i<nums2.size();i++){
            while(!stack.empty()){
                if(stack.top()<nums2[i]){
                    map.insert(pair<int,int>(stack.top(),nums2[i]));
                    stack.pop();
                }else break;
            }
            stack.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++){
            int val = map[nums1[i]];
            if(val==0)ans.push_back(-1);
            else ans.push_back(val);
        }
        return ans;
    }
*/