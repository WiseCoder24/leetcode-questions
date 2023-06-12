/*
1329. Sort the Matrix Diagonally
A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.
*/
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int y = mat.size(), x = mat[0].size() - 1;
        vector<int> diag(y);
        for (int i = 2 - y; i < x; i++) {
            int k = 0;
            for (int j = 0; j < y; j++)
                if (i+j >= 0 && i+j <= x) {
                    diag[k] = mat[j][i+j];
                    k++;
                }
            sort(diag.begin(), diag.begin() + k);
            k = 0;
            for (int j = 0; j < y; j++)
                if (i+j >= 0 && i+j <= x) {
                    mat[j][i+j] = diag[k];
                    k++;
                }
        }
        return mat;
    }
};