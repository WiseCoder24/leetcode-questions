/*
66. Plus One
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        vector<int> ans;
        reverse(digits.begin(),digits.end());
        int x = digits[0]+1;
        if(x > 9){
            x = (digits[0]+1) % 10;
            carry = (digits[0]+1)/10;
            ans.push_back(x);
        }
        else{
            ans.push_back(x);
        }
        for(int i=1;i<digits.size();i++){
            int y = digits[i] + carry;
            if(y>9){
                carry = y/10;
                y = y % 10;
                ans.push_back(y);
            }
            else{
                carry = 0;
            ans.push_back(y);
            }
        }
        if(carry != 0){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};