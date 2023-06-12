/*
869. Reordered Power of 2
Medium

You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.
*/
class Solution {
public:
    vector<int> freq_count(int num){
        vector<int> array(10);
        while(num>0){
            array[num%10]++;
            num = num/10;
        }
        // cout<<"it works"<<endl;
        return array;
    }
    bool reorderedPowerOf2(int n) {
         vector<int> freq = freq_count(n);
        for(int i=0;i<=30;i++){
            vector<int> check = freq_count(1<<i);
            if(freq == check){
                return true;
            }
        }
        return false;
    }
};