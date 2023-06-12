/*
14. Longest Common Prefix
Easy
14.1K
4K
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        //Loop on first string
        for(int i=0;i<strs[0].length();i++){
            char ch = strs[0][i];
            bool match = true;
            // Compare this character with all remaining strings at same index
            for(int j=1;j<strs.size();j++){
                //compare
                if(strs[j].size()<i || ch != strs[j][i]){
                    match = false;
                    break;
                }
            }
            if(!match){
                break;
            }
            else
                ans.push_back(ch);
        }
        return ans;
    }
};

// If there is no common prefix, return an empty string "".
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int maxL = strs[0].length();
        bool match = true;
        int j = 0;
        for (int i = 1; i < strs.size(); i++)
        {
            if ((strs[i]).length() == 0 || (strs[i])[0] != (strs[0])[0])
                return "";
            while (match && j < maxL && j < strs[i].length())
            {
                match = ((strs[i])[j] == (strs[0])[j]);
                j++;
            }
            if (!match)
                maxL = j - 1;
            if (strs[i].length() < maxL)
                maxL = strs[i].length();
            j = 0;
            match = true;
        }
        return strs[0].substr(0, maxL);
    }
};