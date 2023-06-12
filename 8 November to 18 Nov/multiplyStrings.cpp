/*
43. Multiply Strings
Medium

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
#include <bits/stdc++.h>
using namespace std;
inline string add_zero(int n){
    string res = "";
    while(n-- > 0)res += "0";
    return res;
}
string add_string(string& a, string& b){
    if(a.size()>b.size())swap(a,b);
    int a_len = a.size(), b_len = b.size();
    string res = "";
    int sum = 0, carry = 0;
    for(int i=0;i<b_len;i++){
        int a_idx = a_len-1-i, b_idx = b_len-1-i;
        sum = carry + (a_idx>=0 ? (a[a_idx]-'0') : 0) + (b[b_idx]-'0');
        carry = sum/10; sum %= 10;
        res += to_string(sum);
    }
    if(carry>0)
        res += to_string(carry);
    reverse(res.begin(), res.end());
    return res;
}
string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0")
        return "0";
    string res = "";
    if(num1.size()>num2.size())swap(num1, num2);
    int num1_len = num1.size(), num2_len = num2.size();
    for(int i=num1_len-1;i>=0;i--){
        int multiplier = num1[i]-'0';
        int sum = 0, carry = 0;
        string cur_res = "";
        for(int j=num2_len-1;j>=0;j--){
            sum = carry + (num2[j]-'0')*multiplier;
            carry = sum/10; sum %= 10;
            cur_res += to_string(sum);
        }
        if(carry>0)
            cur_res += to_string(carry);
        reverse(cur_res.begin(), cur_res.end());
        cur_res += add_zero(num1_len-i-1);
        res = add_string(res, cur_res);
    }
    return res;
}
int main(){
    string num1 = "123";
    string num2 = "456";
    cout<<multiply(num1, num2);
}