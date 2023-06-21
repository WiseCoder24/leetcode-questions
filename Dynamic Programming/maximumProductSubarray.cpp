/*
152. Maximum Product Subarray
Medium

Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1, suff = 1;
        int ans = INT_MIN;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(pre==0) pre = 1;
            if(suff==0) suff = 1;
            pre = pre * nums[i];
            suff = suff * nums[n-i-1];
            ans = max(ans,max(pre,suff));
        }
        return ans;
    }
};


// Time Limit Exceeded
class Solution {
public:
    int findProduct(vector<int>& nums,int start,int end){
        int product = 1;
        for(int i=start;i<=end;i++){
            product *= nums[i];
        }
        return product;
    }
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int maxProduct = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(i<=j){
                    int product = findProduct(nums,i,j);
                    maxProduct = max(maxProduct,product);
                }
            }
        }
        return maxProduct;
    }
};