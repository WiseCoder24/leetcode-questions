// 128. Longest Consecutive Sequence
/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       set<int> hashSet;
        int currentnum;
        int longestStreak = 0;
        
        for(int num: nums){
            hashSet.insert(num);
        }
        for(int num: nums){
            
            if(!hashSet.count(num-1)){
                currentnum = num;
                int currentStreak =1;
                while(hashSet.count(currentnum+1)){
                currentnum+=1;
                currentStreak+=1;
            }
                longestStreak = max(longestStreak,currentStreak);
            }
            
            
        }
        return longestStreak;
    }
};