//342. Power of four
// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4x.
class Solution {
public:
    bool isPowerOfFour(int n) {
        long long x = 1;
        while(x<=n){
            
            if(x==n){
                return true;
            }
            x *= 4;
        }
        return false;
    }
};