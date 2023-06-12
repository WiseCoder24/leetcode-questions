#include<bits/stdc++.h>
using namespace std;

int solve(int dividend, int divisor){
    int s =0;
    int e = dividend;
    int ans = 0;
    int mid = s+(e-s)/2;
    while(s<=e){
        mid = s+(e-s)/2;
        if(mid*divisor == dividend){
            ans = mid;
            break;
        }
        else if(mid*divisor>dividend){
            e = mid-1;
        }
        else if(mid*divisor<dividend){
            ans = mid;
            s= mid+1;
        }
    }
    return ans;
}

int main(){
    int dividend = 22;
    int divisor = 7;
    int ans = solve(dividend,divisor);
    cout<<ans<<endl;
}