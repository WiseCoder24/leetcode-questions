/*
69. Sqrt(x)
Easy

Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x<2)
            return x;
        int ans;
        int left =1;
        int right = x/2;
        int mid;
        while(left<=right){
            mid = (left+(right-left)/2);
            long temp = (long)mid*(long)mid;
            if(temp==x)
                return mid;
            if(temp<x){
                ans=mid; left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return ans;
    }
};