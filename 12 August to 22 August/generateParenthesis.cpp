/*
22. Generate Parenthesis
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/
class Solution {
public:
    void solve(vector<string> &ans,int n, int open, int close, string output){
        // Base case
        if(open==0 && close==0){
            ans.push_back(output);
            return;
        }
        // include open bracket
        if(open >0){
            output.push_back('(');
            solve(ans,n,open-1,close,output);
            //backtrack
            output.pop_back();
        }
        if(close>open){
            output.push_back(')');
            solve(ans,n,open,close-1,output);
            // backtrack
            output.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        int open=n;
        int close=n;
        solve(ans,n,open,close,output);
        return ans;
    }
};