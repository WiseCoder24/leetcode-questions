//Coding ninjas
#include <bits/stdc++.h>
using namespace std; 
bool check(vector<int> arr,int mid,int n, int m){
        int stdCount = 1;
        int pageSum=0;
        for(int i=0;i<n;i++){
            if(pageSum+arr[i]<=mid){
                pageSum+=arr[i];
            }
            else{
                stdCount++;
                if(stdCount>m || arr[i]>mid){
                    return false;
                }
                pageSum = arr[i];
            }
        }
        return true;
    }
int allocateBooks(vector<int> arr, int n, int m) {
    // Write your code here.
    int s=0;
    int sum = 0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(check(arr, mid, n, m)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}