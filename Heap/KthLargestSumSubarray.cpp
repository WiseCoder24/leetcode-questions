//K-th Largest Sum Subarray

//Solution 1 (Using Min heap)
#include<bits/stdc++.h>
using namespace std;
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	priority_queue<int,vector<int>,greater<int>> minHeap;
	int n=arr.size();
	int sum=0;
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			if(minHeap.size()<k){
			minHeap.push(sum);
			}
			else{
				if(minHeap.top()<sum){
					minHeap.pop();
					minHeap.push(sum);
				}
			}
		}
	}
	return minHeap.top();
}

//Solution 2 (Simple)
#include<bits/stdc++.h>
using namespace std;
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	int add = 0;
	int n=arr.size();
	vector<int> sum;
	for(int i=0;i<arr.size();i++){
		add = 0;
		for(int j=i;j<arr.size();j++){
		add+= arr[j];
		sum.push_back(add);
	}
	
	}
	
	sort(sum.begin(),sum.end());
	
	int ansIdx = sum.size()-k;
	return sum[ansIdx];
}

