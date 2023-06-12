/*
383. Ransom Note
Easy
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       map<char,int> m;
        for(int i=0;i<magazine.size();i++){
            m[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            m[ransomNote[i]]--;
        }
for (auto i : m){
    if(i.second<0){
            return false;
        }
}
      return true;  
    }
};