/*
1002. Find Common Characters
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
*/
class Solution {
public:
    vector<string> commonChars(vector<string>A) {
        unordered_map <char , int> finalCount;
    for(char c = 'a' ; c <= 'z' ; ++c)
        finalCount[c] = 100;
    unordered_map <char , int> count;
    for(string &word : A)
    {
        count.clear();
        for(char c : word)
            count[c]++;
        for(char c = 'a' ; c <= 'z' ; ++c)
            finalCount[c] = min(finalCount[c] , count[c]);
    }
    vector <string> result;
    string temp;
    int times;
    for(char c = 'a' ; c <= 'z' ; ++c)
    {
        times = finalCount[c];
        temp = c;
        while(times > 0)
        {
            result.push_back(temp);
            --times;
        }
    }
    return result;
    }
};