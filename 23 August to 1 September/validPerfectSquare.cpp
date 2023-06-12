/*
367. Valid Perfect Square
Easy

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1){
            return true;
        }
        for(long long i=1;i<=num/2;i++){
            if(i*i == num){
                return true;
            }
        }
        return false;
    }
};