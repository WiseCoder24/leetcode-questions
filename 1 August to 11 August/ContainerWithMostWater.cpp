/*
11. Container With most water
*/
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int area=0;
        int maxArea = INT_MIN;
        while(left!=right){
            if(height[left]<=height[right]){
                area = height[left]*(right-left);
                left++;
            }
            else{
                area = height[right]*(right-left);
                right--;
            }
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};