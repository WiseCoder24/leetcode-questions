/*
767. Reorganize String
Medium

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.
*/
class node{
    public:
    char data;
    int count;
    node(char d,int c){
        data = d;
        count = c;
    }
};

class compare{
    public:
    bool operator()(node a,node b){
        return a.count < b.count;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        
        priority_queue<node,vector<node>, compare> maxHeap;
        for(auto i:m){
            node temp(i.first,i.second);
            maxHeap.push(temp);
        }
        string ans = "";
        while(maxHeap.size()>1){
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();
            ans += first.data;
            ans += second.data;

            first.count--;
            second.count--;
            
            if(first.count!=0){
                maxHeap.push(first);
            }
            if(second.count!=0){
                maxHeap.push(second);
            }
        }
        if(maxHeap.size()==1){
            node temp = maxHeap.top();
            maxHeap.pop();
            if(temp.count==1)
                ans += temp.data;
            else
                return "";
        }
        return ans;
    }
};