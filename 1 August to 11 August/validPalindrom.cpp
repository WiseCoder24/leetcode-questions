// 125. Valid Palindrome
/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(iswalnum(s[i]) ){
                ans+=s[i];
            }
        }
        for(int i=0;i<ans.size()/2;i++){
            if(tolower(ans[i])!=tolower(ans[ans.size()-i-1])){
                return false;
            }
        }                                     
        return true;
    }
};