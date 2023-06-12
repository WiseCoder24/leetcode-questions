/*Cut into segments*/
#include <bits/stdc++.h>
using namespace std;
int solve(int n, int x, int y, int z){
	if(n==0) return 0;
	if(n<0) return INT_MIN;
	int ans1= solve(n-x,x,y,z)+1;
	int ans2= solve(n-y,x,y,z)+1;
	int ans3= solve(n-z,x,y,z)+1;
	int ans = max(ans1,max(ans2,ans3));
	return ans;
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	int ans = solve(n,x,y,z);
	if(ans<0) ans = 0;
	return ans;
}