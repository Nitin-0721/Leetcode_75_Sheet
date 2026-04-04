
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();
        
      
        queue<pair<pair<int, int>, int>> q;
        
        int startR = entrance[0];
        int startC = entrance[1];
        
        q.push({{startR, startC}, 0});
        maze[startR][startC] = '+';  
        
         int dR[] = {0, 0, 1, -1};
        int dC[] = {1, -1, 0, 0};
        
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            
            int r = current.first.first;
            int c = current.first.second;
            int steps = current.second;
            
            // Check all 4 adjacent directions
            for (int i = 0; i < 4; ++i) {
                int nr = r + dR[i];
                int nc = c + dC[i];
                
                 if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] == '.') {
                    
                     if (nr == 0 || nr == rows - 1 || nc == 0 || nc == cols - 1) {
                        return steps + 1;
                    }
                    
                     maze[nr][nc] = '+';
                    q.push({{nr, nc}, steps + 1});
                }
            }
        }
        
        return -1;  
    }
};