// 84. Largest Rectangle in Histogram
// ***************Hard******************
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
class Solution {
public:
    vector<int> prevSmallerElement(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for(int i=0;i<n;i++){
            int curr = arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmallerElement(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        st.push(-1);
        for(int i=arr.size()-1;i>=0;i--){
            int curr = arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        // Find prev smaller element index
        vector<int> prev = prevSmallerElement(heights);
        // Find next smaller element index
        vector<int> next = nextSmallerElement(heights);
        int size = heights.size();
        int maxArea = INT_MIN;
        for(int i=0;i<heights.size();i++){
            int length = heights[i];
            if(next[i]==-1) next[i] = size;
            int width = next[i]-prev[i]-1;
            int area = length*width;
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};