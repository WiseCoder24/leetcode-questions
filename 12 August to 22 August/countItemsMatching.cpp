/*
1773. Count Items Matching a Rule
You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

The ith item is said to match the rule if one of the following is true:

ruleKey == "type" and ruleValue == typei.
ruleKey == "color" and ruleValue == colori.
ruleKey == "name" and ruleValue == namei.
Return the number of items that match the given rule.
*/
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int c=0;
        for(int i=0;i<items.size();i++){
            
                if(ruleKey=="type" && items[i][0]==ruleValue){
                    c++;
                }
                else if(ruleKey=="color" && items[i][1]==ruleValue){
                    c++;
                }
                else if(ruleKey=="name" && items[i][2]==ruleValue){
                    c++;
                }
            
        }
        return c;
    }
};