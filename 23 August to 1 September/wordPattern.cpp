/*
290. Word Pattern
Easy

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
*/
/*
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> m;
        vector<string> words;
        string temp = "";
        for(int i=0;i<=s.size();i++){
            if(s[i]=='\0'){
                words.push_back(temp);
                break;
            }
            else if(s[i]==' '){
                words.push_back(temp);
                temp = "";
            }
            else{
               temp+=s[i]; 
            }
        }
        
        if(words.size() != pattern.size()) return 0;
        
        map<string,int> vis;
        for(int i=0;i<pattern.size();i++){
            if(m.find(pattern[i]) != m.end()){
                if(m[pattern[i]] != words[i]){
                    return 0;
                }
            }
            else{
                m[pattern[i]] = words[i];
                if(vis[words[i]])
                    return 0;
                vis[words[i]] = 1;
            }
        }
        return 1;
    }
};
*/
