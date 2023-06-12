// 1011. Capacity To Ship Packages Within D Days
// Medium

// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
class Solution {
public:
    bool check(vector<int> &weights,int mid, int days){
        int c = 1;int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>mid){
                c++;
                sum = weights[i];
            }
        }
        if(c<=days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCapacity=0;
        int n = weights.size();
        
        for(int i = 0; i < n; i++)
            maxCapacity += weights[i];
        
        int low = *max_element(weights.begin(), weights.end()), high = maxCapacity;
        int result;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(weights,mid, days)) {
                result = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return result;
    }
        
    
};