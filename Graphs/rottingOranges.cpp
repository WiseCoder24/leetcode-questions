/*
994. Rotting Oranges
Medium
10.8K
348
Companies
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> arr = grid;
        int count = 0;
        int ansTime = 0;
        // Insert all rotten oranges in queue
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[row].size();col++){
                if(grid[row][col]==2){
                    //Rotten orange found
                    pair<int,int> coordinate = make_pair(row,col);
                    q.push({coordinate,0});
                }
            }
        }

        while(!q.empty()){
            auto fNode = q.front();
            q.pop();

            int x = fNode.first.first;
            int y = fNode.first.second;
            int time = fNode.second;
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX>=0 && newX<arr.size()&& newY>=0 && newY<arr[0].size() 
                    && arr[newX][newY] == 1){
                        pair<int,int> newCoordinates = make_pair(newX,newY);
                        ansTime = max(ansTime,time+1);
                        q.push({newCoordinates,time+1});
                        arr[newX][newY] = 2;
                    }
            }
        }

        // Check for fresh oranges
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]==1) return -1;
            }
        }

        return ansTime;
    }
};