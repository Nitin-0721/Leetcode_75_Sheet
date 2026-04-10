class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;

        for (int i = 0; i < nums.size(); ++i)
            indices[nums[i]].push_back(i);

        int minDistance = INT_MAX;

        for (auto& [val, idx] : indices) {
            if (idx.size() >= 3) {
                // Slide a window of 3: distance = 2 * (idx[i+2] - idx[i])
                for (int i = 0; i + 2 < idx.size(); ++i)
                    minDistance = min(minDistance, 2 * (idx[i+2] - idx[i]));
            }
        }

        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};