class Solution {
public:
    void backtrack(int k, int target, int start, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == k) {
            if (target == 0) {
                result.push_back(path);
            }
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > target) break; 

            path.push_back(i); 
            backtrack(k, target - i, i + 1, path, result); 
            path.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(k, n, 1, path, result);
        return result;
    }
};