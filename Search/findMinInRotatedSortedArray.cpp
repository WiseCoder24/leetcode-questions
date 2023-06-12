// 153. Find Minimum in Rotated Sorted Array
// Medium

// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.
class Solution {
public:
int pivot(vector<int> arr){
    int s=0;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;
    while(s<e){
        mid = s+(e-s)/2;
        if(mid+1 < arr.size() && arr[mid]>arr[mid+1]) return arr[mid+1];
        if(mid-1>=0 && arr[mid]<arr[mid-1]) return arr[mid];
        if(arr[e]<arr[mid]) s = mid;
        if(arr[e]>arr[mid]) e = mid-1;
        // return arr[s];
    }
    return arr[s];
}
    int findMin(vector<int>& nums) {
      int ans = pivot(nums);
      return ans;  
    }
};