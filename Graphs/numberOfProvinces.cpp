/*
547. Number of Provinces
Medium

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/
class Solution {
public:
    void dfs(unordered_map<int,bool> &visited, int src, vector<vector<int>>& isConnected){
        visited[src] = true;
        // row -> src
        // col -> we will write loop
        int size = isConnected[src].size();
        for(int col=0;col<size;col++){
            if(src!=col && isConnected[src][col]==1){
                // Col is a neighbour
                if(!visited[col]){
                    dfs(visited,col,isConnected);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool> visited;
        int cnt = 0;
        int n = isConnected.size();
        for(int i=1;i<=n;i++){
            if(!visited[i-1]){
                dfs(visited,i-1,isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};