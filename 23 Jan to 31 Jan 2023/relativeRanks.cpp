// 506. Relative Ranks
// Easy
// 947
// 46
// Companies
// You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

// The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

// The 1st place athlete's rank is "Gold Medal".
// The 2nd place athlete's rank is "Silver Medal".
// The 3rd place athlete's rank is "Bronze Medal".
// For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
// Return an array answer of size n where answer[i] is the rank of the ith athlete.
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted_scores = score;
        sort(sorted_scores.begin(),sorted_scores.end());
        reverse(sorted_scores.begin(),sorted_scores.end());
        vector<string> answer;
        map<int,string> m;
        if(sorted_scores.size()>=3){
            m[sorted_scores[0]] = "Gold Medal";
            m[sorted_scores[1]] = "Silver Medal";
            m[sorted_scores[2]] = "Bronze Medal";
        }
        if(sorted_scores.size()==2){
            m[sorted_scores[0]] = "Gold Medal";
            m[sorted_scores[1]] = "Silver Medal";
           
        }
        if(sorted_scores.size()==1){
            m[sorted_scores[0]] = "Gold Medal";
        }

        
        for(int i=3;i<sorted_scores.size();i++){
            m[sorted_scores[i]] = to_string(i+1);
        }
        // for(auto i:m){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        cout<<endl;
        for(int i=0;i<score.size();i++){
            answer.push_back(m[score[i]]);
        }
        return answer;
    }
};