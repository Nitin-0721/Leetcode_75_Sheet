class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int freshCount = 0;
        queue<pair<int, int>> q;

        // 1. Scan the grid to find initial rotten oranges and count fresh ones
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }

        // If there are no fresh oranges, it takes 0 minutes
        if (freshCount == 0) return 0;

        int minutes = 0;
        int dR[] = {0, 0, 1, -1};
        int dC[] = {1, -1, 0, 0};

        // 2. BFS: Process each "minute" layer by layer
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            minutes++; // Increment time for the next level of infection
            
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();

                for (int j = 0; j < 4; ++j) {
                    int nr = r + dR[j];
                    int nc = c + dC[j];

                    // If neighbor is fresh, rot it and add to queue
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        freshCount--;
                        q.push({nr, nc});
                    }
                }
            }
        }

        // 3. Final check: Are there still fresh oranges left?
        return (freshCount == 0) ? minutes : -1;
    }
};