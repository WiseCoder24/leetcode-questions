/*
44. Wildcard Matching
Hard
7.2K
298
Companies
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

// (TIME LIMIT EXCEEDED)
class Solution {
public:
    int solve(string &s, string &p, int si, int pi){
        //Base case
        if(si==s.size() && pi==p.size()) return true;
        if(si==s.size() && pi<p.size()){
            for(int i=pi;i<p.size();i++){
                if(p[i]!='*') return false;
            }
            return true;
        }

        //Single char match
        if(s[si]==p[pi] || p[pi]=='?'){
            return solve(s,p,si+1,pi+1);
        }

        if(p[pi]=='*'){
            // Treat * as empty
            bool caseA = solve(s,p,si,pi+1);
            //Let * consume 1 char
            bool caseB = solve(s,p,si+1,pi);
            return caseA || caseB;
        }

        //Char doesn't match
        return false;
    }
    bool isMatch(string s, string p) {
        int si = 0;
        int pi = 0;
        bool ans = solve(s, p, si, pi);
        return ans;
    }
};