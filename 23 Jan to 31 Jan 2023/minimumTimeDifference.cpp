// 539. Minimum Time Difference
// Medium
// 1.4K
// 236
// Companies
// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(int i=0;i<timePoints.size();i++){
            string curr = timePoints[i];
            if(curr == "00:00"){
                curr = "24:00";
            }
            int hours = stoi(curr.substr(0,2));
            int min = stoi(curr.substr(3,2));
            int totalMinutes = hours*60+min;
            minutes.push_back(totalMinutes);
        }
        sort(minutes.begin(),minutes.end());
        int ans = INT_MAX;
        for(int i=0;i<minutes.size()-1;i++){
            ans = min(ans, minutes[i+1]-minutes[i]);
        }
        int lastDiff = (minutes[0]+1440) - minutes[minutes.size()-1];
        ans = min(lastDiff,ans);
        return ans;
    }
};