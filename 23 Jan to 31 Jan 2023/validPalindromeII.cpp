// 680. Valid Palindrome II
// Easy

// Given a string s, return true if the s can be palindrome after deleting at most one character from it.
class Solution {
public:
    bool checkPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else if(s[i]!=s[j]){
                //ek baar i ko remove ya to ek baar j ko remove
                return checkPalindrome(s,i+1,j) || checkPalindrome(s,i,j-1);
            }
        }
        return true;
    }
};