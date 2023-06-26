/*
733. Flood Fill
Easy

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.
*/
class Solution {
public:
    void dfs(int x, int y, int oldColor,int newColor, map<pair<int,int>,bool> &vis, vector<vector<int>>& arr){
        vis[{x,y}] = true;
        arr[x][y] = newColor;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX>=0 && newX<arr.size() && newY>=0 && newY < arr[0].size() && !vis[{newX,newY}] && arr[newX][newY]==oldColor){
                    dfs(newX, newY,oldColor,newColor,vis,arr);
                }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        map<pair<int,int>,bool> vis;
        vector<vector<int>> ans = image;
        dfs(sr,sc,oldColor,color,vis,ans);
        return ans;
    }
};