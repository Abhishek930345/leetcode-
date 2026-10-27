
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == n - 1) {
                    grid[i][j] = '.';
                }
                else {
                    grid[i][j] = '#';
                }
            }
        }
        return grid;
    }
};

// class Solution {
// public:
//     vector<string> createGrid(int m, int n) {
//         vector<string> grid(m, string(n, '#'));

//         for (int i = 0; i < m; i++) {
//             grid[i][n - 1] = '.';
//         }

//         for (int j = 0; j < n; j++) {
//             grid[0][j] = '.';
//         }

//         return grid;
//     }
// };
