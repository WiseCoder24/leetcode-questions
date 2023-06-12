// Given an integer x, return true if x is palindrome integer.
// An integer is a palindrome when it reads the same backward as forward.
// For example, 121 is a palindrome while 123 is not.
class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> ans;
        int comp = x;
        int temp;
        long long result = 0;
        if(x<0){
            return false;
        }
        while(x){
            temp = x%10;
            x = x/10;
            ans.push_back(temp);
        }
        for(int i=0;i<ans.size();i++){
            result = result*10+ans[i];
        }
        if(result==comp){
            return true;
        }
        return false;
    }
};