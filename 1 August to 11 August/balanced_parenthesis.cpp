// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        bool ans = true;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    ans = false;
                    break;
                }
            }
            else if(s[i]=='}'){
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
                else{
                    ans = false;
                    break;
                }
            }
            else if(s[i]==']'){
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                else{
                    ans = false;
                    break;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return ans;
    }
};