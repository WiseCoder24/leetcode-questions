// 239. Sliding Window Maximum
// Hard
// 14.3K
// 464
// Companies
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        //Traverse first window
        for(int i=0;i<k;i++){
            //Chhote elements remove krdo
            while(!q.empty() && nums[i]>=nums[q.back()]){
                q.pop_back();
            }
            //Inserting index so that we can check out of window
            q.push_back(i); 
        }
        // Store answer of first window
        ans.push_back(nums[q.front()]);
        // remaining window ko process karo
        for(int i=k;i<nums.size();i++){
            // Out of window element ko remove krdo
            if(!q.empty() && i-q.front()>=k){
                q.pop_front();
            }
            // Ab current element ke liye chhote element ko remove krna hai
            while(!q.empty() && nums[i]>=nums[q.back()]){
                q.pop_back();
            }
            //Inserting index so that we can check out of window
            q.push_back(i); 
            //Current window ka answer store krna hai
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};