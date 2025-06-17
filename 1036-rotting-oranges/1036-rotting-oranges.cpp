class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> que;

        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if(fresh == 0){
            return 0;
        }

        int minute = 0;

        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int first = que.front().first;
                int second = que.front().second;
                que.pop();
                for (vector<int>& vec : directions) {
                    int new_first = first + vec[0];
                    int new_second = second + vec[1];
                    if (new_first >= m || new_first < 0 || new_second >= n ||
                        new_second < 0) {
                        continue;
                    }
                    if (grid[new_first][new_second] == 1) {
                        grid[new_first][new_second] = 2;
                        fresh--;
                        que.push({new_first, new_second});
                    }
                }
            }
            minute++;
        }

        if(fresh == 0){
            return minute-1;
        }
        return -1;
    }
};