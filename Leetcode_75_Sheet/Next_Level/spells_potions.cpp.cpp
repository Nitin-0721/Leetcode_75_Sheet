class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        int m = potions.size();

         sort(potions.begin(), potions.end());

        for (int spell : spells) {
            long long minPotion = (success + spell - 1) / spell;  

            // binary search in potions
            int idx = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();

            result.push_back(m - idx);  
        }

        return result;
    }
};