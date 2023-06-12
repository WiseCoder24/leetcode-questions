/*
451. Sort Characters By Frequency

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.
*/
class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        string ans="";
        // int maxFreq= INT_MIN;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        vector<int> temp;
        for(auto i:m){
            temp.push_back(i.second);
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        
        for(int i=0;i<temp.size();i++){
            for(auto it:m){
                if(it.second == temp[i]){
                    int freq = it.second;
                    
                    while(freq>0){
                        // cout<<freq<<" ";
                        ans+=it.first;
                        freq--;
                        if(freq==0){
                            m.erase(it.first);
                        }
                    }
                }
            }
        }
        return ans;
    }
};