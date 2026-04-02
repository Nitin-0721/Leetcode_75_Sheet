

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
         sort(products.begin(), products.end());
        
        vector<vector<string>> result;
        int n = products.size();
        int left = 0, right = n - 1;

         for (int i = 0; i < searchWord.length(); i++) {
            char c = searchWord[i];

        
            while (left <= right && (products[left].length() <= i || products[left][i] != c)) {
                left++;
            }
             while (left <= right && (products[right].length() <= i || products[right][i] != c)) {
                right--;
            }

             vector<string> currentBatch;
            int remain = right - left + 1;
            for (int j = 0; j < min(3, remain); j++) {
                currentBatch.push_back(products[left + j]);
            }
            
            result.push_back(currentBatch);
        }

        return result;
    }
};