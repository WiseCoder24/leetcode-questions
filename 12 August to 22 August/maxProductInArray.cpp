/*
1464. Maximum Product of Two Elements in an Array
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = 1;
        int maxProduct = INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i!=j){
                    product = (nums[i]-1) * (nums[j]-1);
                maxProduct = max(product,maxProduct);
                }
            }
        }
        return maxProduct;
    }
};