/*
119. Pascal's Triangle II
Easy

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ptriangle(rowIndex+1);
        for(int i=0;i<=rowIndex;i++){
            ptriangle[i].resize(i+1);
            ptriangle[i][0] = 1;
            ptriangle[i][i] = 1;
            for(int j=1;j<i;j++){
                ptriangle[i][j] = ptriangle[i-1][j-1]+ptriangle[i-1][j];
            }
        }
        vector<int> ans;
        int n=ptriangle[rowIndex].size();
        for(int i=0;i<n;i++){
            ans.push_back(ptriangle[rowIndex][i]);
        }
        return ans;
    }
};