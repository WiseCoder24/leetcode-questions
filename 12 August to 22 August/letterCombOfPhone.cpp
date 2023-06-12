/*
17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/

//Solution 1 
class Solution {
public:

    void solve(vector<string> &ans,int index,string output,string digits,vector<string> &map){
        //Base case
        if(index>=digits.size()){
            ans.push_back(output);
            return;
        }
        // recursive call
        int digit = digits[index]-'0';
        string value = map[digit];
        for(int i=0;i<value.length();i++){
            char ch = value[i];
            output.push_back(ch);
            solve(ans,index+1,output,digits,map);
            //Backtrack
            output.pop_back();
        }

        /////OR
        // for(int i=0;i<value.length();i++){
        //     char ch = value[i];
        //     solve(ans,index+1,output+ch,digits,map);
        // }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int index = 0;
        if(digits=="") return ans;
        string output = "";
        vector<string> map(10);
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";

        solve(ans,index,output,digits,map);
        return ans;
    }
};

//Solution 2
unordered_map<char, string> L({{'2',"abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}});

class Solution {
public:
    vector<string> letterCombinations(string D) {
        int len = D.size();
        vector<string> ans;
        if (!len) return ans;
        bfs(0, len, "", ans, D);
        return ans;
    }

    void bfs(int pos, int &len, string str, vector<string> &ans, string &D) {
        if (pos == len) ans.push_back(str);
        else {
            string letters = L[D[pos]];
            for (int i = 0; i < letters.size(); i++)
                bfs(pos+1, len, str+letters[i], ans, D);
        }
    }
};



