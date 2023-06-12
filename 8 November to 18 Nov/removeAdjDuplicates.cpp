/*
1047. Remove All Adjacent Duplicates In String
Easy

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
*/
class Solution {
public:
    
    string removeDuplicates(string s) {
        vector<char> a;
        for(int i=0;i<s.size();i++){
            if(a.size()>0 && a.back()==s[i]){
                a.pop_back();
            }
            else{
                a.push_back(s[i]);
            }
        }
        // reverse(a.begin(),a.end());
        string ans = "";
        for(int i=0;i<a.size();i++){
            ans += a[i];
        }
        return ans;
    }
};