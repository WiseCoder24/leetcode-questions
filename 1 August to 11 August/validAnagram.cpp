/*
242. Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> freq1;
        map<char, int> freq2;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            freq1[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            freq2[t[i]]++;
        }
        if(freq1!=freq2)
            return false;
        return true;
    }
};