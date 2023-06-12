/*
2390. Removing Stars From a String
Medium

You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
*/
// Solution 1 (Using stack)
class Solution {
public:
    string removeStars(string s) {
        string temp = s;
        string ans = "";
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Solution 2 (Without using stack)
class Solution {
public:
    string removeStars(string s) {
        string temp = s;
        string ans = "";
        // stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
                ans.push_back(s[i]);
            }
            else if(s.length()!=0){
                ans.pop_back();
            }
        }
        
        return ans;
    }
};