/*
1502. Can Make Arithmetic Progression From Sequence
Easy

A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.
*/
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int diff = arr[1]-arr[0];
        bool ans;
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==diff){
                ans = true;
            }
            else{
                return false;
            }
        }
        return ans;
    }
};