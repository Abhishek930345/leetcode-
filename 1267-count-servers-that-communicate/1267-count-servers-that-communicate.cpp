// class Solution {
// public:
//     int countServers(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         queue<pair<int,int>> q;
//         int vis[n][m];

//          for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
                
//                 if(grid[i][j] == 1){   
//                     q.push({i,j});
//                     vis[i][j] = 0;
//                 } else {
//                     vis[i][j] = 0;
//                 }
//             }
//         }
//         int drow[] = {-1, 0, +1, 0};
//         int dcol[] = {0, 1, 0, -1};

//         while(!q.empty()){
//             int r = q.front().first;
//             int c = q.front().second;
//             q.pop();

//             for(int i = 0; i < 4; i++){
//                 int nrow = r + drow[i];
//                 int ncol = c + dcol[i];
//                 if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
//                    && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1){
//                     vis[r][c] = 1;
//                 }
//             }
//         }
//         int cnt=0;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(vis[i][j] == 1){
//                     cnt++;
//                 }
//             }
//         }

//         return cnt;
//     }
// };
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 &&
                   (row[i] > 1 || col[j] > 1)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};