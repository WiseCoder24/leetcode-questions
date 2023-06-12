/*
503. Next Greater Element II
Medium

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.



The below solution didn't work for some test cases!!!!
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int i=0;
        
        while(ans.size()!=nums.size()){
            i=0;
            while(i<nums.size()){
                vector<int>::iterator it;
                it = find(nums.begin(),nums.end(),nums[i]+1);
                if(it!=nums.end()){
                    ans.push_back(it);
                    i++;
                }
                else{
                    ans.push_back(-1);
                    i++;
                }
            }
        }
        return ans;
    }
};
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int maxEleIdx=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>=nums[maxEleIdx])
            {
                maxEleIdx=i;
            }
        }
        int n=nums.size();
        stack<int> st;  
        vector<int> ans(n);
        int idx=maxEleIdx;   
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() && st.top()<=nums[idx])
                st.pop();
            
            if(st.empty())
            {
                ans[idx]=-1;
            }
            else
            {
                ans[idx]=st.top();
            }
            
            st.push(nums[idx]);
            
            idx--;
            
            if(idx<0)
                idx=nums.size()-1;
        }  
        return ans;
    }
};