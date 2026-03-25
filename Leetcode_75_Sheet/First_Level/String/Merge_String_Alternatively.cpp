class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int maxLength = max(l1, l2);

        vector<char> mergedWord;

        for (int i = 0; i < maxLength; i++) {
            if(i < l1){
                mergedWord.push_back(word1[i]);
            }
            if(i < l2){
                mergedWord.push_back(word2[i]);
            }
        }
        return string(mergedWord.begin(),mergedWord.end());
    }
};