class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int count = 0;
        int maxVowel = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) {
                count++;
            }
        }
        maxVowel = count;

        for (int i = k; i < n; i++) {
            if (vowels.count(s[i])) {
                count++;
            }
            if (vowels.count(s[i - k])) {
                count--;
            }
            maxVowel = max(maxVowel, count);
        }
        return maxVowel;
    }
};