/*
647. Palindromic Substrings
Medium

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.
*/
class Solution {
public:
    int expandAroundIndex(string s, int i, int j){
        int c = 0;
        while(i>=0 && j<s.size() && s[i]==s[j]){
            c++;
            i--;
            j++;
        }
        return c;
    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0;i<s.size();i++){
            // Odd
            int odd = expandAroundIndex(s,i,i);
            count += odd;
            //Even
            int even = expandAroundIndex(s,i,i+1);
            count += even;
        }
        return count;
    }
};