/*
1470. Shuffle Array
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].
*/
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int arrSize = nums.size();
        int p1 = 0;
        int p2 = arrSize/2;
        vector<int> ans;
        while(p1<(arrSize/2)){
            ans.push_back(nums[p1]);
            p1++;
            ans.push_back(nums[p2]);
            p2++;
        }
        return ans;
    }
};