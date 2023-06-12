/*
500. Keyboard Row
Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".
*/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        map<char,int> m;
        string temp = "qwertyuiopQWERTYUIOP";
        for(auto &i : temp){
            m[i] = 1;
        }
        temp = "asdfghjklASDFGHJKL";
        for(auto &i : temp){
            m[i] = 2;
        }
        temp = "zxcvbnmZXCVBNM";
        for(auto &i : temp){
            m[i] = 3;
        }
        bool check;
        for(auto &word: words){
            check = true;
            for(int i=1;i<word.size();i++){
                if(m[word[i]] != m[word[0]]){
                    check = false;
                    break;
                }
            }
            if(check){
                ans.push_back(word);
            }
        }
        return ans;
    }
};